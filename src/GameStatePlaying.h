#pragma once
#include "GameState.h"
#include "TileMap.h"
#include "GameObjectManager.h"


class GameStatePlaying : public GameState
{
	public:
		GameStatePlaying(Game *game);

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		TileMap level1;
		GameObjectManager object_manager;
};