#include "GameStatePlaying.h"
#include "Player.h"


GameStatePlaying::GameStatePlaying(Game *game)
{
	this->game = game;
	level1.Load(game->texmgr.GetRef("Level1"), "res/maps/Level1.txt");

	object_manager.Add("player", new Player(game->texmgr.GetRef("Player"), sf::Vector2f(400, 500)));
}

void GameStatePlaying::HandleInput()
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
		}
	}
}

void GameStatePlaying::Update(float dt)
{
	object_manager.Update(level1, dt);
}

void GameStatePlaying::Draw(float dt)
{
	game->window.draw(game->background);
	game->window.draw(level1);
	object_manager.Draw(game->window, dt);
}