#pragma once

#include <string>
#include <vector>
#include <glm.hpp>
#include <stb_image/stb_image.h>

#include "../../util/Utilities.h"

class Texture {
public:
	Texture(const std::string& path, glm::vec2 blockSize);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind();

	const std::vector<float> GetTextureCoords(int xPos, int yPos) const;

	inline const int GetWidth() const { return m_width; };
	inline const int GetHeight() const { return m_height; };
	inline const glm::vec2 GetBlockNum() const { return m_blockNum; };

private:
	glm::vec2 m_blockNum;
	glm::vec2 m_blockSize;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_width, m_height, m_BPP;
	unsigned int m_id;
};