#version 120

varying vec2 texCoord;


////NEED TO PASS THESE IN////
uniform sampler2D btSceneImg;
uniform float btMiddleGrey;
////////////////////////////

//uniform float heightRatio;
//uniform float widthRatio;

//varying out vec4 fragColour;


float relativeLuminance(in vec3 rgb)
{
	return(0.21226*rgb.r + 0.7152*rgb.g + 0.0722*rgb.b);
}

vec3 brightPass(in sampler2D img, in vec2 uv, in float middle)
{
	vec3 colour = texture2D(img, uv).rgb;

	float lum = relativeLuminance(colour);

	float bright = pow(lum, (middle/lum));

	return vec3(bright * colour);

}

void main()
{
	//fragColour.rgb = vec3(1.0, 0.0, 0.0);
	//fragColour.rgb = texture(sceneImg, passTexcoord).rgb;


	vec3 colour = texture2D(btSceneImg, texCoord).rgb;

	//fragColour.rgb = vec3(relativeLuminance(colour));

	gl_FragColor.rgb = brightPass(btSceneImg, texCoord, btMiddleGrey);


}