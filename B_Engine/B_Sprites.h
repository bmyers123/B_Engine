#ifndef B_SPRITES_H
#define B_SPRITES_H

/*

Copyright Brayden Myers, 2014

This file and all incorporated classes are created for use in:
	-Sprite Loading
	-Sprite Rendering
	-Sprite Animation

*/

#include "Engine.h"

class B_XYcoordSystem
{
public:
	B_XYcoordSystem(float x, float y, float u, float v){ B_x = x; B_y = y; B_u = u; B_v = v; }
	~B_XYcoordSystem(void);

	float B_x, B_y;
	float B_u, B_v;

private:

};


class B_SpriteAnimations
{

public:

	B_SpriteAnimations(void){currentFrame=0; B_spriteLooping=true;}
	~B_SpriteAnimations(void);

	void B_setLoopingStatus(bool isLoop){B_spriteLooping = isLoop;}

	int numFrames;
	bool B_spriteLooping;

	void B_nextFrame();

	std::vector<B_XYcoordSystem*> B_animationCoords;
	int currentFrame;

};


typedef struct _B_SpriteSheetInfo
{
public:
	//std::string B_name;
	float B_height, B_width;

	//GLuint B_textureHandle;
	//sf::Image *B_spriteLoader;

}B_SpriteSheetInfo;


typedef struct _B_SpriteSize
{

	int height, width;
	int normalWidth, normalHeight;

}B_SpriteSize;


class B_Sprites
{

public:

	B_Sprites(void);
	~B_Sprites(void);

	void B_loadSpriteImage(const char* filename);
	void B_addSpriteAnimFrame(int animNumber, float x, float y);

	//void B_setSpriteTexture(GLuint texHandle);
	//void B_setSpriteSize(unsigned int texHandle);
	
	//Renders w/ VBO functions
	void B_renderSprite(B_Sprites spriteObj);
	void B_setupSpriteVBO();
	void B_addVerts();
	void B_addUVs();
	void B_activateSpriteVBO();
	void B_renderSpriteVBO();
	void B_deactivateSpriteVBO();
	//void B_addNormals();

	//void B_defaultTextureSettings(unsigned int texHandle);

	//Set Initial Status of Sprites
	void B_setFrameSize(B_Vec2 scale);
	void B_setSpritePosition(float x, float y){B_posX = x; B_posY = y;}
	void B_setSpriteCenter(float x, float y){B_centerX = x; B_centerY = y;}

	//Update Functions for Sprites that animate
	void B_updateSpritePos(B_Vec3 pos, float dt);
	void B_updateSpriteOrientation(float angle, float dt);
	void B_updateSpriteFrame();
	void B_updateSpriteSize();

//private:

	//Per Sprite Attribs.
	float B_spriteHeight, B_spriteWidth;
	float B_spriteOrientation;
	float B_posX, B_posY;
	float B_centerX, B_centerY;
	
	//VBO ints
	//GLuint B_spriteVBOID;
	//GLuint B_spriteVertID;
	//GLuint B_spriteUVID;

	//Sprite Sheet and Size types/objects
	B_SpriteSheetInfo B_spriteSheet;
	B_SpriteSize B_spriteSize;

	//List of animations
	std::vector<B_SpriteAnimations*> B_animationList;

};

#endif
