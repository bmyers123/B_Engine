
#version 120

varying vec2 passTexcoord;

uniform sampler2D sceneImg0;
uniform sampler2D postProcImg;


vec3 add(sampler2D img0,sampler2D img1, vec2 uv)
{
	vec3 color0 = texture2D(img0, uv).rgb;
	vec3 color1 = texture2D(img1, uv).rgb;
	return (color0 + color1);
}

vec3 multiply(sampler2D img0, sampler2D img1, vec2 uv)
{
	vec3 color0 = texture2D(img0, uv).rgb;
	vec3 color1 = texture2D(img1, uv).rgb;
	return (color0 * color1);	
}

vec3 screen(sampler2D img0,sampler2D img1, vec2 uv)
{
	vec3 color0 = texture2D(img0, uv).rgb;
	vec3 color1 = texture2D(img1, uv).rgb;
	vec3 product = (1.0-color0)*(1.0-color1);
//	return (color0 * color1);	
return 1.0-product;
}

void main()
{
	//fragColour.rgb = vec3(0.0, 0.0, 1.0);

//	fragColour.rgb = add(sceneImg0, postProcImg, passTexcoord);
//	fragColour.rgb = multiply(sceneImg0, postProcImg, passTexcoord);
vec3 colorMult = multiply(sceneImg0, postProcImg, passTexcoord);
	gl_FragColor.rgb = screen(sceneImg0, postProcImg, passTexcoord);
}