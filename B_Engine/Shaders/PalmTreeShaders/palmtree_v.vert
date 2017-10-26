#version 120

varying vec2 texCoord;

//varying vec4 position;
varying vec3 normals;


//uniform sampler2D palmTreeTex;

uniform sampler2D image0;

varying vec3 vert;

varying vec3 newLightPos;
uniform vec3 theLight;


void main()
{


	newLightPos = theLight.xyz;

	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
  //  position = gl_Position;

    normals = normalize(gl_NormalMatrix * gl_Normal);

    texCoord = gl_MultiTexCoord0.xy;

    vert = (gl_ModelViewMatrix * gl_Vertex).xyz;

	newLightPos = (gl_ModelViewMatrix * vec4(newLightPos, gl_Vertex.w)).xyz;

}
