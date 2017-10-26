#ifndef _B_3DWorld_H
#define _B_3DWorld_H

#include "ObjLoad.h"
#include "B_Vec3.h"
#include "Shader.h"
#include "B_Mat3.h"
#include <SFML\Graphics.hpp>
//#include <SFML\Window.hpp>
//#include <SFML\System.hpp>
//#include <SFML\OpenGL.hpp>

class B_3DWorld
{
public:
	B_3DWorld(void);
	~B_3DWorld(void);

	//Everything loaded at once.
	void load3Dworld(const char *filename, char *vertFile, char *fragFile, bool debug, const char *imgFilename);

	//sub loads that actually do the loading
	void load3DWorldObject(const char *filename);
	void load3DWorldShader(char *vertFile, char *fragFile, bool debug);
	void load3DWorldImage(const char *imgFilename);

	void render3DWorld();

	void translate3DWorldObject(ObjLoader &obj);
	void rotate3DWorldObject(ObjLoader &obj);
	void scale3DWorldObject(B_Vec3 axis, float angle);

private:

	ObjLoader *worldObj;
	Shader *worldShader;
	B_Mat3 *worldMat;
	sf::Image worldTexture;
	unsigned int worldImgNum;
};

#endif