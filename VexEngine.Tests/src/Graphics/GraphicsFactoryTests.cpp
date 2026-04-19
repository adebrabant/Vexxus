#include "Graphics/GraphicsFactory.hpp"
#include <gtest/gtest.h>

namespace VexEngine::Tests
{
	TEST(GraphicsFactoryTests, CreateWindow_ShouldReturnValidWindow)
	{
		Graphics::GraphicsFactory factory;

		auto window = factory.CreateWindow(800, 600, "Test Window");

		EXPECT_NE(window, nullptr);
	}

	TEST(GraphicsFactoryTests, CreateRenderer_ShouldReturnValidRenderer)
	{
		Graphics::GraphicsFactory factory;

		auto window = factory.CreateWindow(800, 600, "Test Window");
		auto renderer = factory.CreateRenderer(*window);

		EXPECT_NE(renderer, nullptr);
	}
}