#include "B_VertexBufferObj.h"
#include "Engine.h"

B_VertexBufferObj::B_VertexBufferObj(void)
{
}


B_VertexBufferObj::~B_VertexBufferObj(void)
{
}

int B_VertexBufferObj::setUpVBO(unsigned int numVertices, bool useNormals, bool useTexcoords)
{
	
	if(!vaoHandle)
	{
		//Generate Vertex Arra Object
		glGenVertexArrays(1, &vaoHandle);
		glBindVertexArray(vaoHandle);

		//Generate Empty buffer for each attribute
		//Vertices
		glGenBuffers(1, &vertexHandle);
		glBindBuffer(GL_ARRAY_BUFFER, vertexHandle);
		const unsigned int vertexBufferSize = numVerts * sizeof(float) * 3;
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

	return 0;
}

int B_VertexBufferObj::addVerts(float *rawVerts)
{

//	numVerts = temp_Verts.size() - 1;

	const unsigned int bufferSize =	numVerts * sizeof(float) * 3;//Set Buffer size
	glBindBuffer(GL_ARRAY_BUFFER, vertexHandle);//BIND
	glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, rawVerts);//glBufferData allocates space, glBufferSubData sets values in buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);//UNBIND

	return 0;

}

int B_VertexBufferObj::addUVs(float *rawUVs)
{

//	numVerts = temp_Verts.size() - 1;

	const unsigned int bufferSize =	numVerts * sizeof(float) * 2;//Set Buffer size
	glBindBuffer(GL_ARRAY_BUFFER, uvHandle);//BIND
	glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, rawUVs);//glBufferData allocates space, glBufferSubData sets values in buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);//UNBIND

	return 0;

}

int B_VertexBufferObj::addNormals(float *rawNormals)
{

//	numVerts = temp_Verts.size() - 1;

	const unsigned int bufferSize =	numVerts * sizeof(float) * 3;//Set Buffer size
	glBindBuffer(GL_ARRAY_BUFFER, normalHandle);//BIND
	glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, rawNormals);//glBufferData allocates space, glBufferSubData sets values in buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);//UNBIND

	return 0;
}

//Activate previously made VBOs
void B_VertexBufferObj::activateVBO()
{
	glBindVertexArray(vaoHandle);
}

//Render Activated VBOs
void B_VertexBufferObj::renderVBO()
{
	glDrawArrays(GL_TRIANGLES, 0, numVerts);//numVerts = vertsPerFace * numFaces
}

//Deactivate VBOs for efficiency/saving memory
void B_VertexBufferObj::deactivateVBO()
{
	glBindVertexArray(0);
}