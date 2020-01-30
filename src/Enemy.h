#pragma once
#include "GameObject.h"


class Enemy : public GameObject
{
	public:
		Enemy() {}
		Enemy(sf::Texture &texture, sf::Vector2f pos);

		virtual void Update(float dt) override;
};