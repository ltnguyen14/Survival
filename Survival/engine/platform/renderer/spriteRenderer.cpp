#include "spriteRenderer.h"

SpriteRenderer::SpriteRenderer(const std::string & shaderPath)
	: m_shader(shaderPath)
{
}

void SpriteRenderer::AddSprite(Sprite2D* sprite)
{
	m_sprites.push_back(sprite);
}

void SpriteRenderer::RemoveSprite(Sprite2D* sprite)
{
    int index = -1;
    for (int i = 0; i < m_sprites.size(); i++) {
        if (sprite->uid == m_sprites[i]->uid) {
            index = i;
            break;
        }
    }

    if (index >= 0) {
        m_sprites.erase(m_sprites.begin() + index);
    }
}



void SpriteRenderer::Render(const Camera & camera)
{
	std::sort(m_sprites.begin(), m_sprites.end(), [](Sprite2D* lhs, Sprite2D* rhs) -> bool { return lhs->position.y < rhs->position.y; });

	m_shader.BindShader();

	m_shader.SetUniformInt1("u_Texture", 0);

	glm::mat4 projViewMatrix = camera.GetProjectionViewMatrix();

	m_shader.SetUniformMat4("u_VP", projViewMatrix);

	GLCALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	GLCALL(glEnable(GL_BLEND));
	GLCALL(glDisable(GL_DEPTH_TEST));

	for (unsigned int i = 0; i < m_sprites.size(); i++) {
		m_sprites[i]->Bind();
		m_sprites[i]->GetTexture().Bind();

		glm::mat4 modelMatrix = makeModelMatrix({ m_sprites[i]->position, m_sprites[i]->rotation });
		m_shader.SetUniformMat4("u_M", modelMatrix);
		GLCALL(glDrawElements(GL_TRIANGLES, m_sprites[i]->GetIndiciesCount(), GL_UNSIGNED_INT, nullptr));
	}

	GLCALL(glEnable(GL_DEPTH_TEST));
	GLCALL(glDisable(GL_BLEND));

	//for (unsigned int i = 0; i < m_sprites.size(); i++) {
	//	delete(m_sprites[i]);
	//}
	//m_sprites.clear();
}
