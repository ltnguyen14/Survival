#include "Window.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <gtx/string_cast.hpp>

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_keys[key] = action != GLFW_RELEASE;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
	win->m_buttons[button] = action != GLFW_RELEASE;
}

Window::Window(int width, int height, const char * title, bool resizable)
	:m_width(width), m_height(height), m_title(title), m_resizable(resizable)
{

	/* Initialize the library */
	if (!glfwInit()) {
		std::cout << "Error initializing glfw" << std::endl;
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, m_resizable);

	/* Create a windowed mode window and its OpenGL context */
	m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);

	if (!m_window)
	{
		std::cout << "Error creating new window" << std::endl;
		glfwTerminate();
		return;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(m_window);
	glEnable(GL_DEPTH_TEST);

	if (glewInit() != GLEW_OK) {
		std::cout << "Error initializing GLEW" << std::endl;
		return;
	}

	std::cout << "GLEW version: " << glGetString(GL_VERSION) << std::endl;

	glfwSetWindowUserPointer(m_window, this);
	glfwSetMouseButtonCallback(m_window, mouse_button_callback);
	glfwSetKeyCallback(m_window, key_callback);
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Clear() const
{
	glClearColor(0.2f, 0.4f, 0.8f, 1.0f);
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Draw() const
{
	/* Swap front and back buffers */
	glfwSwapBuffers(m_window);
}

void Window::PollEvents() const
{
	/* Poll for and process events */
	glfwPollEvents();
}
