#pragma once

#include <cstdint>
#include <vector>
#include <filesystem>

namespace Cocoa::Assets
{
	struct Image;

	class AssetLoader
	{
	public:
		AssetLoader();
		~AssetLoader() = default;
		Image LoadImage(const std::filesystem::path& path) const;
		Image LoadImage(const std::vector<std::byte>& bytes) const;
		std::string LoadText(const std::filesystem::path& path) const;
		std::string LoadText(const std::vector<std::byte>& bytes) const;
	};
}