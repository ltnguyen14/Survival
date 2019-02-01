#pragma once

#include <vector>
#include "collision/BoxCollider.h"

class PhysicsManager {
public:
	PhysicsManager(Window* window);
	virtual ~PhysicsManager();

	void AddBoxCollider(Entity& entity, glm::vec2 size);
	void Update();
	void FixedUpdate();

private:
	std::vector<BoxCollider*> m_colliders;
	Window* m_window;
};