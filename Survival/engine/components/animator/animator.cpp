#include "animator.h"

Animator::Animator(const Texture& texture)
	:m_texture(&texture)
{
	m_coords = { 0, 0 };
	m_textureBlockNum = m_texture->GetBlockNum();
	m_timer = clock();
}

Animator::~Animator()
{
}

void Animator::LoadRow(unsigned int row)
{
	m_coords.x = 0;
	m_coords.y = row;
}

void Animator::LoadSprite(glm::vec2 coords)
{
	m_coords = coords;
}

void Animator::NextFrame()
{
	unsigned int newXPos = m_coords.x;
	if ((clock() - m_timer) >= m_speed) {
		newXPos = ((int)m_coords.x + 1) % (int)m_textureBlockNum.x;
		m_timer = clock();
	}
	
	m_coords = glm::vec2(newXPos, m_coords.y);
}
