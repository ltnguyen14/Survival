#include "testState.h"

void TestState::Init(GameEngine * gameEngine)
{
	Texture* texture = new Texture{ "res/spritesheets/test.png", { 63, 128 } };

	Player* player = new Player{ { 0, 0, 0 }, { 63, 128 }, *texture, { 0, 0 } };
	Sprite2D* sprite = new Sprite2D{ { 0, 0, 0 }, { 63, 128 }, *texture, { 0, 0 } };
		
	m_sprites.push_back(player);
	m_sprites.push_back(sprite);

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

void TestState::Draw(GameEngine * gameEngine)
{
	gameEngine->m_spriteRenderer.Render(gameEngine->m_camera);
}
