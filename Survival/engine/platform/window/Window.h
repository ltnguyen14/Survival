#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
private:
	bool m_keys[1024];
	bool m_buttons[128];

	friend static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
	friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

public:
	Window(int width, int height, const char* title, bool resizable);
	virtual ~Window();

	void Clear() const;
	void Draw() const;
	void PollEvents() const;
	
	inline const int GetWidth() const { return m_width; };
	inline const int GetHeight() const { return m_height; };

	inline const bool GetKey(int key) { return m_keys[key]; };
	inline const bool GetMouse(int mouse) { return m_buttons[mouse]; };

	inline bool ShouldClose() { return glfwWindowShouldClose(m_window);  };

private:
	int m_width, m_height;
	const char* m_title;
	bool m_resizable;

private:
	GLFWwindow* m_window;
};