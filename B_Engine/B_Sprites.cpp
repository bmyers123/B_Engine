#include "Engine.h"

B_Sprites::B_Sprites(void)
{

	B_spriteSheet.B_height = 0;
	B_spriteSheet.B_width = 0;

}

B_Sprites::~B_Sprites(void)
{}

//void B_Sprites::B_loadSpriteImage(const char* filename)
//{
//
//	B_spriteSheet.B_spriteLoader->loadFromFile(filename);
//
//	glGenTextures(1, &B_spriteSheet.B_textureHandle);
//	glBindTexture(GL_TEXTURE_2D, B_spriteSheet.B_textureHandle);
//
//	B_defaultTextureSettings(B_spriteSheet.B_textureHandle);
//
//}

//void B_Sprites::B_defaultTextureSettings(unsigned int textureHandle)
//{
//	glBindTexture(GL_TEXTURE_2D, textureHandle);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glBindTexture(GL_TEXTURE_2D, 0);
//}

void B_SpriteAnimations::B_nextFrame()
{
		int numFrames = B_animationCoords.size();
		currentFrame++;
		if(currentFrame >= numFrames)
		{
			if(B_spriteLooping) currentFrame = 0;
			else currentFrame = numFrames - 1;
		}
}

void B_Sprites::B_addSpriteAnimFrame(int animNumber, float x, float y)
{

	float u, v;

	u = (float)x/B_spriteSheet.B_width;
	v = (float)y/B_spriteSheet.B_height;

	B_XYcoordSystem *xy = new B_XYcoordSystem(x, y, u, v);

	B_animationList[animNumber]->B_animationCoords.push_back(xy);

}

/////////////////////////////////////////////////////////////////

////	Render
//void B_Sprites::B_renderSprite(B_Sprites spriteObj)
//{
//	//Activate Sprite's VBO
//	spriteObj.B_renderSpriteVBO();
//
//	//glTranslatef(spriteObj.B_posX, spriteObj.B_posY, 0);
//	//glScalef(spriteObj.B_spriteSize.width, spriteObj.B_spriteSize.height, 0); 
//
//	glBindTexture(GL_TEXTURE_2D, spriteObj.B_spriteSheet.B_textureHandle);
//	//Render Sprite
//	spriteObj.B_renderSpriteVBO();
//
//	//Deactivate Sprite's VBO
//	spriteObj.B_deactivateSpriteVBO();
//
//}

//	Sub Renders
//void B_Sprites::B_activateSpriteVBO()
//{
//	glBindVertexArray(B_spriteVBOID);
//}

//void B_Sprites::B_renderSpriteVBO()
//{
//	glDrawArrays(GL_TRIANGLES, 0, 6);//numVerts = vertsPerFace * numFaces	
//}

//void B_Sprites::B_deactivateSpriteVBO()
//{
//	glBindVertexArray(0);	
//}
//	End sub Renders

/////////////////////////////////////////////////////////////////

////	Sprite VBO Setup
//void B_Sprites::B_setupSpriteVBO()
//{
//		glGenVertexArrays(1, &B_spriteVBOID);
//		glBindVertexArray(B_spriteVBOID);
//
//		//Generate Empty buffer for each attribute
//		//Vertices
//		glGenBuffers(1, &B_spriteVertID);
//		glBindBuffer(GL_ARRAY_BUFFER, B_spriteVertID);
//		const unsigned int vertexBufferSize = 12 * sizeof(float) * 3;
//		glBufferData(GL_ARRAY_BUFFER, vertexBufferSize, 0, GL_STATIC_DRAW);
//	//	glBufferSubData(GL_ARRAY_BUFFER, 0, vertexBufferSize, &temp_Verts[0]);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//
//		//Texture Coordinates
//		glGenBuffers(1, &B_spriteUVID);
//		glBindBuffer(GL_ARRAY_BUFFER, B_spriteUVID);
//		const unsigned int uvBufferSize = 12 * sizeof(float) * 2;
//		glBufferData(GL_ARRAY_BUFFER, uvBufferSize, 0, GL_STATIC_DRAW);
//	//	glBufferSubData(GL_ARRAY_BUFFER, 0, uvBufferSize, &temp_UVs[0]);
//		glEnableVertexAttribArray(8);
//		glVertexAttribPointer(8, 2, GL_FLOAT, GL_FALSE, 0, 0);
//		
//		//Normals
//	//	glGenBuffers(1, &normalHandle);
//	//	glBindBuffer(GL_ARRAY_BUFFER, normalHandle);
//	//	const unsigned int normalBufferSize = vertexBufferSize;
//	//	glBufferData(GL_ARRAY_BUFFER, normalBufferSize, 0, GL_STATIC_DRAW);
//	////	glBufferSubData(GL_ARRAY_BUFFER, 0, normalBufferSize, &temp_Normals[0]);
//	//	glEnableVertexAttribArray(2);
//	//	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
//
//		glBindVertexArray(0); //Turns off state machine
//		glBindBuffer(GL_ARRAY_BUFFER, 0); //Turns of states
//		//Has no effect on current states becaus you disable the state changing maching before changing the states themselves.
//
//
//		B_addVerts();
//		B_addUVs();
//
//}

//	Sub VBO info
//void B_Sprites::B_addVerts()
//{
//
//	const float B_spriteVerts[12] = 
//	{
//		-1.0f, -1.0f,
//		 1.0f, -1.0f,
//		-1.0f,  1.0f,
//		-1.0f,  1.0f,
//		 1.0f, -1.0f,
//		 1.0f,  1.0f
//	};
//
//	const unsigned int bufferSize =	12 * sizeof(float) * 3;//Set Buffer size
//	glBindBuffer(GL_ARRAY_BUFFER, B_spriteVertID);//BIND
//	glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, &B_spriteVerts);//glBufferData allocates space, glBufferSubData sets values in buffer
//	glBindBuffer(GL_ARRAY_BUFFER, 0);//UNBIND
//
//}

//void B_Sprites::B_addUVs()
//{
//	
//	const float B_spriteTexCoords[12] =
//	{
//		0.0f, 0.0f, 
//		1.0f, 0.0f, 
//		0.0f, 1.0f, 
//		0.0f, 1.0f, 
//		1.0f, 0.0f, 
//		1.0f, 1.0f
//	};
//
//	const unsigned int bufferSize =	12 * sizeof(float) * 2;//Set Buffer size
//	glBindBuffer(GL_ARRAY_BUFFER, B_spriteUVID);//BIND
//	glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, &B_spriteTexCoords);//glBufferData allocates space, glBufferSubData sets values in buffer
//	glBindBuffer(GL_ARRAY_BUFFER, 0);//UNBIND
//}
//	End Sub VBO info

/////////////////////////////////////////////////////////////////