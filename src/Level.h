#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Game.h"


class Level : public sf::Drawable, public sf::Transformable
{
	public:
		Level() {}
		Level(Game *game);
		~Level();

		Game *game;

		void Load(sf::Texture &tileset, const std::string &filename);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void UpdateObjects(float dt);
		void DrawObjects(sf::RenderWindow &window, float dt);

		void CheckCollision(GameObject *object);

	private:
		int m_width, m_height;
		sf::Vector2u m_tilesize;
		sf::Texture m_tileset;
		sf::VertexArray m_vertices;
		std::vector<int> m_tiles, m_collisions;
		std::vector<Enemy*> m_enemies;
};