#include "stdafx.h"
#include "Camera.h"

#define POSITION vec3(0, 0, 0)
#define ROTATION vec3(0, 0, 0)


Camera::Camera()
{
	Camera::position = POSITION;
	Camera::rotation = ROTATION;
}

void Camera::handle_input(Window window)
{
	float offset = (float) 1 / (float) 32;

	if (glfwGetKey(window.window(), GLFW_KEY_W) == GLFW_PRESS)
	{
		Camera::position = Camera::position + vec3(0, 0, -offset);
	}

	if (glfwGetKey(window.window(), GLFW_KEY_A) == GLFW_PRESS)
	{
		Camera::position = Camera::position + vec3(-offset, 0, 0);
	}

	if (glfwGetKey(window.window(), GLFW_KEY_S) == GLFW_PRESS)
	{
		Camera::position = Camera::position + vec3(0, 0, offset);
	}

	if (glfwGetKey(window.window(), GLFW_KEY_D) == GLFW_PRESS)
	{
		Camera::position = Camera::position + vec3(offset, 0, 0);
	}

	float rotation = (float) 1 / (float) 4;

	if (glfwGetKey(window.window(), GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		Camera::rotation = Camera::rotation + vec3(0, -rotation, 0);
	}

	if (glfwGetKey(window.window(), GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		Camera::rotation = Camera::rotation + vec3(0, rotation, 0);
	}

	if (glfwGetKey(window.window(), GLFW_KEY_UP) == GLFW_PRESS)
	{
		Camera::rotation = Camera::rotation + vec3(-rotation, 0, 0);
	}

	if (glfwGetKey(window.window(), GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		Camera::rotation = Camera::rotation + vec3(rotation, 0, 0);
	}
}
