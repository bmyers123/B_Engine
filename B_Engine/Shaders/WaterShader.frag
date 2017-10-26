#version 120

//OLD VARS

//uniform sampler2D tex0;
//varying vec2 coords;
////uniform sampler2D tex2;
//uniform sampler2D tex1;
//uniform float amount;
//varying vec2 newCoords;
//varying vec4 myVertex;

//NEW VARS

uniform sampler2D tex0;
varying vec2 coords;
uniform sampler2D tex1;
uniform float amount;
varying vec2 newCoords;
varying vec4 myVertex;


uniform vec3 theLight;
varying vec2 normalCoords;

varying vec3 vert;

varying vec3 newLightPos;

//varying vec3 L;

varying vec3 myNormals;

//uniform sampler2D sky; SKY NOT IMPLEMENTED


vec4 selectiveDulling(vec4 rgb)
{
 vec2 clampedCoords = normalize(coords);//clamp(newCoords.y, 0.0, 1.0);
 //float clampedTest = texture2D(tex1, newCoords + vec2(0.0, amount)).r; // takes the y amount flux and moves the color with the wave. 
// clampedTest += texture2D(tex1, newCoords + vec2(amount, 0.0)).r;
float clampedTest = texture2D(tex1, newCoords);
clampedTest += texture2D(tex1, newCoords);

 vec4 waveHighlight = vec4(0.1, 0.1, 0.3,0.3); 
 //vec4 rbg = vec4(0.0,1.0,0.0,1.0);
 //vec4 final = waveHighlight; // some amount between 0 - 1

 vec4 final = mix(waveHighlight, rgb, clampedTest); // lerps between the lowlight of the wave and the wave highlight texture.
return final; // returns the mixed color.
}

void main()
{

vec3 norm = myNormals;

vec3 outColor = texture2D(tex0, normalCoords).rgb;// make vec4 to have transparency

	float shininess = 4.0;
//	vec3 L = normalize(gl_LightSource[0].position.xyz - vert);
//	vec3 L = normalize(theLight.xyz - vert);
	vec3 L = normalize(newLightPos.xyz - vert);
	vec3 E = normalize(-vert);
	vec3 R = normalize(-reflect(L,norm));
//	float dist = length(theLight.xyz - vert)*0.01;
//	float dist = length(gl_LightSource[0].position.xyz - vert)*0.01;
	float dist = length(newLightPos.xyz - vert)*0.01;
	
	//Calculate Diffuse  
	float diffuse = dot(norm, L);
	diffuse = clamp(diffuse, 0.0, 2.0);
	
	//Calculate Specular
	float spec = pow(max(dot(R, E), 0.0), shininess);
	      
	//Calculate Ambient  
	float ambient = dot(norm, E);
	ambient = ambient*0.5 + (1.0-ambient)*0.5;
	
	//Calculate Attenuation
	float attenuation = 1.0/(1.0 + dist*0.0 + (dist*dist)*0.0);
	//float attenuation = 1.0/(1.0 + dist*amount + (dist*dist)*0.0); // SIMULATES LIGHTNING!

	//Calculate Edge Glow
	float edge = pow(max(dot(norm, normalize(vert))+1.0, 0.0), 2.0);


//NEW CODE
	//float diffuse = dot(normalize(gl_LightSource[0].position.xyz), normalize(norm));
	//float diffuse = dot(normalize(lightDir), normalize(norm));


	 // texture that goes onto the water.
	//vec4 frag = texture2D(sky, coords) * vec4(1.5,1.5,1.5,1.0); // vector brings the sky down to a decent level

	vec3 output = vec3(0.0,0.0,0.0);

	output = vec3(ambient, ambient, ambient);

	output = vec3(0.0, 0.0, 0.0);
	output += vec3(ambient, ambient, ambient)*gl_LightSource[0].ambient.rgb* attenuation;
	output += gl_LightSource[0].diffuse.rgb  * diffuse * attenuation;
//	output += gl_LightSource[0].specular.rgb * spec * attenuation;
	output += vec3(0.6,0.4,0.0) * spec * attenuation; // sun lighting.

	//vec3 outspec = gl_LightSource[0].specular.rgb * spec;// * attenuation;
	//outspec  = outspec * vec3(1.0,0.6,0.0);
	output = output*outColor+(vec3(spec,spec,spec) * vec3(0.8,0.5,0.0));
	
	//Set up transparency for outColor (texture)
	//outColor.rgb = outColor.bgr;
	//outColor.a = 0.6;


	//Combine lighting with texture
	//output = output*color0+vec3(spec,spec,spec);
	//output = output*0.5+vec3(spec,spec,spec);
	
	//Lets add fog
//	dist = length(vert)*0.01;
//	attenuation = 1.0/(1.0 + dist*0.001 + (dist*dist)*0.02);
//	output = vec3(0.2, 0.3, 0.4)*(1.0-attenuation) + output*attenuation;



	//OLD OUTPUTS


	vec4 finalAddition = selectiveDulling(vec4(outColor,0.5));
	//gl_FragColor = outColor + frag;
	//frag.a = 0.5;
	//finalAddition.a = 0.6;
//	gl_FragColor = vec4(norm,1.0f);
	gl_FragColor = finalAddition + vec4(output,0.4);
//	gl_FragColor = vec4(output,1.0) * finalAddition;//+ vec4(outspec,1.0);

//	float colorSign = sin(dist * 0.01);
//	gl_FragColor = vec4(colorSign,colorSign,colorSign,1.0);

//	gl_FragColor = vec4(myNormals, 1.0);
}