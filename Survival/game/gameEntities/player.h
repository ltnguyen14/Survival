#pragma once
#include "../../engine/Engine.h"
#include"../util/util.h"

#define DEFAULT_SPEED 5

class Player : public Sprite2D {

public:
	Player(glm::vec3 worldPosition, glm::vec2 size, const Texture& texture, glm::vec2 coord);

	void Update(InputManager* inputManager, PhysicsManager* physicsManager);

	void SetPosition(glm::vec3 position);
	void SetRotation(glm::vec3 rotation);

private:
	EDirection m_direction = DOWN;
	float m_speed = DEFAULT_SPEED;
};
