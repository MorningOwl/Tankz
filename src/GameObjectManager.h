#pragma once
#include "GameObject.h"
#include "TileMap.h"
#include <map>


class GameObjectManager
{
	public:
		~GameObjectManager();

		void Add(const std::string &name, GameObject* object);
		void Remove(const std::string &name);
		GameObject* Get(const std::string &name);

		void Update(TileMap &map, float dt);
		void Draw(sf::RenderWindow &window, float dt);

	private:
		std::map<std::string, GameObject*> m_objects;
};