#pragma once

#include <vector>
#include "collision/BoxCollider.h"
#include "../components/sprite/sprite2D.h"

class PhysicsManager {
public:
	PhysicsManager(Window* window);
	virtual ~PhysicsManager();

	void AddBoxCollider(Entity& entity, glm::vec2 position, glm::vec2 size);
	std::vector<BoxCollider*> GetBoxColliders() { return m_colliders; };

	void Update();
	void FixedUpdate();

private:
	std::vector<BoxCollider*> m_colliders;
	Texture* m_boxTexture;
	Window* m_window;
};