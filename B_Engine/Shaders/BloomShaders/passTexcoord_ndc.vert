#version 120


varying vec2 passTexCoord;

void main()
{
	gl_Position = gl_Vertex; // no modelview to multiply by because we are already set up for clip space

	passTexCoord = gl_MultiTexCoord0.xy; // passing the texcoord to the fragment shader.


}
