#include "gameEngine.h"

#include "gameState.h"

GameEngine::GameEngine(int width, int height, const char* title, bool resizable, int FPS)
	:m_window { width, height, title, resizable }, m_camera { m_window, true }, m_spriteRenderer { "res/shaders/basic.shader" }, m_backgroundRenderer{ "res/shaders/basic.shader" }, m_fps(FPS), m_inputManager(&m_window), m_physicsEngine(&m_window)
{
}

void GameEngine::Init()
{
	m_running = true;
}

void GameEngine::Cleanup()
{
	// cleanup the all states
	while (!m_states.empty()) {
		m_states.back()->Cleanup();
		m_states.pop_back();
	}
}

void GameEngine::ChangeState(GameState * newState)
{
	// cleanup the current state
	if (!m_states.empty()) {
		m_states.back()->Cleanup();
		m_states.pop_back();
	}

	// store and init the new state
	m_states.push_back(newState);
	m_states.back()->Init(this);
}

void GameEngine::PushState(GameState * newState)
{
	// pause current state
	if (!m_states.empty()) {
		m_states.back()->Pause();
	}

	// store and init the new state
	m_states.push_back(newState);
	m_states.back()->Init(this);
}

void GameEngine::PopState()
{
	// cleanup the current state
	if (!m_states.empty()) {
		m_states.back()->Cleanup();
		m_states.pop_back();
	}

	// resume previous state
	if (!m_states.empty()) {
		m_states.back()->Resume();
	}
}

void GameEngine::HandleEvents()
{
	m_window.PollEvents();
	// let the state handle events
	m_states.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	m_running = !m_window.ShouldClose();
	// let the state update the game
	m_states.back()->Update(this);
}

void GameEngine::FixedUpdate()
{
	// Fixed update - UI etc.
	m_states.back()->FixedUpdate(this);
}

void GameEngine::Draw()
{
	m_window.Clear();
	// let the state update the game
	m_states.back()->Draw(this);
	m_window.Draw();
}
