
#version 120

varying vec2 passTexcoord;

uniform sampler2D sceneImg;
uniform vec2 pixelSize;


vec3 boxBlur(sampler2D img, vec2 centerUV, vec2 pixel)
{
	//return texture(img, centerUV).rgb;

	vec2 offsetUV;

	vec4 totalSample = 1.0 * texture2D(img, centerUV);

	//bottom left

	offsetUV = -pixel;
	totalSample += 1.0* texture2D(img, centerUV + offsetUV);

	//bottom

	offsetUV.x = 0.0;
	totalSample += 1.0* texture2D(img, centerUV + offsetUV);
	//bottom right

	offsetUV.x = pixel.x;
	totalSample += 1.0* texture2D(img, centerUV + offsetUV);
	//right
	offsetUV.y = 0.0; 
	totalSample += 1.0* texture2D(img, centerUV + offsetUV);
	//left
	offsetUV.x = -pixel.x;
	totalSample += 1.0* texture2D(img, centerUV + offsetUV);
	//top left
	offsetUV.y = +pixel.y;
	totalSample += 1.0* texture2D(img, centerUV + offsetUV);
	//top
	offsetUV.x = 0.0;
	totalSample += 1.0* texture2D(img, centerUV + offsetUV);
	//top right
	offsetUV.x = pixel.x;
	totalSample += 1.0* texture2D(img, centerUV + offsetUV);

	//average
	totalSample /=10.0; // normal would be totalSample /= 9.0;

	return totalSample.rgb;
}


vec3 OneDboxBlur(sampler2D img, vec2 centerUV, vec2 pixel)
{

	//THIS BLUR WILL DO X
	//return texture(img, centerUV).rgb;
	//| 0.006 | 0.061 | 0.242 | 0.383 | 0.242 | 0.061 | 0.006 |

	float offsetUV = 0.0;

	vec4 totalSample = 1.0 * texture2D(img, centerUV);

	//2nd left

	offsetUV -= (pixel.x * 2.0);
	totalSample += 1.0* texture2D(img, centerUV + offsetUV);

	//1st left
	offsetUV = 0.0;
	offsetUV -= pixel.x;
	totalSample += 1.0* texture2D(img, centerUV + offsetUV);

	//1st right
	offsetUV = 0.0;
	offsetUV += pixel.x;
	totalSample += 1.0* texture2D(img, centerUV + offsetUV);
	//2nd right
	offsetUV = 0.0;
	offsetUV += 2.0 * pixel.x;
	totalSample += 1.0* texture2D(img, centerUV + offsetUV);



	////left
	//offsetUV.x = -pixel.x;
	//totalSample += 1.0* texture2D(img, centerUV + offsetUV);
	////top left
	//offsetUV.y = +pixel.y;
	//totalSample += 1.0* texture2D(img, centerUV + offsetUV);
	////top
	//offsetUV.x = 0.0;
	//totalSample += 1.0* texture2D(img, centerUV + offsetUV);
	////top right
	//offsetUV.x = pixel.x;
	//totalSample += 1.0* texture2D(img, centerUV + offsetUV);

	//average
	totalSample /=5.0; // normal would be totalSample /= 9.0;

	return totalSample.rgb;
}

void main()
{
	//fragColour.rgb = vec3(0.0, 1.0, 0.0);
//	gl_FragColor.rgb = boxBlur(sceneImg, passTexcoord, pixelSize);
	gl_FragColor.rgb = OneDboxBlur(sceneImg, passTexcoord, pixelSize);
}