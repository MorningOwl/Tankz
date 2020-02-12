#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"


enum class Direction { UP, DOWN, LEFT, RIGHT };

class Projectile : public GameObject
{
	public:
		Projectile() {}
		Projectile(sf::Texture &texture, sf::Vector2f pos, Direction dir);

		virtual void Update(float dt) override;

		bool IsDead();

	private:
		float m_lifetime, m_duration;
};