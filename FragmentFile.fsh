#version 450

in vec2 fragment_texture;

out vec4 pixel;

uniform sampler2D sampler;

void main()
{
	pixel = texture(sampler, fragment_texture);
}