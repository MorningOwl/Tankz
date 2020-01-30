#pragma once
#include <SFML/Graphics.hpp>
#include <vector>


enum class ButtonState { IDLE, HOVER, ACTIVE };
enum class ButtonAction { NEWGAME, EXIT };

class Button
{
	public:
		Button() {}
		Button(ButtonAction action, sf::Vector2f pos, sf::RectangleShape shape, sf::Color idle, sf::Color hover, sf::Color active);

		void Update(sf::Vector2i mousepos);
		void Draw(sf::RenderWindow &window);

		sf::FloatRect GetBounds();
		ButtonAction GetAction();

	private:
		ButtonState m_state;
		ButtonAction m_action;
		sf::RectangleShape m_rect;
		sf::Vector2f m_pos;
		std::vector<sf::Color> m_colours;
};