
#version 330 core

in vertex
{
	vec3 positionEye;
	vec3 normalEye;

	vec2 texcoord;
} data;

uniform sampler2D diffuseMap;
uniform sampler2D specularMap;

uniform vec3 lightPosEye;

layout (location=0) out vec4 fragColour;


// do Phong lighting and optimize the hell out of it
void PhongLighting(in vec3 fragPos, in vec3 fragNorm, 
				   in vec3 lightPos, in vec3 eyePos, 
				   out float kDiffuse, out float kSpecular)
{
	// compute Lambert first
	vec3 N = normalize(fragNorm);
	vec3 L = normalize(lightPos - fragPos);
	float Lambert = dot(N, L);
	kDiffuse = max(0.0, Lambert);

	// now compute Phong
	vec3 R = (2.0*Lambert)*N - L;
	vec3 E = normalize(eyePos - fragPos);
	float Phong = dot(R, E);
	kSpecular = max(0.0, Phong);

	// apply shininess
	kSpecular *= kSpecular;
	kSpecular *= kSpecular;
	kSpecular *= kSpecular;
}


void main()
{
	float kDiffuse, kSpecular;
	PhongLighting(data.positionEye, data.normalEye, 
				  lightPosEye, vec3(0.0), 
				  kDiffuse, kSpecular);	
	
	vec3 ambient = vec3(0.100, 0.050, 0.025);
	vec3 diffuse = kDiffuse * texture(diffuseMap, data.texcoord).rgb;
	vec3 specular = kSpecular * texture(specularMap, data.texcoord).rgb;

	fragColour.rgb = ( ambient + diffuse + specular );
}