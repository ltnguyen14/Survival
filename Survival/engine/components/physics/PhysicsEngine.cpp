#include "PhysicsEngine.h"

PhysicsEngine::PhysicsEngine(Window * window)
	: m_window(window)
{
}

PhysicsEngine::~PhysicsEngine()
{
}

void PhysicsEngine::AddBoxCollider(Entity & entity, glm::vec2 size)
{
	BoxCollider* newBoxCollider = new BoxCollider(size);
	m_colliders.push_back(newBoxCollider);
	newBoxCollider->HookEntity(&entity);
}

void PhysicsEngine::Update()
{
	for (auto collider : m_colliders) {
		collider->position = collider->GetEntity()->position;
	}
}
