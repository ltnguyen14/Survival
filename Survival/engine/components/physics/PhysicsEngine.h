#pragma once

#include <vector>
#include "collision/BoxCollider.h"

class PhysicsEngine {
public:
	PhysicsEngine(Window* window);
	virtual ~PhysicsEngine();

	void AddBoxCollider(Entity& entity, glm::vec2 size);
	void Update();
	void FixedUpdate();

private:
	std::vector<BoxCollider*> m_colliders;
	Window* m_window;
};