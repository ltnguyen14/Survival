#pragma once
#include "../../components/sprite/sprite2D.h"
#include "../window/Window.h"
#include "../entities/camera.h"
#include "../shader/shader.h"
#include "../texture/texture.h"

class SpriteRenderer {
public:
	SpriteRenderer(const std::string & shaderPath);

	void AddSprite(Sprite2D* sprite);
	void Render(const Camera& camera);

private:
	std::vector<Sprite2D*> m_sprites;
	Shader m_shader;
};