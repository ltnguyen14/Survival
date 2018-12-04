#pragma once
#include "spriteRenderer.h"

class BackgroundRenderer : public SpriteRenderer {

public:
	BackgroundRenderer(const std::string & shaderPath) : SpriteRenderer(shaderPath) {};

	void Render(const Camera& camera) override;
};