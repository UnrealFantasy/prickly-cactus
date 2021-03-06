// prickly-cactus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Window.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Model.h"
#include "Entity.h"
#include "Camera.h"
#include "Matrix.h"

int main()
{
	Window m_window = Window();

	m_window.create();

	Shader * m_shader = new Shader(VERTEX_FILE, FRAGMENT_FILE);

	std::vector<vec3> vertices, normals;

	vertices.push_back(vec3(-1, -1, 0));
	vertices.push_back(vec3(-1, 1, 0));
	vertices.push_back(vec3(1, -1, 0));

	vertices.push_back(-vec3(-1, -1, 0));
	vertices.push_back(-vec3(-1, 1, 0));
	vertices.push_back(-vec3(1, -1, 0));

	std::vector<vec2> textures;

	textures.push_back(vec2(0, 1));
	textures.push_back(vec2(0, 0));
	textures.push_back(vec2(1, 1));

	textures.push_back(vec2(1, 0));
	textures.push_back(vec2(1, 1));
	textures.push_back(vec2(0, 0));

	Mesh * m_mesh = new Mesh(vertices, textures, normals);

	Texture * m_texture = new Texture("./Textures/Checkerboard.png");

	Model * m_model = new Model(m_mesh, m_texture);

	Entity * m_entity = new Entity(m_model);

	Camera * m_camera = new Camera();

	m_entity->position.z = -4;

	while (!glfwWindowShouldClose(m_window.window()))
	{
		m_window.clear();

		m_shader->start();

		m_shader->load_uniform("projection_matrix", project_frustrum(70, 0.1f, 1024, (float) WIDTH / (float) HEIGHT));
		m_shader->load_uniform("view_matrix", transform_camera(m_camera));
		m_shader->load_uniform("transformation_matrix", transform_entity(m_entity));

		m_shader->stop();

		m_entity->render(m_shader);

		m_camera->handle_input(m_window);

		m_window.update();
	}

	m_window.close();

	delete m_shader;

	delete m_mesh;
	delete m_texture;

	delete m_model;

	delete m_entity;
	delete m_camera;

	return 0;
}