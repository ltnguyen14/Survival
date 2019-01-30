#pragma once

#include "../../../platform/math/Math.h"
#include "../../../platform/entities/entity.h"

class BoxCollider : public Entity {
public:
	BoxCollider(glm::vec2 size) : m_size(size), m_centerPoint(0, 0) {};
	virtual ~BoxCollider() {};

	inline const Entity* GetEntity() { return m_focusedEntity; };
	void HookEntity(const Entity* entity);
	void Update();

	static bool CheckCollision(BoxCollider* boxOne, BoxCollider* boxTwo);

private:
	const Entity* m_focusedEntity;
	glm::vec2 m_centerPoint;
	glm::vec2 m_size;
};