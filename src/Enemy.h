#pragma once
#include "GameObject.h"


enum class EnemyState { IDLE, FOLLOWING, ATTACKING, GOINGHOME };

class Enemy : public GameObject
{
	public:
		Enemy() {}
		~Enemy();
		Enemy(sf::Texture &texture, sf::Vector2f pos);

		virtual void Update(float dt) override;
		void Update(std::vector<GameObject*> objects, float dt);

	private:
		void CheckForTarget(std::vector<GameObject*> objects);
		void GoTo(sf::Vector2f pos);
		void GoTo(GameObject *object);

		bool isAt(sf::Vector2f pos);
		bool isAt(GameObject *object);

		void Attack(GameObject *object, float dt);

		sf::Vector2f m_spawn_point;
		sf::CircleShape m_sight;
		float m_sight_range;
		GameObject *m_target;
		EnemyState m_state;
		float m_attack_interval, m_time_since_last_attack;
};