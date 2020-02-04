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
		void Update(GameObject *object, float dt);

	private:
		void CheckForTarget(GameObject *object);
		void GoTo(sf::Vector2f pos);
		void GoTo(GameObject *object);

		bool isAt(sf::Vector2f pos);
		bool isAt(GameObject *object);

		sf::Vector2f m_spawn_point;
		sf::CircleShape m_sight;
		float m_sight_range;
		GameObject *m_target;
		EnemyState m_state;
		bool m_attack_timer;
};