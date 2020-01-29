#pragma once
#include <SFML/Graphics.hpp>


class GameObject
{
	public:
		GameObject() {}
		GameObject(sf::Texture &texture, sf::Vector2f pos);

		virtual void Update(float dt) {}
		virtual void Draw(sf::RenderWindow &window, float dt);
		void Move();

		sf::FloatRect GetBounds();
		sf::Vector2f GetVelocity();

		sf::Vector2f m_vel;
		float m_speed;
		sf::Sprite m_sprite;
};