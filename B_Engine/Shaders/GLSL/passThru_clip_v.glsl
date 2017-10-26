#version 330 core

layout (location=0) in vec4 position;
layout (location=2) in vec3 normal;
layout (location=8) in vec2 texcoord;

out vec2 outTexCoords;

uniform mat4 MVP;
//uniform sampler2D tex;


//uniform mat4 worldToObjectMat;

//out vec4 newPos;

void main()
{
	gl_Position = MVP * position;
	outTexCoords = texcoord;
	
}
