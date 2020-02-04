#pragma once
#include <SFML/Graphics.hpp>


class GameObject;

class HealthBar
{
	public:
		HealthBar() {}
		~HealthBar();

		HealthBar(GameObject *object);

		void Update();
		void Draw(sf::RenderWindow &window);

	private:
		sf::RectangleShape m_green, m_red;
		sf::Vector2f m_pos;
		sf::Vector2f m_size;
		GameObject *m_object;
};