#include "GameObjectManager.h"


GameObjectManager::~GameObjectManager()
{
	auto object = m_objects.begin();
	while (object != m_objects.end())
	{
		delete object->second;
		object++;
	}
}

void GameObjectManager::Add(const std::string &name, GameObject *object)
{
	m_objects.insert(std::pair<std::string, GameObject*>(name, object));
}

void GameObjectManager::Remove(const std::string &name)
{
	auto object = m_objects.find(name);
	if (object != m_objects.end())
	{
		delete object->second;
		m_objects.erase(object);
	}
}

GameObject* GameObjectManager::Get(const std::string &name)
{
	auto object = m_objects.find(name);
	if (object == m_objects.end()) return nullptr;
	return object->second;
}

void GameObjectManager::Update(Level &map, float dt)
{
	for (auto object = m_objects.begin(); object != m_objects.end(); object++)
	{
		object->second->Update(dt);
		map.CheckCollision(object->second);
		if (object->second->isDead)
		{
			Remove(object->first);
			return;
		}
	}
}

void GameObjectManager::Draw(sf::RenderWindow &window, float dt)
{
	for (auto object = m_objects.begin(); object != m_objects.end(); object++)
	{
		object->second->Draw(window, dt);
	}
}

std::vector<GameObject*> GameObjectManager::GetObjects()
{
	std::vector<GameObject*> objects;
	for (auto object = m_objects.begin(); object != m_objects.end(); object++)
		objects.push_back(object->second);
	return objects;
}