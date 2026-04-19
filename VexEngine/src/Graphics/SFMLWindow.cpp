#include "Graphics/SFMLWindow.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <string>
#include <stdexcept>

namespace VexEngine::Graphics
{
	SFMLWindow::SFMLWindow(unsigned int width, unsigned int height, const std::string& title) :
		m_window(nullptr),
		m_width(width),
		m_height(height),
		m_title(title),
		m_isOpen(false)
	{

	}

	SFMLWindow::~SFMLWindow()
	{
		Close();
	}

	void SFMLWindow::Open()
	{
		if (m_isOpen)
			return;

		m_window = std::make_unique<sf::RenderWindow>(
			sf::VideoMode({ m_width, m_height }),
			m_title,
			sf::Style::Titlebar | sf::Style::Close);

		m_isOpen = true;
	}

	bool SFMLWindow::IsOpen() 
	{
		Validation();
		// Todo: Remove for Event Bus
		while (const std::optional event = m_window->pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				Close();
		}

		return m_window->isOpen();
	}

	void SFMLWindow::Close()
	{
		if (m_window && m_window->isOpen())
		{
			m_window->close();
			m_isOpen = false;
		}
	}

	unsigned int SFMLWindow::GetWidth() const
	{
		return m_window->getSize().x;
	}

	unsigned int SFMLWindow::GetHeight() const
	{
		return m_window->getSize().y;
	}

	sf::RenderWindow* SFMLWindow::GetRenderWindow()
	{
		Validation();
		return m_window.get();
	}

	void SFMLWindow::Validation()
	{
		if (!m_window)
		{
			throw std::runtime_error(
				"SFMLWindow: Window not created. Call Open() before using the window.");
		}
	}
}