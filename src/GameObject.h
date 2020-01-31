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
		sf::Vector2f GetPosition();
		sf::Vector2f GetVelocity();
		float GetDistanceFrom(sf::Vector2f objectPos);

		sf::Vector2f vel;

	protected:
		float m_speed;
		sf::Sprite m_sprite;
};