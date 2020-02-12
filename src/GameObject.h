#pragma once
#include <SFML/Graphics.hpp>
#include "HealthBar.h"


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
		float GetHealthRatio();

		void ReduceHealth(int amount);

		sf::Vector2f vel;
		bool isDead;

	protected:
		float m_speed;
		sf::Sprite m_sprite;
		HealthBar m_healthbar;
		int m_health, m_max_health, m_attack_power, m_defense;
		float m_attack_rate, m_time_since_last_attack;
};