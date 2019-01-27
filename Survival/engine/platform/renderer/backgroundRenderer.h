#pragma once
#include "spriteRenderer.h"

class BackgroundRenderer : public SpriteRenderer {

public:
	BackgroundRenderer(const std::string & shaderPath) : SpriteRenderer(shaderPath) {};

	void AddSprite(Sprite2D* sprite) override;
	void Render(const Camera& camera) override;

private:
	std::vector<glm::mat4> m_modelMatricies;
};