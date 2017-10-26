#ifndef _GLSLSHADER_H
#define _GLSLSHADER_H

#include "B_Vec3.h"
#include "B_Vec4.h"
#include "B_Mat3.h"
#include "B_Mat4.h"
#include <string>

namespace b_graphics{
	namespace b_shaders{

		enum shaderType
		{
			GLSL_VERTEX_SHADER,
			GLSL_FRAGMENT_SHADER,
			GLSL_GEOMETRY_SHADER,
		};

		class GLSLShader
		{

		public:

			//defualt con/de structors
			GLSLShader();
			~GLSLShader();

			//get functions
			inline shaderType GetType() const
			{
				return type;
			}

			inline unsigned int getHandle() const
			{
				return handle;
			}

			//release shader from graphics memory
			void Release();

			//read in the file paths
			std::string readFile(const char *filePath);

			//create shader from source of from file
			int createFromSource(shaderType sType, const char *source);
			int createFromFile(shaderType sType, const char *filePath);
			//int createFromFile(shaderType sType, const char *vertShaderPath, const char *fragShaderPath);

		private:

			shaderType type;
			unsigned int handle;

		};

		class GLSLShaderProgram
		{

		public:

			//default con/de structors
			GLSLShaderProgram();
			~GLSLShaderProgram();

			//release from graphics memory
			void Release();

			//Attach a shader to the program
			int attachShader(const GLSLShader *shader);

			//link program
			//return 0 = fail, 1 = success
			int linkProgram();

			//activate program
			void Activate() const;

			//Deactivates all or one (one if possible, all if not possible to deactivate single programs)
			void Deactivate();
			//void deactivateAll();

			//get the location of a uniform variable
			//returns -1 if not found or is not in use
			//returns 0 or higher if found
			int getUniformLocation(const char *uniformName);

			//function to send individual uniforms
			//operates on the currently active program

			void UniformFloat(int location, const float value);
			//void UniformVec3(int location, const B_Vec3 vec3);
			//void UniformVec4(int location, const B_Vec4 vec4);
			void UniformMat3(int location, bool transpose, const b_math::b_matrices::B_Mat3 mat3);
			void UniformMat4(int location, bool transpose, const b_math::b_matrices::B_Mat4 mat4);
			void UniformVec3List(int location, unsigned int numValues, const float *vec3List); //Why is this "list"?
			void UniformVec4List(int location, unsigned int numValues, const float *vec4List);

		private:

			unsigned int handle;

		};

	}
}

#endif

