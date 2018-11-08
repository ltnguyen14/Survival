#pragma once

#include "gameEngine.h"

class GameState {
public:

	virtual void Init(GameEngine * gameEngine) = 0;
	virtual void Cleanup() = 0;
	 
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	 
	virtual void HandleEvents(GameEngine* gameEngine) = 0;
	virtual void Update(GameEngine* gameEngine) = 0;
	virtual void Draw(GameEngine* gameEngine) = 0;

	void ChangeState(GameEngine* engine, GameState* newState) {
		engine->ChangeState(newState);
	}
};