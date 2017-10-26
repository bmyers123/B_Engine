
#version 330 core

in vertex
{
	vec3 positionObj;
	vec3 normalObj;

	vec2 texcoord;
} data;

uniform vec3 eyePos;
uniform vec3 lightPos;
uniform sampler2D diffuseMap;

layout (location=0) out vec4 fragColour;


vec3 PhongLighting(in vec3 fragPos, in vec3 fragNorm, 
	in vec3 diffuseColour, in vec3 specularColour)
{
	// ...this is generally a dark constant
	const vec3 ambient = vec3(0.00, 0.00, 0.05);


	// diffuse component
	vec3 N = normalize(fragNorm);
	vec3 L = normalize(lightPos - fragPos);
	float Lambert = max(0.0, dot(L, N));


	// specular coefficient
	vec3 E = normalize(eyePos - fragPos);
	vec3 R = reflect(L, N);
	float Phong = max(0.0, dot(R, -E));
	// pro-tip: doing this is faster than calling the pow() function...
	Phong *= Phong; //^2
	Phong *= Phong; //^4
	Phong *= Phong;	//^8


	// add components
	vec3 diffuse = Lambert * diffuseColour;
	vec3 specular = Phong * specularColour;
	return ( diffuse + specular + ambient );
}


void main()
{
	vec3 diffuseColour = texture(diffuseMap, data.texcoord).rgb;
	const vec3 specularColour = vec3(1.0);

	fragColour.rgb = PhongLighting(data.positionObj, data.normalObj, 
		diffuseColour, specularColour);
}
