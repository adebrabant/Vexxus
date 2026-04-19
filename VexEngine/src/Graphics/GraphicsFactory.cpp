#include "Graphics/GraphicsFactory.hpp"
#include "Graphics/SFMLWindow.hpp"
#include "Graphics/SFMLRenderer.hpp"
#include <Graphics/IRenderer.hpp>
#include <Graphics/IWindow.hpp>
#include <memory>
#include <string>

namespace VexEngine::Graphics
{
	std::unique_ptr<IWindow> GraphicsFactory::CreateWindow(unsigned int width, unsigned int height, const std::string& title)
	{
		return std::make_unique<SFMLWindow>(width, height, title);
	}

	std::unique_ptr<IRenderer> GraphicsFactory::CreateRenderer(IWindow& window)
	{
		return std::make_unique<SFMLRenderer>(static_cast<SFMLWindow&>(window));
	}
}