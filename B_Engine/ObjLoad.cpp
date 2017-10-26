//Brayden Myers 2013

#include "Engine.h"

using namespace b_graphics;
using namespace b_parsers;

ObjLoader::ObjLoader()
{
	temp_Verts.clear();
	temp_UVs.clear();
	temp_Normals.clear();
	numVerts = 0;
	vertexHandle = 0;
	uvHandle = 0;
	normalHandle = 0;
	position.x = position.y = position.z = 0.0f;
	rotation.x = rotation.y = rotation.z = 0.0f;
	uniformScale = 1.0f;

}

ObjLoader::~ObjLoader()
{
	//delete modelMat;
	Release();//tells opengl we are done with these VBO/VAOs
}

void ObjLoader::Release()
{
	if(objID)
	{
		glBindVertexArray(0);
		glDeleteVertexArrays(1, &objID);

		glDeleteBuffers(1, &vertexHandle);
		glDeleteBuffers(1, &uvHandle);
		glDeleteBuffers(1, &normalHandle);

		vertexHandle = 0;
		uvHandle = 0;
		normalHandle = 0;
	}

}

int ObjLoader::loadObj(const char* filename)
{

	std::ifstream objFile(filename);
	
	if(!objFile.is_open())
	{
		std::cout << "Object File was not successfuly opened";
		return -1;
	}

	char buffer[256];


	unsigned int numFaces = 0;


		while(!objFile.eof())
		{
			objFile.getline(buffer, 256);
			objcoords.push_back(new std::string(buffer));
		}

		for(unsigned int i = 0; i< objcoords.size(); i++)
		{
			if(objcoords[i]->c_str()[0] == '#')
					continue;

			// Looks to see if just v at the beginning -> means these are vertex coords
			else if(objcoords[i]->c_str()[0] == 'v' && objcoords[i]->c_str()[1] == ' ') 
			{
				b_math::b_vectors::B_Vec3 vertex;
				sscanf_s(objcoords[i]->c_str(), "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);
			//	temp_Verts.push_back(vertex.x);
			//	temp_Verts.push_back(vertex.y);
			//	temp_Verts.push_back(vertex.z);
				temp_Verts.push_back(vertex);
			}
			
			// Looking for vn first for normal vectors
			else if(objcoords[i]->c_str()[0] == 'v' && objcoords[i]->c_str()[1] == 'n') 
			{
				b_math::b_vectors::B_Vec3 normals;
				sscanf_s(objcoords[i]->c_str(), "vn %f %f %f", &normals.x, &normals.y, &normals.z);
			//	temp_Normals.push_back(normals.x);
			//	temp_Normals.push_back(normals.y);
			//	temp_Normals.push_back(normals.z);
				temp_Normals.push_back(normals);
			}

			//Checks the line for vt == vertex texture coords
			else if(objcoords[i]->c_str()[0] == 'v' && objcoords[i]->c_str()[1] == 't')
			{
				b_math::b_vectors::B_Vec2 uvs;
				sscanf_s(objcoords[i]->c_str(), "vt %f %f", &uvs.x, &uvs.y);
			//	temp_UVs.push_back(uvs.x);
			//	temp_UVs.push_back(uvs.y);
				temp_UVs.push_back(uvs);
			}

			//Checks the line for f+space (faces coordinates)
			else if(objcoords[i]->c_str()[0] == 'f' && objcoords[i]->c_str()[1] == ' ')
			{
				sscanf_s(objcoords[i]->c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", vertexIndex, uvIndex, normalIndex, vertexIndex+1, uvIndex+1, normalIndex+1, vertexIndex+2, uvIndex+2, normalIndex+2);
				
				vertexIndices.push_back(vertexIndex[0]-1);
				vertexIndices.push_back(vertexIndex[1]-1);
				vertexIndices.push_back(vertexIndex[2]-1);

				uvIndices.push_back(uvIndex[0]-1);
				uvIndices.push_back(uvIndex[1]-1);
				uvIndices.push_back(uvIndex[2]-1);

				normalIndices.push_back(normalIndex[0]-1);
				normalIndices.push_back(normalIndex[1]-1);
				normalIndices.push_back(normalIndex[2]-1);

				++numFaces;
			}
		}


		unsigned int vertsPerFace = 3;
		numVerts = vertsPerFace * numFaces;


		setUpVBO();


		unsigned int floatsPerVertex = 3;
		unsigned int floatsPerNormal = 3;
		unsigned int floatsPerUV = 2;

		unsigned int vertFloatTotal = numVerts * floatsPerVertex;
		unsigned int normalFloatTotal = numVerts * floatsPerNormal;
		unsigned int uvFloatTotal = numVerts * floatsPerUV;


		vertData = new float[vertFloatTotal];
		normalData = new float[normalFloatTotal];
		uvData = new float[uvFloatTotal];


		// ?????? fill these arrays
		currentVert = vertData;
		currentNormal = normalData;
		currentUV = uvData;

		for ( unsigned int v = 0; v < numVerts; ++v )
	//	for ( unsigned int f = 0; f < numFaces; ++f )
		{
			unsigned int vertIndex = vertexIndices[v];
			unsigned int normalIndex = normalIndices[v];
			unsigned int uvIndex = uvIndices[v];

			b_math::b_vectors::B_Vec3 vertex = temp_Verts[vertIndex];
			b_math::b_vectors::B_Vec3 normal = temp_Normals[normalIndex];
			b_math::b_vectors::B_Vec2 uv = temp_UVs[uvIndex];

			*(currentVert++) = vertex.x;
			*(currentVert++) = vertex.y;
			*(currentVert++) = vertex.z;

			*(currentNormal++) = normal.x;
			*(currentNormal++) = normal.y;
			*(currentNormal++) = normal.z;

			*(currentUV++) = uv.x;
			*(currentUV++) = uv.y;
		}


		addVerts(vertData);
		addNormals(normalData);
		addUVs(uvData);


		delete[] vertData;
		delete[] normalData;
		delete[] uvData;
	

	return 1;
}


void ObjLoader::setUpVBO()
{
		//Generate Vertex Arra Object
		glGenVertexArrays(1, &objID);
		glBindVertexArray(objID);

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

void ObjLoader::addVerts(float *rawVerts)
{

//	numVerts = temp_Verts.size() - 1;

	const unsigned int bufferSize =	numVerts * sizeof(float) * 3;//Set Buffer size
	glBindBuffer(GL_ARRAY_BUFFER, vertexHandle);//BIND
	glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, rawVerts);//glBufferData allocates space, glBufferSubData sets values in buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);//UNBIND

}

void ObjLoader::addUVs(float *rawUVs)
{

//	numVerts = temp_Verts.size() - 1;

	const unsigned int bufferSize =	numVerts * sizeof(float) * 2;//Set Buffer size
	glBindBuffer(GL_ARRAY_BUFFER, uvHandle);//BIND
	glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, rawUVs);//glBufferData allocates space, glBufferSubData sets values in buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);//UNBIND

}

void ObjLoader::addNormals(float *rawNormals)
{

//	numVerts = temp_Verts.size() - 1;

	const unsigned int bufferSize =	numVerts * sizeof(float) * 3;//Set Buffer size
	glBindBuffer(GL_ARRAY_BUFFER, normalHandle);//BIND
	glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, rawNormals);//glBufferData allocates space, glBufferSubData sets values in buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);//UNBIND

}

//Activate previously made VBOs
void ObjLoader::activateVBO()
{
	glBindVertexArray(objID);
}

//Render Activated VBOs
void ObjLoader::renderVBO()
{
	glDrawArrays(GL_TRIANGLES, 0, numVerts);//numVerts = vertsPerFace * numFaces
}

//Deactivate VBOs for efficiency/saving memory
void ObjLoader::deactivateVBO()
{
	glBindVertexArray(0);
}