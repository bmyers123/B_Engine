
#version 120

varying vec2 passTexcoord;

uniform sampler2D sceneImg;
uniform float pixelSizeX;
uniform float pixelSizeY;



vec3 OneDGaussian(sampler2D img, vec2 centerUV, vec2 pixel)
{

	//THIS BLUR WILL DO X
	//return texture(img, centerUV).rgb;
	//| 0.006 | 0.061 | 0.242 | 0.383 | 0.242 | 0.061 | 0.006 |

	float offsetUV = 0.0;

	vec4 totalSample = 0.383 * texture2D(img, centerUV);

	//3rd right
	offsetUV += (pixel.x * 3.0);
	totalSample += 0.006 * texture2D(img, centerUV + offsetUV);

	//2nd right
	offsetUV = 0.0;
	offsetUV += (pixel.x * 2.0);
	totalSample += 0.061* texture2D(img, centerUV + offsetUV);

	//1st right
	offsetUV = 0.0;
	offsetUV += pixel.x;
	totalSample += 0.0242* texture2D(img, centerUV + offsetUV);

	//1st left
	offsetUV = 0.0;
	offsetUV -= pixel.x;
	totalSample += 0.242* texture2D(img, centerUV + offsetUV);
	//2nd left
	offsetUV = 0.0;
	offsetUV -= (2.0 * pixel.x); 
	totalSample += 0.061* texture2D(img, centerUV + offsetUV);
	//3rd left
	offsetUV = 0.0;
	offsetUV -= (3.0 * pixel.x);
	totalSample += 0.006* texture2D(img, centerUV + offsetUV);

	//average
	//totalSample /=2.0; // normal would be totalSample /= 9.0;
	
	return totalSample.rgb;
}

void main()
{

	vec2 pixelSize = vec2(pixelSizeX, pixelSizeY);
	
	gl_FragColor.rgb = OneDGaussian(sceneImg, passTexcoord, pixelSize);
}