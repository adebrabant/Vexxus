#include "Inputs/InputHandler.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace VexEngine::Inputs
{
	void InputHandler::Update()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			Up = true;
		else
			Up = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			Down = true;
		else
			Down = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			Left = true;
		else
			Left = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			Right = true;
		else
			Right = false;
	}
}