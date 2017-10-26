#version 120

in vec2 texCoord;

/////////PASS THESE IN/////////
uniform sampler2D scSceneImg;
uniform sampler2D scPostProcImg;
///////////////////////////////

uniform float heightRatio;
uniform float widthRatio;


//varying out vec4 fragColour;


vec3 add(in sampler2D img0, in sampler2D img1, in vec2 uv)
{
	vec3 colour0 = texture2D(img0, uv).rgb;
	vec3 colour1 = texture2D(img1, uv).rgb;
	return (colour0 + colour1);
}

vec3 multiply(in sampler2D img0, in sampler2D img1, in vec2 uv)
{
	vec3 colour0 = texture2D(img0, uv).rgb;
	vec3 colour1 = texture2D(img1, uv).rgb;
	return (colour0 * colour1);
}

vec3  screen(in sampler2D img0, in sampler2D img1, in vec2 uv)
{
	vec3 colour0 = texture2D(img0, uv).rgb;
	vec3 colour1 = texture2D(img1, uv).rgb;

	vec3 product = (1.0 - colour0) * (1.0 - colour1);

	//return (colour0 * colour1);
	return 1.0 - product;
}

void main()
{
	//fragColour.rgb = vec3(0.0, 0.0, 1.0);

	//fragColour.rgb = add(sceneImg, postProcImg, passTexcoord);
	//fragColour.rgb = multiply(sceneImg, postProcImg, passTexcoord);


	//fragColour.rgb = screen(scSceneImg, scPostProcImg, texCoord);
	gl_FragColor.rgb = screen(scSceneImg, scPostProcImg, texCoord);
}