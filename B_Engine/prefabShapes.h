#ifndef B_PREFABSHAPES_H
#define B_PREFABSHAPES_H

#include "B_Mat4.h"

class B_prefabShapes
{
public:
	B_prefabShapes();
	~B_prefabShapes();


	struct cube
	{
	public:
		cube();
		~cube();

		void initCube();
		void drawCube();

	private:
		float * cubeVerts;
		float * cubeNormals;
		float * cubeUVs;
//		B_Mat4 cubeMat;

	};

	struct triangleFan_5ts
	{
	public:
		triangleFan_5ts();
		~triangleFan_5ts();

		void initFan();
		void drawFan();

	private:
		float * fanVerts;
		float * fanNormals;
		float * fanUVs;

	}; 


	struct sphere
	{
	public:
		sphere();
		~sphere();

		void initSphere();
		void drawSphere();

	private:
		float * sphereVerts;
		float * sphereNormals;
		float * sphereUVs;
	//		B_Mat4 sphereMat;

	};


};

#endif