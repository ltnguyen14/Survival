#pragma once
#include "Entity.h"
#include "../window/Window.h"
#include "../math/Matrix.h"

class Camera : public Entity{
public:
	Camera(const Window& window, bool ortho);

	void Update();
	void HookEntity(const Entity& entity);

	const glm::mat4& GetViewMatrix() const;
	const glm::mat4& GetProjMatrix() const;
	const glm::mat4& GetProjectionViewMatrix() const;

private:
	const Entity* m_entity;
	glm::mat4 m_projectionMatrix;
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projViewMatrx;
	const Window& m_window;
};