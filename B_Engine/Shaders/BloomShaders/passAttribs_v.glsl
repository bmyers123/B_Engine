/*
	Pass Attributes VS

	GLSL vertex shader that performs the clip transformation and passes all 
	relevant attributes down the pipeline.
*/

#version 330 core

layout (location=0) in vec4 position;
layout (location=2) in vec3 normal;
layout (location=8) in vec2 texcoord;

uniform mat4 mvp;

out vertex
{
	vec3 positionObj;
	vec3 normalObj;
	vec2 texcoordObj;
} data;

void main()
{
	// mandatory!
	gl_Position = mvp * position;

	// additional info
	data.positionObj = position.xyz;
	data.normalObj = normal;
	data.texcoordObj = texcoord;
}
