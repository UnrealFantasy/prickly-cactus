#include "stdafx.h"
#include "Matrix.h"

mat4 transform_entity(Entity * entity)
{
	mat4 transformation_matrix = mat4(1);

	transformation_matrix = glm::translate(transformation_matrix, entity->position);

	transformation_matrix = glm::rotate(transformation_matrix, glm::radians(entity->rotation.x), vec3(1, 0, 0));
	transformation_matrix = glm::rotate(transformation_matrix, glm::radians(entity->rotation.y), vec3(0, 1, 0));
	transformation_matrix = glm::rotate(transformation_matrix, glm::radians(entity->rotation.z), vec3(0, 0, 1));

	transformation_matrix = glm::scale(transformation_matrix, vec3(entity->scale));

	return transformation_matrix;
}

mat4 transform_camera(Camera * camera)
{
	mat4 transformation_matrix = mat4(1);

	transformation_matrix = glm::rotate(transformation_matrix, glm::radians(camera->rotation.z), vec3(0, 0, 1));
	transformation_matrix = glm::rotate(transformation_matrix, glm::radians(camera->rotation.y), vec3(0, 1, 0));
	transformation_matrix = glm::rotate(transformation_matrix, glm::radians(camera->rotation.x), vec3(1, 0, 0));

	transformation_matrix = glm::translate(transformation_matrix, -(camera->position));

	return transformation_matrix;
}

mat4 project_frustrum(float FOV, float zNear, float zFar, float aspect)
{
	mat4 transformation_matrix = glm::perspective(FOV, aspect, zNear, zFar);

	return transformation_matrix;
}
