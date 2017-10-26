#ifndef _ObjLoad_H
#define _ObjLoad_H

#include "B_Vec2.h"
#include "B_Vec3.h"
#include <vector>

namespace b_graphics{
	namespace b_parsers{

		class ObjLoader
		{

		public:

			ObjLoader();
			~ObjLoader();

			//Vertex vector
			std::vector<unsigned int> vertexIndices;
			//UV vector
			std::vector<unsigned int> uvIndices;
			//Normal Vector
			std::vector<unsigned int> normalIndices;
			//Vertex, UV, Normal Temps
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];


			//Temp Vertices Holder
			std::vector<b_math::b_vectors::B_Vec3> temp_Verts;
			//Temp UVs Holder
			std::vector<b_math::b_vectors::B_Vec2> temp_UVs;
			//Temp Normals Holder
			std::vector<b_math::b_vectors::B_Vec3> temp_Normals;

			//Vector that holds text file
			std::vector<std::string*> objcoords;

			//Buffer Ints
			//GLuint objID;
			unsigned int objID;
			//GLuint objIndices;
			unsigned int objIndices;
			//GLuint vertexHandle;
			unsigned int vertexHandle;
			//GLuint normalHandle;
			unsigned int normalHandle;
			//GLuint uvHandle;
			unsigned int uvHandle;

			float *vertData;
			float *normalData;
			float *uvData;

			float *newvertData;
			float *newnormalData;
			float *newuvData;

			float *currentVert;
			float *currentNormal;
			float *currentUV;

			float uniformScale;

			unsigned int numVerts;

			//Intitialize VBO
			void setUpVBO();

			//Activate/Deactivate VBO
			void activateVBO();
			void deactivateVBO();

			//Render information on VBO
			void renderVBO();

			//Release VBO and Information
			void Release();

			//Add VBO Information
			void addVerts(float *rawVerts);
			void addNormals(float *rawNorms);
			void addUVs(float *rawUVs);

			int loadObj(const char* filename);

			b_math::b_vectors::B_Vec3 position;
			b_math::b_vectors::B_Vec3 rotation;

		};
	}
}

#endif


