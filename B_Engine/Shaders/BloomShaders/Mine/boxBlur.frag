#version 120

in vec2 texCoord;

/////////PASS THESE IN/////////
uniform sampler2D bbSceneImg;
uniform vec2 pixelSize;
///////////////////////////////

uniform float heightRatio;
uniform float widthRatio;

//varying out vec4 fragColour;


vec3 boxBlur(in sampler2D img, in vec2 centerUV, in vec2 pixel)
{	
	//return texture(img, centerUV).rgb;

	vec2 offsetUV;

	vec4 totalSample = 1.0 * texture2D(img, centerUV);


	//bottom left
	offsetUV = -pixel;
	totalSample += 1.0*texture2D(img, centerUV + offsetUV);

	//Bottom middle
	offsetUV.x = 0.0;
	totalSample += 0.0 * texture2D(img, centerUV + offsetUV);

	//Bottom Right
	offsetUV.x = +pixel.x;
	totalSample += 1.0 * texture2D(img, centerUV + offsetUV);

	//Middle Right
	offsetUV.y = 0.0;
	totalSample += 2.0 * texture2D(img, centerUV + offsetUV);

	//Middle Left
	offsetUV.x = -pixel.x;
	totalSample += 2.0 * texture2D(img, centerUV + offsetUV);

	//Top Left
	offsetUV.y = +pixel.y;
	totalSample += 1.0 * texture2D(img, centerUV + offsetUV);

	//Top Middle
	offsetUV.x = 0.0;
	totalSample += 0.0 * texture2D(img, centerUV + offsetUV);

	//Top Right
	offsetUV.x = +pixel.x;
	totalSample += 1.0 * texture2D(img, centerUV + offsetUV);

	//average
	totalSample /= 9.0;

	return totalSample.rgb;

}




void main()
{
	//fragColour.rgb = vec3(0.0, 1.0, 0.0);

	//fragColour.rgb = boxBlur(sceneImg, texCoord, pixelSize);
	gl_FragColor.rgb = boxBlur(bbSceneImg, texCoord, pixelSize);

}