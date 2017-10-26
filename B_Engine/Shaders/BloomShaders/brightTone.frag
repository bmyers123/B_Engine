
#version 120

varying vec2 passTexcoord;
uniform sampler2D sceneImg;
uniform float middleGrey;


float relativeLuminance(vec3 rgb) // grey scale
{
	return(0.2126*rgb.r + 0.7152*rgb.g + 0.0722*rgb.b);
}

vec3 brightPass(sampler2D img,vec2 uv, float middle)
{
	vec3 color = texture2D(img, uv).rgb;

	float lum = relativeLuminance(color);

	float bright = pow(lum, (middle/lum));

	return vec3(bright * color);
}

void main()
{
	vec3 color = texture2D(sceneImg,passTexcoord).rgb;
	//fragColour.rgb = vec3(1.0, 0.0, 0.0);
	//fragColour.rgb = vec3(relativeLuminance(color));
    gl_FragColor.rgb = brightPass(sceneImg, passTexcoord, middleGrey);
}