#include <Assets/AssetManager.hpp>
#include <Assets/ShaderSource.hpp>
#include <Assets/Image.hpp>

#include <gtest/gtest.h>
#include <filesystem>
#include <string>

namespace Cocoa::Assets::Tests
{
	TEST(AssetManagerTests, LoadImage_ShouldReturnImage_WhenProvidingPath)
	{
		const std::filesystem::path rootPath = "TestData/Resources";
		AssetManager sut(rootPath);

		const Image& result = sut.LoadImage("Images/test.png");

		EXPECT_NE(&result, nullptr);
	}

	TEST(AssetManagerTests, LoadImage_ShouldReturnSameImage_WhenProvidingSameImagePath)
	{
		const std::filesystem::path rootPath = "TestData/Resources";
		AssetManager sut(rootPath);

		const Image& result1 = sut.LoadImage("Images/test.png");
		const Image& result2 = sut.LoadImage("Images/test.png");

		EXPECT_EQ(&result1, &result2);
	}

	TEST(AssetManagerTests, LoadImage_ShouldReturnDifferentImage_WhenProvidingDifferentImagePath)
	{
		const std::filesystem::path rootPath = "TestData/Resources";
		AssetManager sut(rootPath);

		const Image& result1 = sut.LoadImage("Images/test.png");
		const Image& result2 = sut.LoadImage("Images/test2.png");

		EXPECT_NE(&result1, &result2);
	}

	TEST(AssetManagerTests, LoadShader_ShouldReturnShaderSource_WhenProvidingPaths)
	{
		const std::string shaderId = "test-id";
		const std::string vertexPath = "Texts/sample.txt";
		const std::string fragmentPath = "Texts/sample2.txt";
		const std::filesystem::path rootPath = "TestData/Resources";
		AssetManager sut(rootPath);

		const ShaderSource& result = sut.LoadShader(shaderId, vertexPath, fragmentPath);

		EXPECT_NE(&result, nullptr);
	}

	TEST(AssetManagerTests, LoadShader_ShouldReturnSameShaderSource_WhenProvidingSameShaderId)
	{
		const std::string shaderId = "test-id";
		const std::string vertexPath = "Texts/sample.txt";
		const std::string fragmentPath = "Texts/sample2.txt";
		const std::filesystem::path rootPath = "TestData/Resources";
		AssetManager sut(rootPath);

		const ShaderSource& result1 = sut.LoadShader(shaderId, vertexPath, fragmentPath);
		const ShaderSource& result2 = sut.LoadShader(shaderId, vertexPath, fragmentPath);

		EXPECT_EQ(&result1, &result2);
	}

	TEST(AssetManagerTests, LoadShader_ShouldReturnDifferentShaderSource_WhenProvidingDifferentShaderId)
	{
		const std::string vertexPath = "Texts/sample.txt";
		const std::string fragmentPath = "Texts/sample2.txt";
		const std::filesystem::path rootPath = "TestData/Resources";
		AssetManager sut(rootPath);

		const ShaderSource& result1 = sut.LoadShader("test-id", vertexPath, fragmentPath);
		const ShaderSource& result2 = sut.LoadShader("some-id", vertexPath, fragmentPath);

		EXPECT_NE(&result1, &result2);
	}
}