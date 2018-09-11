#pragma once

#include <iostream>

#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

using namespace glm;

class Mesh
{
	unsigned int VAO;

	unsigned int count;
public:
	Mesh(std::vector<vec3> vertices, std::vector<vec2> textures, std::vector<vec3> normals);

	void render();
};

