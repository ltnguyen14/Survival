#include "BoxCollider.h"

void BoxCollider::HookEntity(const Entity * entity)
{
	m_focusedEntity = entity;
    m_prevPosition = entity->position;
}

void BoxCollider::Update()
{
	position = m_focusedEntity->position;
	m_centerPoint = glm::vec2(position.x + size.x / 2, position.y + size.y / 2);
}

void BoxCollider::CollisionBacktrack() {
    m_focusedEntity->position = m_prevPosition;
    this->Update();
}

bool BoxCollider::CheckCollision(BoxCollider * boxOne, BoxCollider * boxTwo)
{
	// Returns true if there is collision
	float xDistance = std::abs(boxOne->m_centerPoint.x - boxTwo->m_centerPoint.x);
	float yDistance = std::abs(boxOne->m_centerPoint.y - boxTwo->m_centerPoint.y);

	float totalXLength = (boxOne->m_size.x + boxTwo->m_size.x) / 2;
	float totalYLength = (boxOne->m_size.y + boxTwo->m_size.y) / 2;

	if (totalXLength >= xDistance && totalYLength >= yDistance)
		return true;

	return false;
}
