#version 120
	
	//OLD VARS

	//uniform sampler2D tex1;

	//varying vec2 coords;
	//uniform float amount;
	//varying vec2 newCoords;

	//varying vec4 myVertex;

	//vec3 frag;


	//NEW VARS
		
	uniform sampler2D tex1;
	//uniform sampler2D sky; sky not implemented yet

	varying vec2 coords;
	uniform float amount;
	varying vec2 newCoords;

	uniform vec3 theLight;

	varying vec3 vert;

	varying vec3 newLightPos;

	uniform vec4 pixelSize;

	varying vec4 myVertex;

	varying vec3 myNormals;

	varying vec2 normalCoords;



	vec3 frag;

	float height = 100.0;

	



void main()
{

//float pixel = 1.0 /(pixelSize.x);
float pixel = 1.0 /128;
//OLD CODE
	//coords = gl_MultiTexCoord0.xy * 0.05;

	//newCoords = coords*5.0; // 5.0 is the correct amount that I want.

	//myVertex = gl_Vertex;
	//myVertex.y = texture2D(tex1, newCoords + vec2(amount, 0.0)).r * 100.0;
	//myVertex.y += texture2D(tex1, newCoords + vec2(0.0, amount)).r * 100.0;

	//gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * myVertex;


//NEW CODE

	newLightPos = theLight.xyz;// WHEN IMPLEMENTED LIGHT
//	newLightPos = vec3(9000.0,1000.0,9000.0);

	//lightDir = normalize(vec3(1.0,-1.0,1.0));
	coords = gl_MultiTexCoord0.xy * 2.0; //Texcoord * 2.0

	//normalCoords = gl_MultiTexCoord0.xy * 0.05;

	vec3 myNormx = vec3(0.0,0.0,0.0);
	vec3 myNormz = vec3(0.0,0.0,0.0);

	newCoords = coords * 0.2; // *0.2 is the correct amount that I want.
	newCoords += amount;

	myVertex = gl_Vertex;
	//myVertex.y = texture2D(tex1, newCoords + vec2(amount, 0.0)).r * height;
	//myVertex.y += texture2D(tex1, newCoords + vec2(0.0, amount)).r * height;
	myVertex.y = texture2D(tex1, newCoords).r * height;
	myVertex.y += texture2D(tex1, newCoords).r * height;

//	myNormx = gl_Normal;
	myNormx.x = 30.0;//+ vec2(amount, 0.0)  + vec2(0.0,amount )
	myNormx.y =  texture2D(tex1, newCoords + vec2(pixel,0.0)).r * height;
	myNormx.y -=  texture2D(tex1, newCoords - vec2(pixel,0.0)).r * height;
	myNormx = normalize(myNormx);

//	myNormz = gl_Normal;
	myNormz.z = 30.0;//+ vec2(amount,0.0)  + vec2(0.0, amount)
	myNormz.y =  texture2D(tex1, newCoords + vec2(0.0,pixel)).r * height;
	myNormz.y -=  texture2D(tex1, newCoords - vec2(0.0,pixel)).r * height;
	myNormz = normalize(myNormz);


//myNormals = gl_Normal;
	myNormals = normalize(cross(myNormz, myNormx));
	myNormals = normalize(gl_NormalMatrix * myNormals);
	//myNormals = normalize(myNormals);

	//myNormals = vec3(1.0f, 1.0f, 1.0f);

	vert = (gl_ModelViewMatrix * myVertex).xyz;
	newLightPos = (gl_ModelViewMatrix * vec4(newLightPos, myVertex.w)).xyz;

	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * myVertex;	
} 