#include "prefabShapes.h"


B_prefabShapes::B_prefabShapes()
{
}


B_prefabShapes::~B_prefabShapes()
{
}


B_prefabShapes::cube::cube()
{
	cubeVerts = 0;
	cubeNormals = 0;
	cubeUVs = 0;
}

B_prefabShapes::cube::~cube()
{
	delete cubeVerts;
	delete cubeNormals;
	delete cubeUVs;
}

void B_prefabShapes::cube::initCube()
{
	cubeVerts[108] =  -1, -1,  1,   -1,  1,  1,    1,  1,  1, //1
		               1,  1,  1,    1, -1,  1,   -1, -1,  1, //2
					  -1, -1, -1,   -1,  1, -1,   -1,  1,  1, //3
					  -1,  1,  1,   -1, -1,  1,   -1, -1, -1, //4
					  -1,  1,  1,   -1,  1, -1,    1,  1, -1, //5 
					   1,  1, -1,    1,  1,  1,   -1,  1,  1, //6
					   1, -1,  1,    1,  1,  1,    1,  1, -1, //7
					   1,  1, -1,    1, -1, -1,    1, -1,  1, //8
					   1, -1, -1,    1,  1, -1,   -1,  1, -1, //9 
					  -1,  1, -1,   -1, -1, -1,    1, -1, -1, //10 
					  -1, -1, -1,   -1, -1,  1,    1, -1,  1, //11 
					   1, -1,  1,    1, -1, -1,   -1, -1, -1; //12

	//cubeNormals[108] = 0;
	//cubeUVs[72] = 0;
	
}

void B_prefabShapes::cube::drawCube()
{
	initCube();

	//Create Vertex Buffer

	//Add verts, normals, UVs

	//Render Buffer

	//Delete?

}

B_prefabShapes::triangleFan_5ts::triangleFan_5ts()
{
	fanVerts = 0;
	fanNormals = 0;
	fanUVs = 0;
}

B_prefabShapes::triangleFan_5ts::~triangleFan_5ts()
{
	delete fanVerts;
	delete fanNormals;
	delete fanUVs;
}


void B_prefabShapes::triangleFan_5ts::initFan()
{
	fanVerts[30] = 0, -1,   -1,     -1,      -0.875, -0.75,
		           0, -1,   -0.875, -0.75,   -0.35,   0,
				   0, -1,   -0.25,   0,       0.25,   0, 
				   0, -1,    0.25,   0,       0.875, -0.75,
				   0, -1,    0.875, -0.75,    1,     -1;
	
	//fanNormals[30] = 0;
	fanUVs = fanVerts;
}

void B_prefabShapes::triangleFan_5ts::drawFan()
{
	initFan();

	//Create Vertex Buffer

	//Add verts, normals, UVs

	//Render Buffer

	//Delete?
}

B_prefabShapes::sphere::sphere()
{
	sphereVerts = 0;
	sphereNormals = 0;
	sphereUVs = 0;
}

B_prefabShapes::sphere::~sphere()
{
	delete sphereVerts;
	delete sphereNormals;
	delete sphereUVs;
}

void B_prefabShapes::sphere::initSphere()
{
	sphereVerts[108] = 0;
	sphereNormals[108] = 0;
	sphereUVs[72] = 0;
}

void B_prefabShapes::sphere::drawSphere()
{
	initSphere();

	//Create Vertex Buffer

	//Add verts, normals, UVs

	//Render Buffer

	//Delete?
}