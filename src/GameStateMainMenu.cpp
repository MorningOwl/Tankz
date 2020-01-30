#include "GameStateMainMenu.h"
#include "GameStatePlaying.h"


GameStateMainMenu::GameStateMainMenu(Game *game)
{
	this->game = game;

	m_buttons.push_back(new Button(ButtonAction::NEWGAME, sf::Vector2f(400, 200), sf::RectangleShape(sf::Vector2f(80, 20)), sf::Color(100, 100, 100), sf::Color::Cyan, sf::Color::Blue));
	m_buttons.push_back(new Button(ButtonAction::EXIT, sf::Vector2f(400, 250), sf::RectangleShape(sf::Vector2f(80, 20)), sf::Color(100, 100, 100), sf::Color::Cyan, sf::Color::Blue));
}

GameStateMainMenu::~GameStateMainMenu()
{
	for (auto button : m_buttons)
		delete button;
}

void GameStateMainMenu::HandleInput()
{
	sf::Event ev;

	while (game->window.pollEvent(ev))
	{
		switch (ev.type)
		{
			case sf::Event::Closed:
				game->window.close();
				break;

			case sf::Event::KeyPressed:
				switch (ev.key.code)
				{
					case sf::Keyboard::Escape:
						game->window.close();
						break;
				}
				break;

			case sf::Event::MouseButtonReleased:
				if (ev.mouseButton.button != sf::Mouse::Left)
					break;

				for (auto button : m_buttons)
				{
					if (button->GetBounds().contains(sf::Vector2f(sf::Mouse::getPosition(game->window))))
					{
						switch (button->GetAction())
						{
							case ButtonAction::NEWGAME:
								game->PushState(new GameStatePlaying(game));
								break;

							case ButtonAction::EXIT:
								game->window.close();
								break;
						}
					}
				}
				break;
		}
	}
}

void GameStateMainMenu::Update(float dt)
{
	for (auto button : m_buttons)
		button->Update(sf::Mouse::getPosition(game->window));
}

void GameStateMainMenu::Draw(float dt)
{
	game->window.draw(game->background);
	for (auto button : m_buttons)
		button->Draw(game->window);
}