#include "sprite2D.h"

Sprite2D::Sprite2D(glm::vec3 worldPosition, glm::vec2 size, const Texture& texture, glm::vec2 coord)
	: m_texture(texture), m_coord(coord)
{
	this->size = glm::vec3(size, 1.0f);
	this->position = worldPosition;
	
	std::vector<float> textureCoords = m_texture.GetTextureCoords(m_coord.x, m_coord.y);

	float positions[] = {
		0.0f,   0.0f,   0.0f, textureCoords[0], textureCoords[2],
		size.x, 0.0f,   0.0f, textureCoords[1], textureCoords[2],
		size.x, size.y, 0.0f, textureCoords[1], textureCoords[3],
		0.0f,   size.y, 0.0f, textureCoords[0], textureCoords[3],
	};

	unsigned int indicies[] = {
		0, 1, 2,
		2, 3, 0,
	};

	m_vao = new VertexArray();
	m_vbo = new VertexBuffer(positions, 5 * 4 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(2);
	m_vao->AddBuffer(*m_vbo, layout);

	m_ibo = new IndexBuffer(indicies, 6);
}

Sprite2D::~Sprite2D()
{
	delete(m_vbo);
	delete(m_ibo);
	delete(m_vao);
	delete(m_animator);
}

void Sprite2D::Bind() const
{
	m_vao->Bind();
	m_ibo->Bind();
}

void Sprite2D::Update(InputManager* inputManager)
{
	std::vector<float> textureCoords;
	if (m_animator != nullptr) {
		glm::vec2 texPosition = m_animator->GetCoords();
		textureCoords = m_animator->GetTexture()->GetTextureCoords(texPosition.x, texPosition.y);


		float positions[] = {
			0.0f,   0.0f,   0.0f, textureCoords[0], textureCoords[2],
			size.x, 0.0f,   0.0f, textureCoords[1], textureCoords[2],
			size.x, size.y, 0.0f, textureCoords[1], textureCoords[3],
			0.0f,   size.y, 0.0f, textureCoords[0], textureCoords[3],
		};

		delete(m_vao);
		m_vao = new VertexArray();
		m_vao->Bind();
		m_vbo->Bind();
		m_vbo->LoadData(positions, 5 * 4 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(3);
		layout.Push<float>(2);
		m_vao->AddBuffer(*m_vbo, layout);
	}
}
