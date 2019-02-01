#include "BoxCollider.h"

BoxCollider::BoxCollider(glm::vec2 position, glm::vec2 size, Entity * entity)
	: m_centerPoint(0, 0) 
{
	this->m_offsetFromEntityPosition = glm::vec2(entity->position.x - position.x, entity->position.y - position.y);
	this->position = glm::vec3(entity->position.x - m_offsetFromEntityPosition.x, entity->position.y - m_offsetFromEntityPosition.y, 0);
	this->size = glm::vec3(size.x, size.y, 1);  
	this->HookEntity(entity);
}

void BoxCollider::HookEntity(Entity * entity)
{
	m_focusedEntity = entity;
    position = entity->position;
    m_prevPosition = entity->position;
	m_centerPoint = glm::vec2(position.x + size.x / 2, position.y + size.y / 2);
}

void BoxCollider::Update()
{
	this->position = glm::vec3(m_focusedEntity->position.x - m_offsetFromEntityPosition.x, m_focusedEntity->position.y - m_offsetFromEntityPosition.y, 0);
	m_centerPoint = glm::vec2(this->position.x + size.x / 2, this->position.y + size.y / 2);
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

	float totalXLength = (boxOne->size.x + boxTwo->size.x) / 2;
	float totalYLength = (boxOne->size.y + boxTwo->size.y) / 2;

	if (totalXLength >= xDistance && totalYLength >= yDistance)
		return true;

	return false;
}
