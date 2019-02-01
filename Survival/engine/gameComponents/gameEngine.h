#pragma once

#include <vector>
#include "../platform/window/Window.h"
#include "../platform/entities/camera.h"
#include "../platform/renderer/spriteRenderer.h"
#include "../platform/renderer/backgroundRenderer.h"
#include "../components/physics/PhysicsManager.h"
#include "../components/event/EventManager.h"
#include "inputManager.h"

class GameState;

class GameEngine {
public:
	GameEngine(int width, int height, const char* title, bool resizable, int FPS);

	void Init();
	void Cleanup();

	void ChangeState(GameState* newState);
	void PushState(GameState* newState);
	void PopState();

	void HandleEvents();
	void Update();
	void FixedUpdate();
	void Draw();

	bool Running() { return m_running; };
	void Quit() { m_running = false; };

public:
	Window m_window;
	Camera m_camera;
	InputManager m_inputManager;
	EventManager m_eventManager;
	PhysicsManager m_physicsManager;
	SpriteRenderer m_spriteRenderer;
	BackgroundRenderer m_backgroundRenderer;

private:
	std::vector<GameState*> m_states;
	bool m_running;
	int m_fps;
};