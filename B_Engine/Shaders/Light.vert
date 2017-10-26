#version 120

varying vec3 vert;
varying vec3 normals;
varying vec2 texCoord;

varying vec3 newLightPos;

uniform vec3 theLight;
	
void main()
{
	
	newLightPos = theLight.xyz;

	vert = (gl_ModelViewMatrix * gl_Vertex).xyz;
	normals = normalize(gl_NormalMatrix * gl_Normal);

	newLightPos = (gl_ModelViewMatrix * vec4(newLightPos, gl_Vertex.w)).xyz;
	
	texCoord = gl_MultiTexCoord0.xy;
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
} 