#pragma once
#include "Graphics/IWindow.hpp"
#include "Graphics/IRenderer.hpp"
#include <memory>
#include <string>

namespace VexEngine::Graphics
{
	class GraphicsFactory
	{
	public:
		std::unique_ptr<IWindow> CreateWindow(unsigned int width, unsigned int height, const std::string& title);
		std::unique_ptr<IRenderer> CreateRenderer(IWindow& window);
	};
}