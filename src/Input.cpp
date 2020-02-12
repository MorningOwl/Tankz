#include "Input.h"


bool Input::isKeyHeld(Key key)
{
	switch (key)
	{
		case Key::Left: return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		case Key::Right: return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
		case Key::Up: return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
		case Key::Down: return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
		case Key::W: return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		case Key::S: return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		case Key::A: return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		case Key::D: return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	}
}