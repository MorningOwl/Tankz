#include "Player.h"


Player::Player(sf::Texture &texture, sf::Vector2f pos)
	:GameObject(texture, pos)
{

}

void Player::Update(float dt)
{
	m_vel.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) * m_speed
		- sf::Keyboard::isKeyPressed(sf::Keyboard::Left) * m_speed;

	m_vel.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) * m_speed
		- sf::Keyboard::isKeyPressed(sf::Keyboard::Up) * m_speed;

	Move();
}