#pragma once

#include <glm/glm.hpp>

using namespace glm;

#include "Window.h"

class Camera
{
public:
	vec3 position, rotation;

	Camera();

	void handle_input(Window window);
};

