#pragma once
#include "GameState.h"


class GameStatePlaying : public GameState
{
	public:
		GameStatePlaying(Game *game);

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
};