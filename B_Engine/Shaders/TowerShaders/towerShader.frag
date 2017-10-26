#version 120

varying vec2 texCoord;

varying vec4 position;
varying vec3 normals;


uniform sampler2D towerTex;

varying vec4 vert;

varying out vec4 fragColour;


//vec3 PhongLighting(in vec3 fragPos, in vec3 fragNorm, 
//	in vec3 diffuseColour, in vec3 specularColour)
//{
//	const float shininess = 10.0;


//	// ...this is generally a dark constant
//	const vec3 ambient = vec3(0.00, 0.00, 0.05);


//	// diffuse component
//	vec3 N = normalize(fragNorm);
//	vec3 L = normalize(gl_LightSource[0].position.xyz - fragPos);
//	//vec3 L = normalize(lightPos - fragPos);
//	float Lambert = max(0.0, dot(L, N));


//	// specular coefficient
//	vec3 E = normalize(-fragPos);
//	vec3 R = reflect(L,fragNorm);
//	//vec3 E = normalize(eyePos - fragPos);
//	//vec3 R = reflect(L, N);
//	float Phong = max(0.0, dot(R, -E));
//	Phong = pow(Phong, shininess);


//	// add components
//	vec3 diffuse = Lambert * diffuseColour;
//	vec3 specular = Phong * specularColour;
//	return ( diffuse + specular + ambient );
//}


void main() 
{

//const vec3 specularColour = vec3(1.0);

//vec3 diffuseColour = texture2D(palmTreeTex, texCoord).rgb;

fragColour.a = 1.0;

 //fragColour.rgb = PhongLighting(position.xyz, normals, diffuseColour, specularColour);

 fragColour.rgb = texture2D(towerTex, texCoord).rgb;

}