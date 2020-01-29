#pragma once
#include <SFML/Graphics.hpp>
#include <map>


class TextureManager
{
	public:
		void LoadTexture(const std::string &name, const std::string &filename);
		sf::Texture& GetRef(const std::string &texture);

	private:
		std::map<const std::string, sf::Texture> m_textures;
};