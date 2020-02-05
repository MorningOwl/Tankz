#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyManager.h"
#include "Game.h"


class Level : public sf::Drawable, public sf::Transformable
{
	public:
		Level() {}
		Level(Game *game);

		Game *game;

		void Load(sf::Texture &tileset, const std::string &filename);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void Update(std::vector<GameObject*> objects, float dt);
		void Draw(sf::RenderWindow &window, float dt);

		void CheckCollision(GameObject *object);

	private:
		int m_width, m_height;
		sf::Vector2u m_tilesize;
		sf::Texture m_tileset;
		sf::VertexArray m_vertices;
		std::vector<int> m_tiles, m_collisions;
		EnemyManager m_enemy_manager;
};