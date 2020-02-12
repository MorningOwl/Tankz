#pragma once
#include "GameObject.h"
#include "ProjectileManager.h"


class Player : public GameObject
{
	public:
		Player() {}
		Player(sf::Texture &texture, sf::Texture &projectile, sf::Vector2f pos);

		virtual void Update(float dt) override;
		virtual void Draw(sf::RenderWindow &window, float dt) override;

	private:
		void Fire();

		ProjectileManager m_projmgr;
		sf::Texture m_projectile_texture;
};