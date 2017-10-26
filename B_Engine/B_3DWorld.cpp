#include "Engine.h"

B_3DWorld::B_3DWorld(void)
{
	worldObj = new ObjLoader();
	worldMat = new B_Mat3();
	worldShader = new Shader();
	//worldTexture = new sf::Image();
}


B_3DWorld::~B_3DWorld(void)
{
	delete worldObj;
	delete worldMat;
}

void B_3DWorld::load3Dworld(const char *filename, char *vertFile, char *fragFile, bool debug, const char *imgFilename)
{
	load3DWorldObject(filename);
	load3DWorldShader(vertFile, fragFile, debug);
	load3DWorldImage(imgFilename);
}

void B_3DWorld::load3DWorldObject(const char *filename)
{
	worldObj->loadObj(filename);
}

void B_3DWorld::load3DWorldShader(char *vertFile, char *fragFile, bool debug)
{
	worldShader->Load(vertFile, fragFile, debug);
}

void B_3DWorld::load3DWorldImage(const char *imgFilename)
{
	//Load Image from file location
	if(!worldTexture.loadFromFile(imgFilename))
	{
		printf("Boat's Wood Texture Failed to Load");
	}
	else
	{
		//Always flip because openGL loads them incorrectly/upside-down
		worldTexture.flipVertically();
	}
	
	//Generate the texture ID
	glGenTextures(1, &worldImgNum);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, worldImgNum);
	
	//Make it a mipmap //ERROR - UNRESOLVED EXTERNAL BS....
	/*gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA,
	worldTexture.getSize().x, worldTexture.getSize().y,
	GL_RGBA, GL_UNSIGNED_BYTE, worldTexture.getPixelsPtr());*/

	//Same Thing?? (Not sure, but no given error atm)
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, worldTexture.getSize().x, worldTexture.getSize().y, 0, GL_RGB,  GL_UNSIGNED_BYTE, worldTexture.getPixelsPtr());

	//Set texture parameters (default)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//Unbind so that it doesn't show up on every object
	glBindTexture(GL_TEXTURE_2D, 0);
}

void B_3DWorld::render3DWorld()//INCOMPLETE -> No VBO activates/renders and no shader attached
{
	glPushMatrix();

	//Activate the Shader
	worldShader->Activate();

	//Activate VB)
	worldObj->activateVBO();

	//Enable states for verts/textures/normals/colors
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//Send vert/normal/texture/color data through pipeline to shader
	glVertexPointer(3, GL_FLOAT, 0, &worldObj->vertData[0]);
	glNormalPointer(GL_FLOAT, 0, &worldObj->normalData[0]);
	glTexCoordPointer(2, GL_FLOAT, 0, &worldObj->uvData[0]);
	glColorPointer(3, GL_FLOAT, 0, &worldObj->normalData[0]);

	//// Disable normal and color vertex components
	//glDisableClientState(GL_COLOR_ARRAY);
	////glDisableClientState(GL_NORMAL_ARRAY);

	//Pass image number to shader with name of image to be used inside the shader (ie - worldImg)
	worldShader->SetImage(worldImgNum, "worldImg", 0);
	
	/* Any Tranformations/Updates go here for the object */

	//Render VBO
	worldObj->renderVBO();

	//Deactivate VBO
	worldObj->deactivateVBO();

	//Deactivate the Shader	
	worldShader->Deactivate();

	glPopMatrix();

}