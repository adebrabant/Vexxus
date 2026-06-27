#pragma once

#include <filesystem>
#include <vector>
#include <cstddef>

namespace Cocoa::Assets
{
	class AssetSource
	{
	public:
		virtual ~AssetSource() = default;
		virtual std::vector<std::byte> ReadBytes(const std::filesystem::path& path) const = 0; 
		virtual bool Exists(const std::filesystem::path& path) const = 0;
	};
}