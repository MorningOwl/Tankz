#include "GameObject.h"


GameObject::GameObject(sf::Texture &texture, sf::Vector2f pos)
{
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	m_speed = 5;
	m_sprite.setPosition(pos);
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

void GameObject::Move()
{
	m_sprite.move(vel);
}

void GameObject::Draw(sf::RenderWindow &window, float dt)
{
	window.draw(m_sprite);
}