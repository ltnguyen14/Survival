#pragma once

#include "../../../platform/math/Math.h"
#include "../../../platform/entities/entity.h"

class BoxCollider : public Entity {
public:
	BoxCollider(glm::vec2 size, Entity* entity);
	virtual ~BoxCollider() {};

	inline const Entity* GetEntity() { return m_focusedEntity; };
	void HookEntity(Entity* entity);

	inline void SetPrevPosition() { this->m_prevPosition = this->position; };

    void CollisionBacktrack();
	void Update();

	static bool CheckCollision(BoxCollider* boxOne, BoxCollider* boxTwo);

private:
	Entity* m_focusedEntity;
    glm::vec3 m_prevPosition;
	glm::vec2 m_centerPoint;
};
