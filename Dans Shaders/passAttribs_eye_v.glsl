
#version 330 core

layout (location=0) in vec4 position;
layout (location=2) in vec3 normal;
layout (location=8) in vec2 texcoord;

uniform mat4 modelview;
uniform mat4 projection;

out vertex
{
	vec3 positionEye;
	vec3 normalEye;

	vec2 texcoord;
} data;

void main()
{
	vec4 positionEye = modelview * position;
	data.positionEye = positionEye.xyz;
	gl_Position = projection * positionEye;

	vec4 normalEye = modelview * vec4(normal, 0.0);
	data.normalEye = normalEye.xyz;

	data.texcoord = texcoord;
}