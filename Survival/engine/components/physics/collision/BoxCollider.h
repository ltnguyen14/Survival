#pragma once

#include "../../engine/platform/math/Math.h"
#include "../../engine/platform/entities/entity.h"

class BoxCollider : public Entity {
public:
	BoxCollider(glm::vec2 size) : m_size(size), m_position({ 0, 0 }) {};
	virtual ~BoxCollider() {};

	bool Collides(BoxCollider collider);

	inline void HookEntity(const Entity* entity) { m_entity = entity; };
	inline const Entity* GetEntity() const { return m_entity; };

private:
	glm::vec2 m_size;
	glm::vec2 m_position;
	const Entity* m_entity;
};