#include "backgroundRenderer.h"

void BackgroundRenderer::AddSprite(Sprite2D * sprite)
{
	m_sprites.push_back(sprite);
	glm::mat4 modelMatrix = makeModelMatrix({ sprite->position, sprite->rotation });

	m_modelMatricies.push_back(modelMatrix);
}

void BackgroundRenderer::Render(const Camera & camera)
{
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

		m_shader.SetUniformMat4("u_M", m_modelMatricies[i]);
		GLCALL(glDrawElements(GL_TRIANGLES, m_sprites[i]->GetIndiciesCount(), GL_UNSIGNED_INT, nullptr));
	}

	GLCALL(glEnable(GL_DEPTH_TEST));
	GLCALL(glDisable(GL_BLEND));
}
