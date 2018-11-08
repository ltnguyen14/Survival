#pragma once

#include <time.h>

#include "../../platform/texture/texture.h"
#include "../../platform/math/Math.h"

class Animator {

public:
	Animator(const Texture& texture);
	virtual ~Animator();

	void LoadRow(unsigned int row);
	void LoadSprite(glm::vec2 coords);

	void NextFrame();

	inline const Texture* GetTexture() const { return m_texture; };
	inline const glm::vec2 GetCoords() const { return m_coords; };

private:
	const Texture* m_texture;
	glm::vec2 m_coords;
	glm::vec2 m_textureBlockNum;
	int m_speed = 250;
	time_t m_timer;
};