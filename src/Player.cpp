#include "Player.h"


Player::Player(sf::Texture &texture, sf::Texture &projectile, sf::Vector2f pos)
	:GameObject(texture, pos)
{
	m_projectile_texture = projectile;
	m_attack_rate = 0.5;
	m_time_since_last_attack = 0;
}

void Player::Update(float dt)
{
	vel.x = m_input.isKeyHeld(Key::Right) * m_speed
		- m_input.isKeyHeld(Key::Left) * m_speed;

	vel.y = m_input.isKeyHeld(Key::Down) * m_speed
		- m_input.isKeyHeld(Key::Up) * m_speed;

	AdjustVelocity();

	m_time_since_last_attack += dt;

	if (m_time_since_last_attack >= m_attack_rate)
		Fire();

	m_projmgr.Update(dt);
}

std::vector<Projectile*> Player::GetProjectiles()
{
	return m_projmgr.GetProjectiles();
}

void Player::Draw(sf::RenderWindow &window, float dt)
{
	m_projmgr.Draw(window, dt);
	window.draw(m_sprite);
	if (m_healthbar.isVisible())
		m_healthbar.Draw(window);
}

void Player::Fire()
{
	if (m_input.isKeyHeld(Key::W))
		m_projmgr.Add(new Projectile(m_projectile_texture, GetPosition(), Direction::UP)), m_time_since_last_attack = 0;
	else if (m_input.isKeyHeld(Key::S))
		m_projmgr.Add(new Projectile(m_projectile_texture, GetPosition(), Direction::DOWN)), m_time_since_last_attack = 0;
	else if (m_input.isKeyHeld(Key::A))
		m_projmgr.Add(new Projectile(m_projectile_texture, GetPosition(), Direction::LEFT)), m_time_since_last_attack = 0;
	else if (m_input.isKeyHeld(Key::D))
		m_projmgr.Add(new Projectile(m_projectile_texture, GetPosition(), Direction::RIGHT)), m_time_since_last_attack = 0;
}