#include "PhysicsManager.h"

PhysicsManager::PhysicsManager(Window * window)
	: m_window(window)
{
	m_boxTexture = new Texture{ "res/spritesheets/Box2D.png", { 16, 16 } };
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::AddBoxCollider(Entity & entity, glm::vec2 position, glm::vec2 size)
{
	BoxCollider* newBoxCollider = new BoxCollider(position, size, &entity, m_boxTexture, { 0, 0 });
	m_colliders.push_back(newBoxCollider);
	newBoxCollider->HookEntity(&entity);
}

void PhysicsManager::Update()
{
	for (auto collider : m_colliders) {
		collider->Update();
	}
}

void PhysicsManager::FixedUpdate()
{
    for (int x = 0; x < m_colliders.size(); x++)
        for (int y = x + 1; y < m_colliders.size(); y++) {
			bool collision = false;
            if (BoxCollider::CheckCollision(m_colliders[x], m_colliders[y])) {
                m_colliders[x]->CollisionBacktrack();
				collision = true;
            }
			if (!collision)
				m_colliders[x]->SetPrevPosition();
        }
}

