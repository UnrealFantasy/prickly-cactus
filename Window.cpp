#include "stdafx.h"
#include "Window.h"


Window::Window()
{
	Window::width = WIDTH;
	Window::height = HEIGHT;
	Window::title = TITLE;
}

Window::Window(unsigned int width, unsigned int height, const char * title)
{
	Window::width = width;
	Window::height = height;
	Window::title = title;
}

void Window::create()
{
	if (glfwInit() != GLFW_TRUE)
	{
		std::cout << "ERROR: GLFW::INIT" << std::endl;

		glfwTerminate();
	}

	glfwDefaultWindowHints();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	pointer = glfwCreateWindow(width, height, title, nullptr, nullptr);

	if (!pointer)
	{
		std::cout << "ERROR: GLFW::CREATE" << std::endl;

		glfwTerminate();
	}

	glfwMakeContextCurrent(pointer);

	glfwSwapInterval(1);

	glfwShowWindow(pointer);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR: GLEW::INIT" << std::endl;
	}
}

void Window::clear()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update()
{
	glfwSwapBuffers(pointer);
	glfwPollEvents();
}

void Window::close()
{
	glfwDestroyWindow(pointer);
	glfwTerminate();
}

GLFWwindow * Window::window()
{
	return pointer;
}
