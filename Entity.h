#pragma once

#pragma once

#include "Model.h"

#include <glm/glm.hpp>

using namespace glm;

class Entity
{
public:
	vec3 position, rotation;

	float scale;

	Model * model;

	Entity(Model * model);
	Entity(vec3 position, vec3 rotation, float scale, Model * model);

	void render(Shader * shader);
};

