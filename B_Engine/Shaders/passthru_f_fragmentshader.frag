
#version 120


//varying vec4 COLOUR;
varying vec2 texCoord;

varying vec4 position;
varying vec3 normals;

varying vec4 vert;

//uniform sampler2D woodTex;
//uniform sampler2D normalMap;


void main()
{

//vec3 normalMapVec = texture2D(normalMap, texCoord).rgb * 2 - 1;

	//vec4 texCol = texture2D(woodTex,texCoord);
	//gl_FragColor = COLOUR;

float shine = 20.0;

vec3 L = normalize(gl_LightSource[0].position.xyz - vert.xyz);
vec3 E = normalize(-vert.xyz);
vec3 R = normalize(-reflect(L,normals));

	 //calc diffuse
 float diffuse = dot(normals, L);
 diffuse = clamp(diffuse,0.0,1.0);

 // calc spec
 float spec = pow(max(dot(R,E),0.0),shine);

// calc ambience
 float ambient = dot(normals, E);
 ambient = ambient * 0.5 + (1.0 - ambient)*0.8;

// calc Attenu
//float attenuation = 1.0 / (1.0 + dist*0.001 + (dist*dist)*0.02);

 // calc magic glow
//float magic = pow(max(dot(normals, normalize(vert.xyz))+1.0,0.0),1.0);
//magic = magic * (sin(amount) *0.25+0.75);

 //diffuse = diffuse*0.5+0.5;

// //tune shader
//diffuse  = floor(diffuse*5.0)/5.0;

vec3 output = vec3(0.0,0.0,0.0);
output += vec3(ambient, ambient, ambient);
//output += gl_LightSource[0].diffuse.rgb * diffuse; //* attenuation;
//output += gl_LightSource[0].specular.rgb * spec;// * attenuation;
//output += vec3(magic,magic,magic);


//vec3 outspec = gl_LightSource[0].specular.rgb * spec;// * attenuation;
//vec3 colorTex = texture2D(woodTex, texCoord).rgb;


vec3 colour = vec3(1.0, 0.0, 0.0);

//output = output * colorTex + outspec;


 //gl_FragColor = vec4(output, 1.0);
 gl_FragColor = vec4(normals, 1.0);

//texCol = vec4(output, 1.0);
}
