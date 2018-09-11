#include "stdafx.h"
#include "Entity.h"

#define POSITION vec3(0, 0, 0)
#define ROTATION vec3(0, 0, 0)
#define SCALE 1

Entity::Entity(Model * model) : Entity(POSITION, ROTATION, SCALE, model)
{
	Entity::model = model;

	Entity::position = position;
	Entity::rotation = rotation;
	Entity::scale = scale;
}

Entity::Entity(vec3 position, vec3 rotation, float scale, Model * model)
{
	Entity::model = model;

	Entity::position = position;
	Entity::rotation = rotation;
	Entity::scale = scale;
}

void Entity::render(Shader * shader)
{
	model->render(shader);
}

// TODO: Class methods and/or convert to struct format.