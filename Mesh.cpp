#include "stdafx.h"
#include "Mesh.h"

Mesh::Mesh(std::vector<vec3> vertices, std::vector<vec2> textures, std::vector<vec3> normals)
{
	Mesh::count = vertices.size();

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int V_VBO;

	glGenBuffers(1, &V_VBO);

	glBindBuffer(GL_ARRAY_BUFFER, V_VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vec3), vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	unsigned int T_VBO;

	glGenBuffers(1, &T_VBO);

	glBindBuffer(GL_ARRAY_BUFFER, T_VBO);
	glBufferData(GL_ARRAY_BUFFER, textures.size() * sizeof(vec2), textures.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
}

void Mesh::render()
{
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, count);
}
