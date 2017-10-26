#version 120
	
	uniform sampler2D worldImg;

	varying vec4 verts;
	varying vec4 position;
	varying vec3 normals;
	varying vec2 coords;

	uniform mat4 MVP;
	uniform mat4 modelView;
	
void main()
{
	//Get verts in there modelView space, assign to "verts"
	verts = gl_ModelViewMatrix * gl_Vertex;

	//Get the position of the vertices in modelViewProjection space, assign to "position"
	//gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
	gl_Position = MVP * gl_Vertex;
	position = gl_Position;

	//Assign texture coordinates to "coords"
	coords = gl_MultiTexCoord0.xy; 

	//Get normals, assign to "normals"
	normals = normalize(gl_NormalMatrix * gl_Normal);
} 