#pragma once
#include "../platform/window/Window.h"

class InputManager {

public:
	InputManager(Window* window) : m_window(window) {};
	virtual ~InputManager() {};

	inline const bool GetKey(int key) { return m_window->GetKey(key); };
	inline const bool GetMouse(int mouse) { return m_window->GetMouse(mouse); };

private:
	Window* m_window;
};