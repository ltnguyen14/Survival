#pragma once

#include "../../../platform/math/Math.h"
#include "../../../platform/entities/entity.h"
#include "../components/sprite/sprite2D.h"

class BoxCollider : public Entity {
public:
	BoxCollider(glm::vec2 position, glm::vec2 size, Entity* entity, Texture* texture, glm::vec2 coord);
	virtual ~BoxCollider() {};

	inline const Entity* GetEntity() { return m_focusedEntity; };
	void HookEntity(Entity* entity);

	inline void SetPrevPosition() { this->m_prevPosition = this->m_focusedEntity->position; };
	inline Sprite2D* GetBoundingBoxSprite() { return m_boundingBox; };

    void CollisionBacktrack();
	void Update();

	static bool CheckCollision(BoxCollider* boxOne, BoxCollider* boxTwo);

private:
	Sprite2D* m_boundingBox;
	Entity* m_focusedEntity;
    glm::vec3 m_prevPosition;
	glm::vec2 m_centerPoint;
	glm::vec2 m_offsetFromEntityPosition;
};
