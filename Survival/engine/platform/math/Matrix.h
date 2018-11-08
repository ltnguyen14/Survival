#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "../entities/camera.h"
#include "../entities/entity.h"
#include "../window/Window.h"

class Camera;
struct Entity;
class Window;

glm::mat4 makeModelMatrix(const Entity& entity);
glm::mat4 makeViewMatrix(const Camera& camera, const Window& window);
glm::mat4 makePerspectiveMatrix(float fov, const Window& window);
glm::mat4 makeOrthoMatrix(const Window& window);

