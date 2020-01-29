#pragma once
#include <SFML/Graphics.hpp>


class TileMap : public sf::Drawable, public sf::Transformable
{
	public:
		void Load(sf::Texture &tileset, const std::string &filename);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		int m_width, m_height;
		sf::Vector2u m_tilesize;
		std::vector<int> m_tiles;
		sf::Texture m_tileset;
		sf::VertexArray m_vertices;
};