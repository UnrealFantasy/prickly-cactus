#version 450

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec2 vertex_texture;

out vec2 fragment_texture;

uniform mat4 transformation_matrix, view_matrix, projection_matrix;

void main()
{
	gl_Position = projection_matrix * view_matrix * transformation_matrix * vec4(vertex, 1);
	
	fragment_texture = vertex_texture;
}