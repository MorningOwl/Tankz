#pragma once
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include <SFML/Graphics.hpp>


class Level;

class EnemyManager
{
	public:
		~EnemyManager();

		void Add(Enemy *enemy);
		void Remove(Enemy *enemy);

		void Update(Level *map, GameObject *player, float dt) const;
		void Draw(sf::RenderWindow &window, float dt);

	private:
		std::vector<Enemy*> m_enemies;
};