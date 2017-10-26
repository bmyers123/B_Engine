#version 120

varying vec3 vert;
varying vec3 normals;
varying vec2 texCoord;

varying vec3 newLightPos;

uniform sampler2D image0;
//uniform sampler2D image1;

//uniform float amount;
	
void main()
{
//	float shininess = 20.0;

//	vec3 L = normalize(gl_LightSource[0].position.xyz - vert);
//	vec3 E = normalize(-vert);
//	vec3 R = normalize(-reflect(L,norm));
//	float dist = length(gl_LightSource[0].position.xyz - vert)*0.01;


float shininess = 4.0;
	vec3 L = normalize(newLightPos.xyz - vert);
	vec3 E = normalize(-vert);
	vec3 R = normalize(-reflect(L,normals));
	float dist = length(newLightPos.xyz - vert)*0.01;


	//calc diffuse
	float diffuse = dot(normals, L);
	diffuse = clamp(diffuse,0.0,1.0);

	// calc spec
	float spec = pow(max(dot(R,E),0.0),shininess);

	// calc ambience
	float ambient = dot(normals, E);
	ambient = ambient * 0.5 + (1.0 - ambient)*0.8;

	// calc Attenu
	float attenuation = 1.0 / (1.0 + dist*0.001 + (dist*dist)*0.02);



	// calc magic glow
	//float magic = pow(max(dot(normals, normalize(vert))+1.0,0.0),1.0);
	//magic = magic * (sin(amount) *0.25+0.75);

	diffuse = diffuse*0.5+0.5;

	//tune shader
//	diffuse  = floor(diffuse*5.0)/5.0;

	vec3 output = vec3(0.0,0.0,0.0);
	output += vec3(ambient, ambient, ambient);
	output += gl_LightSource[0].diffuse.rgb * diffuse * attenuation;
	output += gl_LightSource[0].specular.rgb * spec * attenuation;
	//output += vec3(magic,magic,magic);


	vec3 outspec = gl_LightSource[0].specular.rgb * spec * attenuation;
	vec3 colorTex = texture2D(image0, texCoord).rgb;
	//vec3 colorTex2 = texture2D(image1, texCoord).rgb;
	output = output * colorTex;
	//texture2D(image0,texCoord).rbg;
	
	float dist2 = length(vert)*0.01;

	//calc fog
	//float fog = 1.0 / (1.0 + dist2*0.001 + (dist2*dist2)*0.02);
	//output = vec3(0.2,0.3,0.4) * (1.0 - fog) + output*fog;

	gl_FragColor = vec4(output, 1.0) + vec4(outspec, 1.0);
} 