#pragma once
#include "GameObject.h"


class Player : public GameObject
{
	public:
		Player() {}
		Player(sf::Texture &texture, sf::Vector2f pos);

		virtual void Update(float dt) override;
};