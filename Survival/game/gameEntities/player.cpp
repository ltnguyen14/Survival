#include "player.h"

Player::Player(glm::vec3 worldPosition, glm::vec2 size, const Texture & texture, glm::vec2 coord)
	: Sprite2D(worldPosition, size, texture, coord)
{
	Animator* animator = new Animator(m_texture);

	LoadAnimator(*animator);
	GetAnimator()->LoadRow(0);
}

void Player::Update(InputManager* inputManager, PhysicsManager* physicsManager)
{
	Sprite2D::Update(inputManager, physicsManager);
	//-------------------MOVEMENT-------------------------------
	// Handle key pressed
	glm::vec3 displacement = { 0, 0, 0 };

	if (inputManager->GetKey(GLFW_KEY_A)) {
		displacement.x -= m_speed;
	}
	else if (inputManager->GetKey(GLFW_KEY_D)) {
		displacement.x += m_speed;
	}

	if (inputManager->GetKey(GLFW_KEY_W)) {
		displacement.y -= m_speed;
	}
	else if (inputManager->GetKey(GLFW_KEY_S)) {
		displacement.y += m_speed;
	}

	float displacement_length = sqrt(displacement.x * displacement.x + displacement.y * displacement.y);
	// If moving
	if (displacement_length != 0) {
		displacement = glm::vec3((float)displacement.x / displacement_length, (float)displacement.y / displacement_length, 0) * m_speed;

		EDirection prevDir = m_direction;

		// Change to appropriate direction
		if (displacement.x > 0) {
			m_direction = RIGHT;
		}
		else if (displacement.x < 0) {
			m_direction = LEFT;
		}

		if (displacement.y > 0) {
			m_direction = DOWN;
		}
		else if (displacement.y < 0) {
			m_direction = UP;
		}

		if (prevDir != m_direction)
			GetAnimator()->LoadRow(m_direction);
		// Adjust position of object
		this->position += displacement;
	}

	//-------------------ANIM_FRAME-------------------------------
	if (displacement_length != 0) {
		GetAnimator()->NextFrame();
	}
	else {
		GetAnimator()->LoadSprite({ 0, m_direction });
	}

}

void Player::SetPosition(glm::vec3 position)
{
	this->position = position;
}

void Player::SetRotation(glm::vec3 rotation)
{
	this->rotation = rotation;
}
