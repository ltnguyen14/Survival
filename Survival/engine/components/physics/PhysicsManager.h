#pragma once

#include <vector>
#include "collision/BoxCollider.h"
#include "../components/sprite/sprite2D.h"

class PhysicsManager {
public:
	PhysicsManager(Window* window);
	virtual ~PhysicsManager();

	void AddBoxCollider(Entity& entity, glm::vec2 position, glm::vec2 size);
	std::vector<Sprite2D*> GetBoxColliderSprites() { return m_boxColliderSprites; };

	void Update();
	void FixedUpdate();

private:
	std::vector<BoxCollider*> m_colliders;
	std::vector<Sprite2D*> m_boxColliderSprites;
	Texture* m_boxTexture;
	Window* m_window;
};