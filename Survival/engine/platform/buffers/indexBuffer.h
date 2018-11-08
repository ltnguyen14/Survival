#pragma once

#include <GL/glew.h>
#include "../../util/Utilities.h"

class IndexBuffer {
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	IndexBuffer() {};
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return m_count; };

private:
	unsigned int m_id;
	unsigned int m_count;
};