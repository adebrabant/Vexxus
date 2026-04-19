#pragma once

#include "Graphics/IWindow.hpp"
#include <string>
#include <memory>

namespace sf
{
	class RenderWindow;
}

namespace VexEngine::Graphics
{
	class SFMLWindow : public IWindow
	{
	public:
		SFMLWindow(unsigned int width, unsigned int height, const std::string& title);
		~SFMLWindow() override;
		void Open() override;
		bool IsOpen() override;
		void Close() override;
		unsigned int GetWidth() const override;
		unsigned int GetHeight() const override;
		sf::RenderWindow* GetRenderWindow();

	private:
		void Validation();

	private:
		std::unique_ptr<sf::RenderWindow> m_window;
		unsigned int m_width;
		unsigned int m_height;
		std::string m_title;
		bool m_isOpen;
	};
}