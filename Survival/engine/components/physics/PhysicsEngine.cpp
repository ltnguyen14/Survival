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
    for (int x = 0; x < m_colliders.size(); x++)
        for (int y = x + 1; y < m_colliders.size(); y++) {
            if (BoxCollider::CheckCollision(m_colliders[x], m_colliders[y])) {
                std::cout << "Collision detected!" << std::endl;
                m_colliders[x].CollisionBacktrack();
            }
        }
}

