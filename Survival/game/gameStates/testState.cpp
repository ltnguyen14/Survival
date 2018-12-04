#include "testState.h"

void TestState::Init(GameEngine * gameEngine)
{
	srand(time(nullptr));
	Texture* playerTexture = new Texture{ "res/spritesheets/Player.png", { 16, 32 } };
	Texture* objectTexture = new Texture{ "res/spritesheets/spritesheet_natural_items.png", { 16, 16 } };

	Player* player = new Player{ { 0, 0, 0 }, { 64, 128 }, *playerTexture, { 0, 0 } };

	for (unsigned int x = 0; x < 10; x++)
		for (unsigned int y = 0; y < 10; y++) {
			Sprite2D* sprite = new Sprite2D{ { x * 64 * 2, y * 64, 0 }, { 64, 64 }, *objectTexture, { 1, 0 } };
			Sprite2D* sprite2 = new Sprite2D{ { x * 64 * 2 + 64, y * 64, 0 }, { 64, 64 }, *objectTexture, { 0, 0 } };

			m_backgroundSprites.push_back(sprite);
			m_backgroundSprites.push_back(sprite2);
		}
	
	m_sprites.push_back(player);

	for (unsigned int i = 0; i < m_backgroundSprites.size(); i++) {
		gameEngine->m_backgroundRenderer.AddSprite(m_backgroundSprites[i]);
	}

	for (unsigned int i = 0; i < m_sprites.size(); i++) {
		gameEngine->m_spriteRenderer.AddSprite(m_sprites[i]);
	}
	gameEngine->m_camera.HookEntity(*player);
}

void TestState::Cleanup()
{
}

void TestState::Pause()
{
}

void TestState::Resume()
{
}

void TestState::HandleEvents(GameEngine * gameEngine)
{
}

void TestState::Update(GameEngine * gameEngine)
{
	for (unsigned int i = 0; i < m_sprites.size(); i++) {
		m_sprites[i]->Update(&gameEngine->m_inputManager);
	}
	gameEngine->m_camera.Update();
}

void TestState::FixedUpdate(GameEngine * gameEngine)
{
	{
		ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}
}

void TestState::Draw(GameEngine * gameEngine)
{
	gameEngine->m_backgroundRenderer.Render(gameEngine->m_camera);
	gameEngine->m_spriteRenderer.Render(gameEngine->m_camera);
}
