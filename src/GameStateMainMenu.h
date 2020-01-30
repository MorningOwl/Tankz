#pragma once
#include "GameState.h"
#include "Button.h"
#include <vector>


class GameStateMainMenu : public GameState
{
	public:
		GameStateMainMenu(Game *game);
		~GameStateMainMenu();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		std::vector<Button*> m_buttons;
};