#include "Engine.h"

B_2DWorld::B_2DWorld(void)
{
	tileAccessor = new tile();
	worldDimensions = B_Vec2(0.0f, 0.0f);
	numTiles = B_Vec2(0.0f, 0.0f);
	worldCenter = B_Vec2(0.0f, 0.0f);
	worldPos = B_Vec2(0.0f, 0.0f);
}

tile::tile()
{
	tileCenter = B_Vec2(0.0f, 0.0f);
	tilePos = B_Vec2(0.0f, 0.0f);
	tileDimensions = B_Vec2(0.0f, 0.0f);
	collidable = false;
	numVerts = 12;
	halfVerts = 6;
	objID = numVerts = halfVerts = vertexHandle = normalHandle = uvHandle = 0;
}

tile::~tile()
{
	tileCenter = B_Vec2(0.0f, 0.0f);
	tilePos = B_Vec2(0.0f, 0.0f);
	tileDimensions = B_Vec2(0.0f, 0.0f);
	collidable = false;

	//Add VBO stuff to release

}


B_2DWorld::~B_2DWorld(void)
{
}

/*		SET & GET FUNCTIONS FOR WORLD		*/
void B_2DWorld::setWorldPosition(B_Vec2 worldPosition)
{
	worldPos = worldPosition;
}

void B_2DWorld::setWorldCenter(B_Vec2 worldMiddle)
{
	worldCenter = worldMiddle;
}

void B_2DWorld::setWorldDimension(B_Vec2 worldSize)
{
	worldDimensions = worldSize;
}

B_Vec2 B_2DWorld::getWorldPosition()
{
	return worldPos;
}

B_Vec2 B_2DWorld::getWorldCenter()
{
	return worldCenter;
}

B_Vec2 B_2DWorld::getWorldDimension()
{
	return worldDimensions;
}

/*		SET & GET FUNCTIONS FOR TILES		*/
void tile::setTilePosition(float x, float y)
{
	tilePos.x = x;
	tilePos.y = y;
}

void tile::setTileCenter(float x, float y)
{
	tileCenter.x = x;
	tileCenter.y = y;
}

void tile::setTileDimensions(float width, float height)
{
	tileDimensions.x = width;
	tileDimensions.y = height;
}

B_Vec2 tile::getTilePosition()
{
	return tilePos;
}

B_Vec2 tile::getTileCenter()
{
	return tileCenter;
}

B_Vec2 tile::getTileDimensions()
{
	return tileDimensions;
}

//Creation of World Grid
void B_2DWorld::createWorldGrid(B_Vec2 worldSize, B_Vec2 worldPos, B_Vec2 numberOfTiles)
{
	setWorldDimension(worldSize);
	setWorldPosition(worldPos);
	setWorldCenter(worldSize/2);

	//tileAccessor.setTileDimensions(worldSize.x);
	numTiles = numberOfTiles;


	for(unsigned int i = 0; i < numTiles.y; i ++)
	{

		for(unsigned int j = 0; j < numTiles.x; j ++)
		{
			//Create new tile;
			tile *tempTile = new tile();
			//
			//Set each tile's Dimensions based upon the given information
			tempTile->setTileDimensions(worldDimensions.x / numTiles.x, worldDimensions.y / numTiles.y);
			//
			//Set each tile's Center based upon given information
			tempTile->setTileCenter(		 ( (worldDimensions.x / numTiles.x) /2.0f) + ((worldDimensions.x / numTiles.x) * j),  ( (worldDimensions.y / numTiles.y) /2.0f ) + ((worldDimensions.y / numTiles.y) * i));
			//
			//Set each tile's position based upon given information
			tempTile->setTilePosition((worldDimensions.x / numTiles.x) * j, (worldDimensions.y / numTiles.y) * i);
			//			
			//Initialize the vertices/UVs for each tile based on their positions (set above)
			tempTile->initializeTriangleVerts();
			tempTile->initializeTriangleUVs();
			//
			//Initialize each tile's Shader (ie load the shader in for each tile so that it can be drawn)
			tempTile->initializeShader();
			//
			//Use the verts to initialize a vbo for each tile
			tempTile->initializeVBO();
			//
			//Add this tile to the current row
			tempRow.push_back(tempTile);
			//
		}

		tileGrid.push_back(tempRow);

		tempRow.clear();
		//delete tempRow;
	}


	std::cout << " Grid Initialized " << std::endl;

}


void tile::initializeShader()
{
	ptTileShader.Load("Shaders/passthru_v_fragmentshader.vert", "Shaders/passthru_f_fragmentshader.frag", true);
}

void tile::initializeVBO()
{
	initializeTriangleVerts();
	setUpVBO();
	addVerts(triOneVerts);
	addVerts(triTwoVerts);
	addUVs(triOneUVs);
	addUVs(triTwoUVs);
	addNormals(triOneNormals);
	addNormals(triTwoNormals);
}

void tile::drawThisTile()
{
	//glPushMatrix();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//	glEnableClientState(GL_NORMAL_ARRAY);
//	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(2, GL_FLOAT, 0, &triOneVerts[0]);
	glVertexPointer(2, GL_FLOAT, 0, &triTwoVerts[0]);
	glTexCoordPointer(2, GL_FLOAT, 0, &triOneUVs[0]);
	glTexCoordPointer(2, GL_FLOAT, 0, &triTwoUVs[0]);
	glNormalPointer(GL_FLOAT, 0, &triOneNormals[0]);
	glNormalPointer(GL_FLOAT, 0, &triTwoNormals[0]);

	//glColorPointer(3, GL_FLOAT, 0, &hMapNorms[0]);

	// Disable normal and color vertex components
	glDisableClientState(GL_COLOR_ARRAY);
	//glDisableClientState(GL_NORMAL_ARRAY);

	//Activate shader
	ptTileShader.Activate();

	//set all images, floats, vecs, etc

	//draw elements for meshes and such

	//Deactivate Shader
	ptTileShader.Deactivate();

	//glPopMatrix();


}

void B_2DWorld::drawTiles()
{
	for(unsigned int i = 0; i < numTiles.y; i++)
	{
		for(unsigned int j = 0; j < numTiles.x; j++)
		{
			tileGrid[i][j]->initializeShader();
			tileGrid[i][j]->initializeVBO();
			tileGrid[i][j]->drawThisTile();
		}
	}

	std::cout << "All tiles drawn." << std::endl;
}

void tile::setUpVBO()
{
		//Generate Vertex Arra Object
		glGenVertexArrays(1, &objID);
		glBindVertexArray(objID);

		//Generate Empty buffer for each attribute
		//Vertices
		glGenBuffers(1, &vertexHandle);
		glBindBuffer(GL_ARRAY_BUFFER, vertexHandle);
		const unsigned int vertexBufferSize = numVerts * sizeof(float) * 2;
		glBufferData(GL_ARRAY_BUFFER, vertexBufferSize, 0, GL_STATIC_DRAW);
	//	glBufferSubData(GL_ARRAY_BUFFER, 0, vertexBufferSize, &temp_Verts[0]);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		//Texture Coordinates
		glGenBuffers(1, &uvHandle);
		glBindBuffer(GL_ARRAY_BUFFER, uvHandle);
		const unsigned int uvBufferSize = numVerts * sizeof(float) * 2;
		glBufferData(GL_ARRAY_BUFFER, uvBufferSize, 0, GL_STATIC_DRAW);
	//	glBufferSubData(GL_ARRAY_BUFFER, 0, uvBufferSize, &temp_UVs[0]);
		glEnableVertexAttribArray(8);
		glVertexAttribPointer(8, 2, GL_FLOAT, GL_FALSE, 0, 0);
		
		//Normals
		glGenBuffers(1, &normalHandle);
		glBindBuffer(GL_ARRAY_BUFFER, normalHandle);
		const unsigned int normalBufferSize = vertexBufferSize;
		glBufferData(GL_ARRAY_BUFFER, normalBufferSize, 0, GL_STATIC_DRAW);
	//	glBufferSubData(GL_ARRAY_BUFFER, 0, normalBufferSize, &temp_Normals[0]);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);


		glBindVertexArray(0); //Turns off state machine
		glBindBuffer(GL_ARRAY_BUFFER, 0); //Turns of states
		//Has no effect on current states becaus you disable the state changing maching before changing the states themselves.

}

void tile::addVerts(float *rawVerts)
{
	const unsigned int bufferSize =	numVerts * sizeof(float) * 2;//Set Buffer size
	glBindBuffer(GL_ARRAY_BUFFER, vertexHandle);//BIND
	glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, rawVerts);//glBufferData allocates space, glBufferSubData sets values in buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);//UNBIND
}

void tile::addUVs(float *rawUVs)
{
	const unsigned int bufferSize =	numVerts * sizeof(float) * 2;//Set Buffer size
	glBindBuffer(GL_ARRAY_BUFFER, uvHandle);//BIND
	glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, rawUVs);//glBufferData allocates space, glBufferSubData sets values in buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);//UNBIND
}

void tile::addNormals(float *rawNormals)
{
	const unsigned int bufferSize =	numVerts * sizeof(float) * 2;//Set Buffer size
	glBindBuffer(GL_ARRAY_BUFFER, normalHandle);//BIND
	glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, rawNormals);//glBufferData allocates space, glBufferSubData sets values in buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);//UNBIND
}

//Activate previously made VBOs
void tile::activateVBO()
{
	glBindVertexArray(objID);
}

//Render Activated VBOs
void tile::renderVBO()
{
	glDrawArrays(GL_TRIANGLES, 0, numVerts);//numVerts = vertsPerFace * numFaces
}

//Deactivate VBOs for efficiency/saving memory
void tile::deactivateVBO()
{
	glBindVertexArray(0);
}

void tile::initializeTriangleVerts()
{

	/*		Tile Triangle Number One Verts		*/

	triOneVerts[0] = tilePos.x;
	triOneVerts[1] = tilePos.y;

	triOneVerts[2] = tilePos.x;
	triOneVerts[3] = tilePos.y + tileDimensions.y;

	triOneVerts[4] = tilePos.x + tileDimensions.x;
	triOneVerts[5] = tilePos.y + tileDimensions.y;


	/*		Tile Triangle Number Two Verts		*/

	triTwoVerts[0] = tilePos.x;
	triTwoVerts[1] = tilePos.y;

	triTwoVerts[2] = tilePos.x + tileDimensions.x;
	triTwoVerts[3] = tilePos.y + tileDimensions.y;

	triTwoVerts[4] = tilePos.x + tileDimensions.x;
	triTwoVerts[5] = tilePos.y;

}

void tile::initializeTriangleUVs()
{
	triOneUVs[0] = 0.0f;
	triOneUVs[1] = 0.0f;

	triOneUVs[2] = 0.0f;
	triOneUVs[3] = 1.0f;

	triOneUVs[4] = 1.0f;
	triOneUVs[5] = 1.0f;


	triTwoUVs[0] = 0.0f;
	triTwoUVs[1] = 0.0f;

	triTwoUVs[2] = 1.0f;
	triTwoUVs[3] = 1.0f;

	triTwoUVs[4] = 1.0f;
	triTwoUVs[5] = 0.0f;


}

void tile::initializeTriangleNormals()
{
	//Triangle One 

	triOneNormals[0] = 0.0f;
	triOneNormals[1] = 0.0f;
	triOneNormals[2] = 1.0f;

	triOneNormals[3] = 0.0f;
	triOneNormals[4] = 0.0f;
	triOneNormals[5] = 1.0f;

	triOneNormals[6] = 0.0f;
	triOneNormals[7] = 0.0f;
	triOneNormals[8] = 1.0f;


	//Triangle Two

	triTwoNormals[0] = 0.0f;
	triTwoNormals[1] = 0.0f;
	triTwoNormals[2] = 1.0f;

	triTwoNormals[3] = 0.0f;
	triTwoNormals[4] = 0.0f;
	triTwoNormals[5] = 1.0f;

	triTwoNormals[6] = 0.0f;
	triTwoNormals[7] = 0.0f;
	triTwoNormals[8] = 1.0f;
}