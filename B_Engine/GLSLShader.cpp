#include "Engine.h"

using namespace b_graphics;
using namespace b_shaders;

GLSLShader::GLSLShader()
{
	handle = 0;
}


GLSLShader::~GLSLShader()
{
	Release();
}

std::string GLSLShader::readFile(const char *filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

int GLSLShader::createFromSource(shaderType sType, const char *source)
{
	return 0;
}


int GLSLShader::createFromFile(shaderType sType, const char *filePath)
{
	if(!handle)
	{
		if(filePath)
		{
			//create shader
			if(sType == GLSL_VERTEX_SHADER)
			{
				handle = glCreateShader(GL_VERTEX_SHADER);
			}
			else if(sType == GLSL_FRAGMENT_SHADER)
			{
				handle = glCreateShader(GL_FRAGMENT_SHADER);
			
			}

			if(handle)
			{
				//Read shader file
				std::string shaderStr = readFile(filePath);
				const char *shaderSrc = shaderStr.c_str();

				//Compile shader
				std::cout <<"Compiling shader." << std::endl;
				glShaderSource(handle, 1, &shaderSrc, NULL);
				glCompileShader(handle);

				//Create vars for error checking
				GLint result = GL_FALSE;
				int logLength;
				// Get error if shader compiling fails
				glGetShaderiv(handle, GL_COMPILE_STATUS, &result);
				glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &logLength);
				std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
				glGetShaderInfoLog(handle, logLength, NULL, &vertShaderError[0]);
				std::cout << &vertShaderError[0] << std::endl;

				//glDeleteShader(handle);

			}
		}
	}

	return 0;
}

void GLSLShader::Release()
{
	//deactivate shader handle with like...glDeactivate(handle) or something...
	if(handle)
	{
		glDeleteShader(handle);
		handle = 0;
	}
}

//SHADER PROGRAM FUNCTIONS

GLSLShaderProgram::GLSLShaderProgram()
{
	handle = 0;
}

GLSLShaderProgram::~GLSLShaderProgram()
{
	Release();
}

int GLSLShaderProgram::attachShader(const GLSLShader *shader)
{
	if(shader)
	{
		if(!handle)
		{
			handle = glCreateProgram();
		}

		glAttachShader(handle, shader->getHandle());
		linkProgram();

	}



	return 0;
}

int GLSLShaderProgram::linkProgram()
{
	if(handle)
	{
		glLinkProgram(handle);

		GLint result = GL_FALSE;
		int logLength;
		//validating program
		glGetProgramiv(handle, GL_LINK_STATUS, &result);
		glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> programError( (logLength > 1) ? logLength : 1 );
		glGetProgramInfoLog(handle, logLength, NULL, &programError[0]);
		std::cout << &programError[0] << std::endl;

		glDeleteShader(handle);

	}
	return 0;
}

void GLSLShaderProgram::Activate() const
{
	glUseProgram(handle);
}

void GLSLShaderProgram::Deactivate()
{
	glUseProgram(0);
}

int GLSLShaderProgram::getUniformLocation(const char *uniformName)
{
	if(uniformName)
	{
		GLuint loc = glGetUniformLocation(handle, uniformName);
		return loc;
	}

	else 
		return -1;
}

void GLSLShaderProgram::UniformFloat(int location, const float value)
{
	glUniform1f(location, value);
}

void GLSLShaderProgram::UniformMat3(int location, bool transpose, const b_math::b_matrices::B_Mat3 mat3)
{
	glUniformMatrix3fv(location, 1, transpose, mat3.m);
}

void GLSLShaderProgram::UniformMat4(int location, bool transpose, const b_math::b_matrices::B_Mat4 mat4)
{
	glUniformMatrix4fv(location, 1, transpose, mat4.m);
}

void GLSLShaderProgram::UniformVec3List(int location, unsigned int numValues, const float *vec3List)
{
	glUniform3fv(location, numValues, vec3List);
}

void GLSLShaderProgram::UniformVec4List(int location, unsigned int numValues, const float *vec4List)
{
	glUniform4fv(location, numValues, vec4List);
}

void GLSLShaderProgram::Release()
{
	if(handle)
	{
		glDeleteProgram(handle);
		handle = 0;
	}
}

