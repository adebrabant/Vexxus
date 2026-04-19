#include "Graphics/SFMLRenderer.hpp"
#include "Graphics/SFMLWindow.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

namespace VexEngine::Graphics
{
	SFMLRenderer::SFMLRenderer(SFMLWindow& sfmlWindow)
		: m_sfmlWindow(sfmlWindow)
	{

	}

	SFMLRenderer::~SFMLRenderer()
	{

	}

	void SFMLRenderer::Clear()
	{
		m_sfmlWindow.GetRenderWindow()->clear(sf::Color::Black);
	}

	void SFMLRenderer::DrawSprite(/*sprite params*/)
	{
		// ToDo: add me
	}

	void SFMLRenderer::Display()
	{
		m_sfmlWindow.GetRenderWindow()->display();
	}
}