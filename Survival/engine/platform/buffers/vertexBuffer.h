#pragma once

#include <GL/glew.h>
#include "../../util/Utilities.h"

class VertexBuffer {
public:
	VertexBuffer(const void* data, unsigned int size);
	VertexBuffer() : m_id(0) {};

	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

	void LoadData(const void* data, unsigned int size);

private:
	unsigned int m_id;

};