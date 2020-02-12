#pragma once
#include "Projectile.h"
#include <vector>


class ProjectileManager
{
	public:
		public:
			~ProjectileManager();

			void Add(Projectile *projectile);
			void Remove(Projectile *projectile);

			void Update(float dt);
			void Draw(sf::RenderWindow &window, float dt);

	private:
		std::vector<Projectile*> m_projectiles;
};