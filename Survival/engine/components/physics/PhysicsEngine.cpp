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
		collider->Update();
	}
}

void PhysicsEngine::FixedUpdate()
{
	if (BoxCollider::CheckCollision(m_colliders[0], m_colliders[1]))
		std::cout << "Collision" << std::endl;
}


