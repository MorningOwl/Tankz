#include "TileMap.h"
#include <fstream>
#include <cassert>


void TileMap::Load(sf::Texture &tileset, const std::string &filename)
{
	m_tileset = tileset;
	std::ifstream load(filename);
	assert(load.is_open());

	load >> m_width >> m_height;
	load >> m_tilesize.x >> m_tilesize.y;

	for (int i = 0; i < m_width * m_height; i++)
	{
		int tile;
		load >> tile;
		m_tiles.push_back(tile);
	}

	load.close();

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(m_width * m_height * 4);

	for (int i = 0; i < m_width; i++)
		for (int j = 0; j < m_height; j++)
		{
			int tiletype = m_tiles[j * m_width + i];

			int tu = tiletype % (m_tileset.getSize().x / m_tilesize.x);
			int tv = tiletype / (m_tileset.getSize().x / m_tilesize.x);

			sf::Vertex *quad = &m_vertices[(j * m_width + i) * 4];

			quad[0].position = sf::Vector2f(i * m_tilesize.x, j * m_tilesize.y);
			quad[1].position = sf::Vector2f((i + 1) * m_tilesize.x, j * m_tilesize.y);
			quad[2].position = sf::Vector2f((i + 1) * m_tilesize.x, (j + 1) * m_tilesize.y);
			quad[3].position = sf::Vector2f(i * m_tilesize.x, (j + 1) * m_tilesize.y);

			quad[0].texCoords = sf::Vector2f(tu * m_tilesize.x, tv * m_tilesize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * m_tilesize.x, tv * m_tilesize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * m_tilesize.x, (tv + 1) * m_tilesize.y);
			quad[3].texCoords = sf::Vector2f(tu * m_tilesize.x, (tv + 1) * m_tilesize.y);
		}
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_tileset;
	target.draw(m_vertices, states);
}