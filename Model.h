#pragma once

#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"

class Model
{
public:
	Mesh * mesh;
	Texture * texture;

	Model(Mesh * mesh, Texture * texture);

	void render(Shader * shader);
};