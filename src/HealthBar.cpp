#include "HealthBar.h"
#include "GameObject.h"


HealthBar::HealthBar(GameObject *object, bool isVisible)
	:m_object(object), m_isVisible(isVisible)
{
	m_size = sf::Vector2f(20, 3);
	m_green = sf::RectangleShape(m_size);
	m_green.setFillColor(sf::Color::Green);
	m_red = sf::RectangleShape(m_size);
	m_red.setFillColor(sf::Color::Red);

	Update();
}

HealthBar::~HealthBar()
{
	m_object = nullptr;
}

void HealthBar::Update()
{
	sf::FloatRect object_rect = m_object->GetBounds();
	sf::Vector2f object_pos = m_object->GetPosition();

	m_pos = sf::Vector2f(object_pos.x - m_red.getGlobalBounds().width / 2, object_pos.y - object_rect.height);
	m_green.setPosition(m_pos);
	m_red.setPosition(m_pos);

	m_green.setSize(sf::Vector2f(m_object->GetHealthRatio() * 20, m_size.y));

	if (m_object->GetHealthRatio() != 1)
		SetVisible(true);
	else
		SetVisible(false);
}

void HealthBar::Draw(sf::RenderWindow &window)
{
	window.draw(m_red);
	window.draw(m_green);
}

void HealthBar::SetVisible(bool flag)
{
	m_isVisible = flag;
}

bool HealthBar::isVisible()
{
	return m_isVisible;
}