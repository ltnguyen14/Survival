#include "testState.h"

void TestState::Init(GameEngine * gameEngine)
{
	srand(time(nullptr));
	Texture* playerTexture = new Texture{ "res/spritesheets/test.png", { 63, 128 } };
	Texture* objectTexture = new Texture{ "res/spritesheets/spritesheet_natural.png", { 48, 64 } };

	Player* player = new Player{ { 0, 0, 0 }, { 64, 128 }, *playerTexture, { 0, 0 } };
    std::cout << "Created a new player with uid: " << player->uid << std::endl;
	gameEngine->m_physicsManager.AddBoxCollider(
		*player, 
		player->position + glm::vec3(player->size.x / 4, player->size.y / 2, 0),
		{ 64 / 2, 128 / 2 }
	);
	/*
	Sprite2D* sprite = new Sprite2D{ {128, 0, 0}, { 64, 64 }, *objectTexture, { 0, 0 } };
    std::cout << "Created a new sprite with uid: " << sprite->uid << std::endl;
	gameEngine->m_physicsManager.AddBoxCollider(*sprite, { 64, 64 });

	m_backgroundSprites.push_back(sprite);
	*/

	for (int x = 0; x < 1; x++)
		for (int y = 0; y < 1; y++) {
			Sprite2D* sprite = new Sprite2D{ { x * 64, y * 64, 0 }, { 48 * 4, 64 * 4 }, *objectTexture, { 1, 0 } };
			gameEngine->m_physicsManager.AddBoxCollider(
				*sprite, 
				sprite->position + glm::vec3(sprite->size.x/4, sprite->size.y/2, 0), 
				glm::vec2(sprite->size.x / 2, sprite->size.y / 2)
			);
			m_backgroundSprites.push_back(sprite);
		}
	
	m_sprites.push_back(player);

	for (unsigned int i = 0; i < m_backgroundSprites.size(); i++) {
		gameEngine->m_spriteRenderer.AddSprite(m_backgroundSprites[i]);
	}

	for (unsigned int i = 0; i < m_sprites.size(); i++) {
		gameEngine->m_spriteRenderer.AddSprite(m_sprites[i]);
	}

	for (int i = 0; i < gameEngine->m_physicsManager.GetBoxColliderSprites().size(); i++) {
		gameEngine->m_spriteRenderer.AddSprite(gameEngine->m_physicsManager.GetBoxColliderSprites()[i]);
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
		m_sprites[i]->Update(&gameEngine->m_inputManager, &gameEngine->m_physicsManager);
	}
	gameEngine->m_camera.Update();
	gameEngine->m_physicsManager.Update();
}

void TestState::FixedUpdate(GameEngine * gameEngine)
{
	gameEngine->m_physicsManager.FixedUpdate();
	{
		ImGui::SetNextWindowSize({ (float)gameEngine->m_window.GetWidth() * 2 / 3, (float)gameEngine->m_window.GetHeight() / 3 });
		ImGui::SetNextWindowPos({ 0, 0 });
		
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
