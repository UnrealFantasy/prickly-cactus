#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Entity.h"
#include "Camera.h"

using namespace glm;

mat4 transform_entity(Entity * entity);
mat4 transform_camera(Camera * camera);
mat4 project_frustrum(float FOV, float zNear, float zFar, float aspect);