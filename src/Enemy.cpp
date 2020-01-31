#include "Enemy.h"
#include <cmath>


Enemy::Enemy(sf::Texture &texture, sf::Vector2f pos)
	:GameObject(texture, pos), m_spawn_point(pos), m_target(nullptr), m_state(EnemyState::IDLE)
{
	m_speed = 3;
	m_sight_range = 100;
	m_sight.setRadius(m_sight_range);
	m_sight.setPosition(pos);
}

Enemy::~Enemy()
{
	m_target = nullptr;
}

void Enemy::Update(float dt)
{

}

void Enemy::Update(GameObject *object, float dt)
{
	vel = sf::Vector2f(0, 0);

	switch (m_state)
	{
		case EnemyState::IDLE:
			CheckForTarget(object);
			break;

		case EnemyState::FOLLOWING:
			if (GetDistanceFrom(m_target->GetPosition()) < m_sight_range)
				GoTo(m_target->GetPosition());
			else
				m_target = nullptr, m_state = EnemyState::GOINGHOME;
			break;

		case EnemyState::GOINGHOME:
			GoTo(m_spawn_point);
			if (GetDistanceFrom(m_spawn_point) < 10)
				m_state = EnemyState::IDLE;
			CheckForTarget(object);
			break;
	}
}

void Enemy::GoTo(sf::Vector2f pos)
{
	sf::Vector2f pos1 = GetPosition();
	sf::Vector2f pos2 = pos;

	if (pos1.x < pos2.x - m_speed) vel.x = m_speed;
	else if (pos1.x > pos2.x + m_speed) vel.x = -m_speed;
	if (pos1.y < pos2.y - m_speed) vel.y = m_speed;
	else if (pos1.y > pos2.y + m_speed) vel.y = -m_speed;
}

void Enemy::CheckForTarget(GameObject *object)
{
	if (GetDistanceFrom(object->GetPosition()) < m_sight_range)
		m_target = object, m_state = EnemyState::FOLLOWING;
}