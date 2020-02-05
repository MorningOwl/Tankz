#include "EnemyManager.h"
#include "Level.h"


EnemyManager::~EnemyManager()
{
	for (auto enemy : m_enemies)
		delete enemy;
}

void EnemyManager::Add(Enemy *enemy)
{
	m_enemies.push_back(enemy);
}

void EnemyManager::Remove(Enemy *enemy)
{
	delete enemy;
}

void EnemyManager::Update(Level *map, std::vector<GameObject*> objects, float dt) const
{
	for (auto enemy : m_enemies)
	{
		enemy->Update(objects, dt);
		map->CheckCollision(enemy);
	}
}

void EnemyManager::Draw(sf::RenderWindow &window, float dt)
{
	for (auto enemy : m_enemies)
		enemy->Draw(window, dt);
}