#pragma once

#include <iostream>

#include <fstream>

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

using namespace glm;

#define VERTEX_FILE "./Shaders/VertexFile.vsh"
#define FRAGMENT_FILE "./Shaders/FragmentFile.fsh"

class Shader
{
	unsigned int vertex, fragment, program;
public:
	Shader(const char* vertex_file, const char* fragment_file);

	void start();
	void stop();

	void load_uniform(const char* uniform_name, mat4 matrix);
};

