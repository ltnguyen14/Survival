#include "BoxCollider.h"

void BoxCollider::HookEntity(const Entity * entity)
{
	m_focusedEntity = entity;
}

void BoxCollider::Update()
{
	position = m_focusedEntity->position;
	m_centerPoint = glm::vec2(position.x + size.x / 2, position.y + size.y / 2);
}
