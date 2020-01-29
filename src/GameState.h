#pragma once
#include "Game.h"


class GameState
{
	public:
		Game *game;

		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw(float dt) = 0;
};