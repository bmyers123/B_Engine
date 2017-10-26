#ifndef _B_WORLD_H
#define _B_WORLD_H

#include "B_Vec2.h"
#include "Shader.h"

#include <vector>

class tile 
{
public:

	tile();
	~tile();

	/*		SET & GET FUNCTIONS		*/

	void setCollidable(bool collide);

	void setTileDimensions(float width, float height);
	b_math::b_vectors::B_Vec2 getTileDimensions();

	void setTilePosition(float x, float y);
	b_math::b_vectors::B_Vec2 getTilePosition();

	void setTileCenter(float x, float y);
	b_math::b_vectors::B_Vec2 getTileCenter();

	/*		VBO Functions and Variables		*/
	void initializeShader();
	void initializeVBO();

	/*		Draw This Tile		*/
	void drawThisTile();

	void setUpVBO();
	void initializeTriangleVerts();
	void initializeTriangleUVs();
	void initializeTriangleNormals();
	void addVerts(float *rawVerts);
	void addUVs(float *rawUVs);
	void addNormals(float *rawNormals);
	void activateVBO();
	void renderVBO();
	void deactivateVBO();

	unsigned int objID, numVerts, halfVerts;
	unsigned int vertexHandle, normalHandle, uvHandle;



	/*		VARIABLES		*/

	//Rendering Variables
	float triOneVerts[6];//verts 1, 2, 3
	float triTwoVerts[6];//verts 4, 5, 6
	//
	float triOneUVs[6];//uvs 1, 2, 3
	float triTwoUVs[6];//uvs 4, 5, 6
	//
	float triOneNormals[9];//Not the correct size atm, also not currently being used
	float triTwoNormals[9];
	//

	/*		Objects used by each tile		*/
	Shader ptTileShader;
	//
	//Dimensional Variables
	b_math::b_vectors::B_Vec2 tileDimensions; //tileWidth = x, tileHeight = y;
	//
	//Positional Variables
	b_math::b_vectors::B_Vec2 tileCenter;
	b_math::b_vectors::B_Vec2 tilePos;

	bool collidable;

};

class B_2DWorld
{
public:

	B_2DWorld(void);
	~B_2DWorld(void);

	void createWorldGrid(b_math::b_vectors::B_Vec2 worldSize, b_math::b_vectors::B_Vec2 worldPos, b_math::b_vectors::B_Vec2 numberOfTiles);

	/*		SET & GET FUNCTIONS		*/

	void setWorldDimension(b_math::b_vectors::B_Vec2 worldSize);
	b_math::b_vectors::B_Vec2 getWorldDimension();

	void setWorldPosition(b_math::b_vectors::B_Vec2 worldPosition);
	b_math::b_vectors::B_Vec2 getWorldPosition();

	void setWorldCenter(b_math::b_vectors::B_Vec2 worldMiddle);
	b_math::b_vectors::B_Vec2 getWorldCenter();

	void drawTiles();
	void drawTilesImmediate();

	/*		VARIABLES & STATES		*/

	enum tileDrawStates : int {drawLeft = 1, drawRight = 2, drawBoth = 3};

	b_math::b_vectors::B_Vec2 worldDimensions; //worldWidth = x, worldHeight = y;
	b_math::b_vectors::B_Vec2 worldPos;
	b_math::b_vectors::B_Vec2 worldCenter;
	b_math::b_vectors::B_Vec2 numTiles;	


//private:

	/*static B_2DWorld *worldTA;*/
	tile *tileAccessor;


	std::vector<std::vector<tile*>> tileGrid;
	std::vector<tile*> tempRow;// = new std::vector<tile>();

	//static std::vector<tile> tempRow;
};

#endif
