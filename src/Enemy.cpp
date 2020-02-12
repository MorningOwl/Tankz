#include "Enemy.h"
#include <cmath>


Enemy::Enemy(sf::Texture &texture, sf::Vector2f pos)
	:GameObject(texture, pos), m_spawn_point(pos), m_target(nullptr), m_state(EnemyState::IDLE)
{
	m_speed = 3;
	m_sight_range = 100;
	m_sight.setRadius(m_sight_range);
	m_sight.setPosition(pos);
	m_attack_rate = 1;
	m_time_since_last_attack = 0;
}

Enemy::~Enemy()
{
	m_target = nullptr;
}

void Enemy::Update(float dt)
{

}

void Enemy::Update(Player *player, float dt)
{
	vel = sf::Vector2f(0, 0);

	switch (m_state)
	{
		case EnemyState::IDLE:
			CheckForTarget(player);
			break;

		case EnemyState::FOLLOWING:
			if (GetDistanceFrom(m_target->GetPosition()) <= m_sight_range)
				GoTo(m_target);
			else
			{
				m_target = nullptr, m_state = EnemyState::GOINGHOME;
				break;
			}

			if (isAt(m_target))
				Attack(m_target, dt);
			break;

		case EnemyState::GOINGHOME:
			GoTo(m_spawn_point);
			if (isAt(m_spawn_point))
				m_state = EnemyState::IDLE;
			CheckForTarget(player);
			break;
	}
}

bool Enemy::isAt(GameObject *object)
{
	sf::FloatRect rect1 = GetBounds();
	sf::FloatRect rect2 = object->GetBounds();

	if (rect1.top - 3 < rect2.top + rect2.height + 3 && rect1.top + rect1.height + 3 > rect2.top - 3)
		return (rect1.left - 3 < rect2.left + rect2.width + 3 && rect1.left > rect2.left) || (rect1.left + rect1.width + 3 > rect2.left - 3 && rect1.left < rect2.left);

	if (rect1.left - 3 < rect2.left + rect2.width + 3 && rect1.left + rect1.width + 3 > rect2.left - 3)
		return (rect1.top - 3 < rect2.top + rect2.height + 3 && rect1.top > rect2.top) || (rect1.top + rect1.height + 3 > rect2.top - 3 && rect1.top < rect2.top);

	return false;
}

bool Enemy::isAt(sf::Vector2f pos)
{
	return GetDistanceFrom(pos) == 0;
}

void Enemy::GoTo(sf::Vector2f destination)
{
	sf::Vector2f pos1 = GetPosition();
	sf::Vector2f pos2 = destination;


	if (pos1.x < pos2.x)
	{
		if (pos1.x + m_speed > pos2.x) vel.x = pos2.x - pos1.x;
		else vel.x = m_speed;
	}

	else if (pos1.x > pos2.x)
	{
		if (pos1.x - m_speed < pos2.x) vel.x = pos2.x - pos1.x;
		else vel.x = -m_speed;
	}

	if (pos1.y < pos2.y)
	{
		if (pos1.y + m_speed > pos2.y) vel.y = pos2.y - pos1.y;
		else vel.y = m_speed;
	}

	else if (pos1.y > pos2.y)
	{
		if (pos1.y - m_speed < pos2.y) vel.y = pos2.y - pos1.y;
		else vel.y = -m_speed;
	}

	AdjustVelocity();
}

void Enemy::GoTo(GameObject *object)
{
	sf::FloatRect rect1 = GetBounds();
	sf::FloatRect rect2 = object->GetBounds();


	if (rect1.left + rect1.width + 2 < rect2.left - 2)
	{
		if (rect1.left + rect1.width + 2 + m_speed > rect2.left - 2) vel.x = (rect2.left - 2) - (rect1.left + rect1.width + 2);
		else vel.x = m_speed;
	}

	else if (rect1.left - 2 > rect2.left + rect2.width + 2)
	{
		if (rect1.left - 2 - m_speed < rect2.left + rect2.width + 2) vel.x = (rect2.left + rect2.width + 2) - (rect1.left - 2);
		else vel.x = -m_speed;
	}

	if (rect1.top + rect1.height + 2 < rect2.top - 2)
	{
		if (rect1.top + rect1.height + 2 + m_speed > rect2.top - 2) vel.y = (rect2.top - 2) - (rect1.top + rect1.height + 2);
		else vel.y = m_speed;
	}

	else if (rect1.top - 2 > rect2.top + rect2.height + 2)
	{
		if (rect1.top - 2 - m_speed < rect2.top + rect2.height + 2) vel.y = (rect2.top + rect2.height + 2) - (rect1.top - 2);
		else vel.y = -m_speed;
	}

	AdjustVelocity();
}

void Enemy::CheckForTarget(Player *player)
{
	if (GetDistanceFrom(player->GetPosition()) < m_sight_range)
		m_target = player, m_state = EnemyState::FOLLOWING;
}

void Enemy::Attack(GameObject *object, float dt)
{
	m_time_since_last_attack += dt;

	if (m_time_since_last_attack >= m_attack_rate)
	{
		object->ReduceHealth(attack_power);
		if (object->isDead())
		{
			m_target = nullptr;
			m_state = EnemyState::GOINGHOME;
		}

		m_time_since_last_attack = 0;
	}
}