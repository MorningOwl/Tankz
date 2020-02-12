#include "Game.h"
#include "GameStatePlaying.h"
#include "GameStateMainMenu.h"


Game::Game()
{
	window.create(sf::VideoMode(800, 600), "Tankz");
	window.setFramerateLimit(60);

	LoadTextures();
	background.setTexture(texmgr.GetRef("Background"));

	PushState(new GameStateMainMenu(this));
	PushState(new GameStatePlaying(this));
}

Game::~Game()
{
	while (!m_states.empty())
		PopState();
}

void Game::GameLoop()
{
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();
		if (PeekState() == nullptr) continue;
		PeekState()->HandleInput();
		PeekState()->Update(dt);
		window.clear(sf::Color::Black);
		PeekState()->Draw(dt);
		window.display();
	}
}

void Game::LoadTextures()
{
	texmgr.LoadTexture("Background", "res/images/Background.png");
	texmgr.LoadTexture("Player", "res/images/Player.png");
	texmgr.LoadTexture("Projectile", "res/images/Projectile.png");
	texmgr.LoadTexture("Enemy", "res/images/Enemy.png");
	texmgr.LoadTexture("Level1", "res/images/Level1.png");
}

void Game::PushState(GameState *state)
{
	m_states.push(state);
}

void Game::PopState()
{
	delete m_states.top();
	m_states.pop();
}

void Game::ChangeState(GameState *state)
{
	if (!m_states.empty())
		PopState();
	PushState(state);
}

GameState* Game::PeekState()
{
	if (m_states.empty()) return nullptr;
	return m_states.top();
}