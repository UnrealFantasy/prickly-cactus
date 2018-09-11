#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "stb_image.h"

class Texture
{
	unsigned int texture;
public:
	Texture(const char* file);

	void start();
	void stop();
};

