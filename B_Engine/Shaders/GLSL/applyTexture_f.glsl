
#version 330 core

in vec2 outTexCoords;

//out vec4 fragColour;
layout (location=0) out vec4 fragColour;

uniform sampler2D tex;

//uniform vec4 colour;



void main()
{	
	//fragColour = vec4(1.0, 0.0, 0.0, 1.0);
	fragColour = texture(tex, outTexCoords); //colour;
	
}