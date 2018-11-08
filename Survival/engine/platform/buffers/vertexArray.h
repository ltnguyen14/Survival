#pragma once

#include <vector>
#include <GL/glew.h>

#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "vertexBufferLayout.h"

#include "../../util/Utilities.h"

class VertexArray {
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;

private:
	unsigned int m_vao;
};