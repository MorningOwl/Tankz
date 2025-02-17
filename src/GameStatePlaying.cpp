#include "GameStatePlaying.h"
#include "Player.h"


GameStatePlaying::GameStatePlaying(Game *game)
{
	this->game = game;
	level1.Init(game);
	level1.Load(game->texmgr.GetRef("Level1"), "res/maps/Level1.txt");
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
						//game->PopState();
						game->window.close();
						return;

					case sf::Keyboard::F1:
						game->ChangeState(new GameStatePlaying(game));
						return;
				}
				break;
		}
	}
}

void GameStatePlaying::Update(float dt)
{
	object_manager.Update(level1, dt);
	level1.Update(dt);
}

void GameStatePlaying::Draw(float dt)
{
	game->window.draw(level1);
	object_manager.Draw(game->window, dt);
	level1.Draw(game->window, dt);
}