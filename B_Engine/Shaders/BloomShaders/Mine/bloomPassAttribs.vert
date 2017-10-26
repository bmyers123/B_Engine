#version 120

varying vec2 texCoord;

varying vec4 position;
varying vec3 normals;

uniform float heightRatio;
uniform float widthRatio;

varying vec4 vert;

void main()
{

	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
    position = gl_Position;

    normals = normalize(gl_NormalMatrix * gl_Normal);

    texCoord = gl_MultiTexCoord0.xy;

    vert = gl_ModelViewMatrix * gl_Vertex;

}