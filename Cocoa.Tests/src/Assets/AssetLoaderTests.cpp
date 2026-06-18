#include <Assets/AssetLoader.hpp>
#include <Assets/Image.hpp>

#include <gtest/gtest.h>

#include <filesystem>
#include <stdexcept>
#include <string>

namespace Cocoa::Assets::Tests
{
    TEST(AssetLoaderTests, LoadTextFile_ShouldReturnContents_WhenFileExists)
    {
        AssetLoader sut;
        const std::filesystem::path path =
            "TestData/Resources/Texts/sample.txt";

        const std::string result = sut.LoadTextFile(path);

        EXPECT_EQ(result, "Hello from AssetLoader test.");
    }

    TEST(AssetLoaderTests, LoadTextFile_ShouldThrowError_WhenFileDoesNotExist)
    {
        AssetLoader sut;
        const std::filesystem::path path =
            "TestData/Resources/Texts/missing.txt";

        EXPECT_THROW(
            {
                sut.LoadTextFile(path);
            },
            std::runtime_error
        );
    }

    TEST(AssetLoaderTests, Load_ShouldReturnImage_WhenFileExists)
    {
        AssetLoader sut;
        const std::filesystem::path path =
            "TestData/Resources/Images/test.png";

        const Image result = sut.Load(path);

        EXPECT_GT(result.Width, 0);
        EXPECT_GT(result.Height, 0);
        EXPECT_EQ(result.Channels, 4);
        EXPECT_FALSE(result.Pixels.empty());
    }

    TEST(AssetLoaderTests, Load_ShouldReturnEmptyImage_WhenFileDoesNotExist)
    {
        AssetLoader sut;
        const std::filesystem::path path =
            "TestData/Resources/Images/missing.png";

        const Image result = sut.Load(path);

        EXPECT_EQ(result.Width, 0);
        EXPECT_EQ(result.Height, 0);
        EXPECT_EQ(result.Channels, 4);
        EXPECT_TRUE(result.Pixels.empty());
    }

    TEST(AssetLoaderTests, Load_ShouldSetPixelSize_WhenFileExists)
    {
        AssetLoader sut;
        const std::filesystem::path path =
            "TestData/Resources/Images/test.png";

        const Image result = sut.Load(path);

        const size_t expectedSize =
            static_cast<size_t>(result.Width) *
            static_cast<size_t>(result.Height) *
            4;

        EXPECT_EQ(result.Pixels.size(), expectedSize);
    }

    TEST(AssetLoaderTests, Load_ShouldForceFourChannels_WhenLoadingImage)
    {
        AssetLoader sut;
        const std::filesystem::path path =
            "TestData/Resources/Images/test.png";

        const Image result = sut.Load(path);

        EXPECT_EQ(result.Channels, 4);
    }
}