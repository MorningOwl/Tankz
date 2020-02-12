#include "Projectile.h"


Projectile::Projectile(sf::Texture &texture, sf::Vector2f pos, Direction dir)
	:GameObject(texture, pos)
{
	m_speed = 7;
	m_lifetime = 0.5;
	m_duration = 0;
	attack_power = 10;

	switch (dir)
	{
		case Direction::UP: vel.y = -m_speed; break;
		case Direction::DOWN: vel.y = m_speed; break;
		case Direction::LEFT: vel.x = -m_speed; break;
		case Direction::RIGHT: vel.x = m_speed; break;
	}
}

void Projectile::Update(float dt)
{
	m_duration += dt;
	if (m_duration >= m_lifetime)
		m_health = 0;
	Move();
}