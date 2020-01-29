#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include "TextureManager.h"


class GameState;

class Game
{
	public:
		Game();
		~Game();

		void GameLoop();
		void PushState(GameState *state);
		void PopState();
		void ChangeState(GameState *state);
		GameState* PeekState();

		void LoadTextures();

		sf::RenderWindow window;
		TextureManager texmgr;
		sf::Sprite background;

	private:
		std::stack<GameState*> m_states;
};