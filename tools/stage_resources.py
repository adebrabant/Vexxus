# tools/stage_resources.py

from __future__ import annotations

import argparse
import json
import shutil
import sys
from pathlib import Path


METADATA_DIR_NAME = "metadata"


def fail(message: str) -> None:
    print(f"[stage_resources] ERROR: {message}", file=sys.stderr)
    sys.exit(1)


def load_json(path: Path) -> dict:
    try:
        with path.open("r", encoding="utf-8") as file:
            data = json.load(file)
    except json.JSONDecodeError as error:
        fail(f"Invalid JSON in '{path}': {error}")
    except OSError as error:
        fail(f"Could not read '{path}': {error}")

    if not isinstance(data, dict):
        fail(f"Metadata file '{path}' must contain a JSON object at the root.")

    return data


def merge_metadata(resource_roots: list[Path], output_root: Path) -> None:
    merged_by_file: dict[str, dict] = {}

    for resource_root in resource_roots:
        metadata_root = resource_root / METADATA_DIR_NAME

        if not metadata_root.exists():
            continue

        for metadata_file in metadata_root.glob("*.json"):
            metadata_name = metadata_file.name
            metadata = load_json(metadata_file)

            if metadata_name not in merged_by_file:
                merged_by_file[metadata_name] = {}

            destination_metadata = merged_by_file[metadata_name]

            for asset_id, asset_record in metadata.items():
                if asset_id in destination_metadata:
                    fail(
                        "Duplicate asset id "
                        f"'{asset_id}' found while merging '{metadata_name}'. "
                        f"Duplicate came from '{metadata_file}'."
                    )

                destination_metadata[asset_id] = asset_record

    output_metadata_root = output_root / METADATA_DIR_NAME
    output_metadata_root.mkdir(parents=True, exist_ok=True)

    for metadata_name, merged_metadata in merged_by_file.items():
        output_file = output_metadata_root / metadata_name

        with output_file.open("w", encoding="utf-8") as file:
            json.dump(merged_metadata, file, indent=2)
            file.write("\n")


def copy_resource_files(resource_roots: list[Path], output_root: Path) -> None:
    copied_paths: dict[Path, Path] = {}

    for resource_root in resource_roots:
        if not resource_root.exists():
            print(f"[stage_resources] Skipping missing resource root: {resource_root}")
            continue

        for source_path in resource_root.rglob("*"):
            if not source_path.is_file():
                continue

            relative_path = source_path.relative_to(resource_root)

            # Metadata is merged separately.
            if relative_path.parts[0] == METADATA_DIR_NAME:
                continue

            output_path = output_root / relative_path

            if relative_path in copied_paths:
                fail(
                    "Duplicate resource file path "
                    f"'{relative_path}' found.\n"
                    f"First:  {copied_paths[relative_path]}\n"
                    f"Second: {source_path}"
                )

            copied_paths[relative_path] = source_path

            output_path.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(source_path, output_path)


def stage_resources(resource_roots: list[Path], output_root: Path) -> None:
    if output_root.exists():
        shutil.rmtree(output_root)

    output_root.mkdir(parents=True, exist_ok=True)

    copy_resource_files(resource_roots, output_root)
    merge_metadata(resource_roots, output_root)


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Stage Cocoa runtime resources."
    )

    parser.add_argument(
        "--input",
        action="append",
        required=True,
        help="Resource root to stage. Can be passed multiple times."
    )

    parser.add_argument(
        "--output",
        required=True,
        help="Output resources directory."
    )

    args = parser.parse_args()

    resource_roots = [Path(path).resolve() for path in args.input]
    output_root = Path(args.output).resolve()

    stage_resources(resource_roots, output_root)

    print(f"[stage_resources] Staged resources to: {output_root}")


if __name__ == "__main__":
    main()