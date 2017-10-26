
#version 330 core

uniform vec4 colour;

layout (location=0) out vec4 fragColour;

void main()
{
	fragColour = colour;
}