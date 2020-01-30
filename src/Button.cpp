#include "Button.h"


Button::Button(ButtonAction action, sf::Vector2f pos, sf::RectangleShape shape, sf::Color idle, sf::Color hover, sf::Color active)
	:m_rect(shape), m_action(action)
{
	m_rect.setOrigin(m_rect.getGlobalBounds().width / 2, m_rect.getGlobalBounds().height / 2);
	m_rect.setPosition(pos);
	m_colours.push_back(idle);
	m_colours.push_back(hover);
	m_colours.push_back(active);
}

void Button::Update(sf::Vector2i mousepos)
{
	m_state = ButtonState::IDLE;
	if (m_rect.getGlobalBounds().contains(sf::Vector2f(mousepos)))
	{
		m_state = ButtonState::HOVER;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				m_state = ButtonState::ACTIVE;
	}

	m_rect.setFillColor(m_colours[(int)m_state]);
}

void Button::Draw(sf::RenderWindow &window)
{
	window.draw(m_rect);
}

sf::FloatRect Button::GetBounds()
{
	return m_rect.getGlobalBounds();
}

ButtonAction Button::GetAction()
{
	return m_action;
}