#pragma once
#include "GameState.h"
#include "Level.h"
#include "GameObjectManager.h"


class GameStatePlaying : public GameState
{
	public:
		GameStatePlaying(Game *game);

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		Level level1;
		GameObjectManager object_manager;
};