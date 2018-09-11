#include "stdafx.h"
#include "Shader.h"

Shader::Shader(const char * vertex_file, const char * fragment_file)
{
	std::ifstream vertex_stream(vertex_file);

	std::string vertex_line, vertex_string;

	while (std::getline(vertex_stream, vertex_line))
	{
		vertex_string += vertex_line + "\n";
	}

	const char* vertex_source = vertex_string.c_str();

	std::ifstream fragment_stream(fragment_file);

	std::string fragment_line, fragment_string;

	while (std::getline(fragment_stream, fragment_line))
	{
		fragment_string += fragment_line + "\n";
	}

	const char* fragment_source = fragment_string.c_str();

	vertex = glCreateShader(GL_VERTEX_SHADER);
	fragment = glCreateShader(GL_FRAGMENT_SHADER);

	program = glCreateProgram();

	glShaderSource(vertex, 1, &vertex_source, NULL);
	glShaderSource(fragment, 1, &fragment_source, NULL);

	glCompileShader(vertex);
	glCompileShader(fragment);

	int vertex_status;
	char vertex_log[1024];

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &vertex_status);

	if (!vertex_status)
	{
		glGetShaderInfoLog(vertex, 1024, nullptr, vertex_log);

		std::cout << "ERROR: SHADER::PROGRAM::VERTEX::COMPILE" << std::endl;
		std::cout << vertex_log << std::endl;
	}

	int fragment_status;
	char fragment_log[1024];

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &fragment_status);

	if (!fragment_status)
	{
		glGetShaderInfoLog(fragment, 1024, nullptr, fragment_log);

		std::cout << "ERROR: SHADER::PROGRAM::FRAGMENT::COMPILE" << std::endl;
		std::cout << fragment_log << std::endl;
	}

	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	glLinkProgram(program);

	int link_status;
	char link_log[1024];

	glGetProgramiv(program, GL_LINK_STATUS, &link_status);

	if (!link_status)
	{
		glGetProgramInfoLog(program, 1024, nullptr, link_log);

		std::cout << "ERROR: SHADER::PROGRAM::LINK" << std::endl;
		std::cout << link_log << std::endl;
	}

	glValidateProgram(program);
}

void Shader::start()
{
	glUseProgram(program);
}

void Shader::stop()
{
	glUseProgram(0);
}

void Shader::load_uniform(const char * uniform_name, mat4 matrix)
{
	glUniformMatrix4fv(glGetUniformLocation(program, uniform_name), 1, GL_FALSE, &matrix[0][0]);
}
