#include "ProjectileManager.h"


ProjectileManager::~ProjectileManager()
{
	for (auto projectile : m_projectiles)
		delete projectile;
}

void ProjectileManager::Add(Projectile *projectile)
{
	m_projectiles.push_back(projectile);
}

void ProjectileManager::Remove(Projectile *projectile)
{
	for (size_t i = 0; i < m_projectiles.size(); i++)
		if (m_projectiles[i] == projectile)
		{
			delete m_projectiles[i];
			m_projectiles.erase(m_projectiles.begin() + i);
		}
}

void ProjectileManager::Update(float dt)
{
	for (auto projectile : m_projectiles)
	{
		projectile->Update(dt);
		if (projectile->isDead)
		{
			Remove(projectile);
			break;
		}
	}
}

void ProjectileManager::Draw(sf::RenderWindow &window, float dt)
{
	for (auto projectile : m_projectiles)
		projectile->Draw(window, dt);
}