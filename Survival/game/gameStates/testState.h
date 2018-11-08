#pragma once

#include "../Engine.h"
#include "../gameEntities/gameEntities.h"

class TestState : public GameState {

public:
	void Init(GameEngine * gameEngine);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* gameEngine);
	void Update(GameEngine* gameEngine);
	void Draw(GameEngine* gameEngine);

private:
	std::vector<Sprite2D*> m_sprites;
};
