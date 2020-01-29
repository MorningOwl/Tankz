#include "TextureManager.h"
#include <cassert>


void TextureManager::LoadTexture(const std::string &name, const std::string &filename)
{
	sf::Texture tex;
	assert(tex.loadFromFile(filename));
	m_textures[name] = tex;
}

sf::Texture& TextureManager::GetRef(const std::string &texture)
{
	return m_textures.at(texture);
}