#include "texture.h"

Texture::Texture(const std::string& path, glm::vec2 blockSize)
	:m_FilePath(path), m_LocalBuffer(nullptr), m_width(0), m_height(0), m_BPP(0), m_id(0), m_blockSize(blockSize)
{
	stbi_set_flip_vertically_on_load(1);
	m_LocalBuffer = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);

	GLCALL(glGenTextures(1, &m_id));
	GLCALL(glBindTexture(GL_TEXTURE_2D, m_id));

	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
	GLCALL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));


	GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
	GLCALL(glBindTexture(GL_TEXTURE_2D, 0));

	if (m_LocalBuffer)
		stbi_image_free(m_LocalBuffer);

	m_blockNum = { (float)m_width / (float)m_blockSize.x, (float)m_height / (float)m_blockSize.y };
}

Texture::~Texture()
{
	GLCALL(glDeleteTextures(1, &m_id));
}

void Texture::Bind(unsigned int slot) const
{
	GLCALL(glActiveTexture(GL_TEXTURE0 + slot));
	GLCALL(glBindTexture(GL_TEXTURE_2D, m_id));
}

void Texture::Unbind()
{
	GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
}

const std::vector<float> Texture::GetTextureCoords(int xPos, int yPos) const
{
	const float TEX_PER_ROW_VERTICLE = (float)m_height / (float)m_blockSize.y;
	const float TEX_PER_ROW_HORIZONTAL = (float)m_width / (float)m_blockSize.x;

	const float SPRITE_SIZE_WIDTH = 1.0f / TEX_PER_ROW_HORIZONTAL;
	const float SPRITE_SIZE_HEIGHT = 1.0f / TEX_PER_ROW_VERTICLE;

	float xMin = (xPos * (float)SPRITE_SIZE_WIDTH);
	float yMax = (yPos * (float)SPRITE_SIZE_HEIGHT) * (-1) + 1;

	float xMax = (xMin + SPRITE_SIZE_WIDTH);
	float yMin = (yMax - SPRITE_SIZE_HEIGHT);

	return { xMin, xMax, yMax, yMin };

}
