#include "camera.h"

Camera::Camera(const Window& window, bool ortho)
	:m_window(window)
{
	if (ortho)
		m_projectionMatrix = makeOrthoMatrix(window);
	else
		m_projectionMatrix = makePerspectiveMatrix(45, window);

	position = { 0, 0, -5 };
}

void Camera::Update()
{
	if (m_entity != nullptr) {
		position = m_entity->position;
		rotation = m_entity->rotation;
		size = m_entity->size;
	}

	m_viewMatrix = makeViewMatrix(*this, m_window);
	m_projViewMatrx = m_projectionMatrix * m_viewMatrix;
}

void Camera::HookEntity(const Entity & entity)
{
	m_entity = &entity;
}

const glm::mat4 & Camera::GetViewMatrix() const
{
	return m_viewMatrix;
}

const glm::mat4 & Camera::GetProjMatrix() const
{
	return m_projectionMatrix;
}

const glm::mat4 & Camera::GetProjectionViewMatrix() const
{
	return m_projViewMatrx;
}

