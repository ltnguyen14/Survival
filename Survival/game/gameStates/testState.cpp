#include "testState.h"

void TestState::Init(GameEngine * gameEngine)
{
	srand(time(nullptr));
	Texture* playerTexture = new Texture{ "res/spritesheets/Player.png", { 16, 32 } };
	Texture* objectTexture = new Texture{ "res/spritesheets/spritesheet_natural.png", { 16, 16 } };

	m_textures.push_back(playerTexture);
	m_textures.push_back(objectTexture);

	Player* player = new Player{ { 0, 0, 0 }, { 64, 128 }, *playerTexture, { 0, 0 } };
    std::cout << "Created a new player with uid: " << player->uid << std::endl;
	gameEngine->m_physicsManager.AddBoxCollider(
		*player, 
		player->position + glm::vec3(player->size.x / 4, player->size.y / 2, 0),
		{ 64 / 2, 128 / 2 }
	);

	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++) {
			Sprite2D* sprite = new Sprite2D{ { x * 64, y * 64, 0 }, { 64, 64 }, *objectTexture, { 1, 0 } };
			m_backgroundSprites.push_back(sprite);
		}
	
	m_sprites.push_back(player);

	// Add background sprites
	for (unsigned int i = 0; i < m_backgroundSprites.size(); i++) {
		gameEngine->m_backgroundRenderer.AddSprite(m_backgroundSprites[i]);
	}

	// Add to normal sprite renderer
	for (unsigned int i = 0; i < m_sprites.size(); i++) {
		gameEngine->m_spriteRenderer.AddSprite(m_sprites[i]);
	}

	//Add collision bounding boxes
	std::vector<BoxCollider*> boxColliders = gameEngine->m_physicsManager.GetBoxColliders();
	for (int i = 0; i < boxColliders.size(); i++) {
		gameEngine->m_collisionBoxRenderer.AddSprite(boxColliders[i]->GetBoundingBoxSprite());
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
		ImGui::SetNextWindowSize({ (float)gameEngine->m_window.GetWidth(), (float)gameEngine->m_window.GetHeight() / 3 });
		ImGui::SetNextWindowPos({ 0, 0 });
		
		ImGui::Begin("Debugger");                          // Create a window called "Hello, world!" and append into it.
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::Checkbox("Draw collision boxes", &m_drawCollisionBoxes);

		if (ImGui::Button("Reload Textures")) {
			for (auto texture : m_textures) {
				texture->ReloadTexture();
			}
		}

		if (ImGui::Button("Quit")) {
			gameEngine->Quit();
		}

		ImGui::End();
	}
}

void TestState::Draw(GameEngine * gameEngine)
{
	gameEngine->m_backgroundRenderer.Render(gameEngine->m_camera);
	gameEngine->m_spriteRenderer.Render(gameEngine->m_camera);

	if (m_drawCollisionBoxes) {
		gameEngine->m_collisionBoxRenderer.Render(gameEngine->m_camera);
	}
}
