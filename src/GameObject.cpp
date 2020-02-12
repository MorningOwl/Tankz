#include "GameObject.h"


GameObject::GameObject(sf::Texture &texture, sf::Vector2f pos)
{
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	m_speed = 5;
	m_sprite.setPosition(pos);
	m_health = 20, m_max_health = 20;
	attack_power = 4, m_defense = 2;
	m_healthbar = HealthBar(this);
}

sf::FloatRect GameObject::GetBounds()
{
	return m_sprite.getGlobalBounds();
}

sf::Vector2f GameObject::GetPosition()
{
	return m_sprite.getPosition();
}

sf::Vector2f GameObject::GetVelocity()
{
	return vel;
}

float GameObject::GetDistanceFrom(sf::Vector2f objectPos)
{
	sf::Vector2f pos1 = GetPosition();
	sf::Vector2f pos2 = objectPos;
	return sqrt((pos2.x - pos1.x) * (pos2.x - pos1.x) + (pos2.y - pos1.y) * (pos2.y - pos1.y));
}

float GameObject::GetHealthRatio()
{
	return m_health * 1.0 / m_max_health;
}

bool GameObject::isDead()
{
	return m_health <= 0;
}

void GameObject::Kill()
{
	m_health = 0;
}

void GameObject::ReduceHealth(int amount)
{
	m_health -= amount;
}

void GameObject::AdjustVelocity()
{
	if (vel.x != 0 && vel.y != 0)
		vel.x *= 0.75, vel.y *= 0.75;
}

void GameObject::Move()
{
	m_sprite.move(vel);
	m_healthbar.Update();
}

void GameObject::Draw(sf::RenderWindow &window, float dt)
{
	window.draw(m_sprite);
	if (m_healthbar.isVisible())
		m_healthbar.Draw(window);
}