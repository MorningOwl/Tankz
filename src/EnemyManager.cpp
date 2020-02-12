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
	for (size_t i = 0; i < m_enemies.size(); i++)
		if (m_enemies[i] == enemy)
		{
			delete m_enemies[i];
			m_enemies.erase(m_enemies.begin() + i);
		}
}

void EnemyManager::Update(Level *map, Player *player, float dt)
{
	for (auto enemy : m_enemies)
	{
		enemy->Update(player, dt);
		map->CheckCollision(enemy);

		for (auto proj : map->GetProjectiles())
			if (proj->GetBounds().intersects(enemy->GetBounds()))
				enemy->ReduceHealth(proj->attack_power), proj->Kill();

		if (enemy->isDead())
		{
			Remove(enemy);
			return;
		}
	}
}

void EnemyManager::Draw(sf::RenderWindow &window, float dt)
{
	for (auto enemy : m_enemies)
		enemy->Draw(window, dt);
}