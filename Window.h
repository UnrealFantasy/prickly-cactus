#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 600
#define TITLE "GLFW"

class Window
{
	unsigned int width, height;

	const char * title;

	GLFWwindow * pointer;
public:
	Window();
	Window(unsigned int width, unsigned int height, const char* title);

	void create();

	void clear();
	void update();

	void close();

	GLFWwindow* window();
};

