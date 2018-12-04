#pragma once

#include <algorithm>

#include "../../components/sprite/sprite2D.h"
#include "../window/Window.h"
#include "../entities/camera.h"
#include "../shader/shader.h"
#include "../texture/texture.h"

class SpriteRenderer {
public:
	SpriteRenderer(const std::string & shaderPath);

	void AddSprite(Sprite2D* sprite);
	virtual void Render(const Camera& camera);

protected:
	std::vector<Sprite2D*> m_sprites;
	Shader m_shader;
};