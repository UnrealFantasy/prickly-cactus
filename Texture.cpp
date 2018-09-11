#include "stdafx.h"
#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const char * file)
{
	int width, height, channels;

	unsigned char* data = stbi_load(file, &width, &height, &channels, 0);

	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "ERROR: TEXTURE::READ" << std::endl;
	}

	stbi_image_free(data);
}

void Texture::start()
{
	glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture::stop()
{
	// <code> glBindTexture(GL_TEXTURE_2D, 0); </code>
}
