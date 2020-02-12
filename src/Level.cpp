#include "Level.h"
#include <fstream>
#include <cassert>


void Level::Init(Game *game)
{
	this->game = game;
	player = new Player(game->texmgr.GetRef("Player"), game->texmgr.GetRef("Projectile"), sf::Vector2f(400, 500));
}

Level::~Level()
{
	delete player;
}

void Level::Load(sf::Texture &tileset, const std::string &filename)
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

	for (int i = 0; i < m_width * m_height; i++)
	{
		int tile;
		load >> tile;
		m_collisions.push_back(tile);
	}

	for (int i = 0; i < m_width * m_height; i++)
	{
		int tile;
		load >> tile;
		if (tile == 1)
			m_enemy_manager.Add(new Enemy(game->texmgr.GetRef("Enemy"),
				sf::Vector2f((i % m_width) * m_tilesize.x + m_tilesize.x / 2, (i / m_width) * m_tilesize.y + m_tilesize.y / 2)));
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

void Level::CheckCollision(GameObject *object, bool projectile)
{
	sf::Vector2f pos = sf::Vector2f((int)object->GetPosition().x / m_tilesize.x, (int)object->GetPosition().y / m_tilesize.y);
	sf::FloatRect current_rect = object->GetBounds();
	sf::FloatRect collision_rect_X = sf::FloatRect(current_rect.left + object->GetVelocity().x, current_rect.top, current_rect.width, current_rect.height);
	sf::FloatRect collision_rect_Y = sf::FloatRect(current_rect.left, current_rect.top + object->GetVelocity().y, current_rect.width, current_rect.height);

	for (int y = pos.y - 1; y <= pos.y + 1; y++)
		for (int x = pos.x - 1; x <= pos.x + 1; x++)
		{
			if (y * m_width + x > m_collisions.size()) continue;
			if (!m_collisions[y * m_width + x]) continue;
			sf::FloatRect tile(x * m_tilesize.x, y * m_tilesize.y, m_tilesize.x, m_tilesize.y);

			if (projectile && current_rect.intersects(tile))
			{
				object->Kill();
				return;
			}

			if (tile.intersects(collision_rect_X))
			{
				if (collision_rect_X.left < tile.left && collision_rect_X.left + collision_rect_X.width > tile.left)
					object->vel.x = tile.left - (current_rect.left + current_rect.width);

				else if (collision_rect_X.left < tile.left + tile.width && collision_rect_X.left + collision_rect_X.width > tile.left + tile.width)
					object->vel.x = tile.left + tile.width - current_rect.left;
			}

			if (tile.intersects(collision_rect_Y))
			{
				if (collision_rect_Y.top < tile.top && collision_rect_Y.top + collision_rect_Y.height > tile.top)
					object->vel.y = tile.top - (current_rect.top + current_rect.height);

				else if (collision_rect_Y.top < tile.top + tile.height && collision_rect_Y.top + collision_rect_Y.height > tile.top + tile.height)
					object->vel.y = tile.top + tile.height - current_rect.top;
			}
		}

	object->Move();
}

std::vector<Projectile*> Level::GetProjectiles()
{
	return player->GetProjectiles();
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_tileset;
	target.draw(m_vertices, states);
}

void Level::Update(float dt)
{
	m_enemy_manager.Update(this, player, dt);
	player->Update(dt);
	CheckCollision(player);

	for (auto proj : GetProjectiles())
		CheckCollision(proj, true);
}

void Level::Draw(sf::RenderWindow &window, float dt)
{
	m_enemy_manager.Draw(window, dt);
	player->Draw(window, dt);
}