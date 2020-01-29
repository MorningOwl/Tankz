#pragma once
#include "GameState.h"
#include "TileMap.h"


class GameStatePlaying : public GameState
{
	public:
		GameStatePlaying(Game *game);

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		TileMap level1;
};