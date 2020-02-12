#pragma once
#include <SFML/Graphics.hpp>


class GameObject;

class HealthBar
{
	public:
		HealthBar() {}
		~HealthBar();

		HealthBar(GameObject *object, bool isVisible = false);
		void SetVisible(bool flag);
		bool isVisible();

		void Update();
		void Draw(sf::RenderWindow &window);

	private:
		sf::RectangleShape m_green, m_red;
		sf::Vector2f m_pos;
		sf::Vector2f m_size;
		GameObject *m_object;
		bool m_isVisible;
};