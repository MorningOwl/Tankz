#pragma once
#include "Enemy.h"
#include <vector>
#include <SFML/Graphics.hpp>


class Level;

class EnemyManager
{
	public:
		~EnemyManager();

		void Add(Enemy *enemy);
		void Remove(Enemy *enemy);

		void Update(Level *map, Player *player, float dt);
		void Draw(sf::RenderWindow &window, float dt);

	private:
		std::vector<Enemy*> m_enemies;
};