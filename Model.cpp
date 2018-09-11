#include "stdafx.h"
#include "Model.h"


Model::Model(Mesh * mesh, Texture * texture)
{
	Model::mesh = mesh;
	Model::texture = texture;
}

void Model::render(Shader * shader)
{
	shader->start();
	texture->start();

	mesh->render();

	shader->stop();
}
