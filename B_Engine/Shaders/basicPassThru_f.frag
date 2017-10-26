#version 120

uniform sampler2D worldImg;
varying vec4 verts;
varying vec4 position;
varying vec3 normals;
varying vec2 coords;

void main()
{
	vec4 outColor = texture2D(worldImg, coords);

	gl_FragColor = outColor;
}
