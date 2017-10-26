//Brent Cowan - 2013

#include <fstream>         //Loading and saving files
using namespace std;

#include "Engine (2).h"
#include "ShaderLoader.h"
 //Brent's GLSL loader/debugger

Shader::Shader()
{
	shaderProgram = NULL;
}

Shader::~Shader()
{
	glUseProgramObjectARB(0);
	glDetachObjectARB(shaderProgram, vertexShader);
	glDetachObjectARB(shaderProgram, fragmentShader);
	glDeleteObjectARB(shaderProgram);
}

GLhandleARB Shader::getProgramHandle()
{
	return shaderProgram;
}

bool Shader::Load(char *vertexFile, char *fragmentFile, bool debug)
{
	ShaderLoader shade;

	if(!shade.Load(vertexFile, fragmentFile, debug))
	{
		printf("Shader Failed to Load");
		return false;
	}
	vertexShader   = shade.GetVertexHandle();
	fragmentShader = shade.GetFragmentHandle();
	shaderProgram  = shade.GetProgramHandle();

	return true;
}

void Shader::Activate()
{
	glUseProgramObjectARB(shaderProgram);
}

void Shader::Deactivate()
{
	glUseProgramObjectARB(0);

	glDisable(GL_BLEND);
	
	glActiveTextureARB(GL_TEXTURE0_ARB); glDisable(GL_TEXTURE_2D);
	glActiveTextureARB(GL_TEXTURE1_ARB); glDisable(GL_TEXTURE_2D);
	glActiveTextureARB(GL_TEXTURE2_ARB); glDisable(GL_TEXTURE_2D);
	glActiveTextureARB(GL_TEXTURE3_ARB); glDisable(GL_TEXTURE_2D);
	glActiveTextureARB(GL_TEXTURE4_ARB); glDisable(GL_TEXTURE_2D);
	glActiveTextureARB(GL_TEXTURE0_ARB);
}

void Shader::SetImage(GLuint imageID, char* name, int imageNum)
{
	glEnable(GL_TEXTURE);
	glActiveTextureARB(GL_TEXTURE0_ARB + imageNum); 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, imageID);
	GLint textureID = glGetUniformLocationARB(shaderProgram, name);
	glUniform1iARB(textureID, imageNum);
	glActiveTextureARB(GL_TEXTURE0_ARB); 
}

void Shader::SetFloat(char* name, float value)
{
	GLint floatID = glGetUniformLocationARB(shaderProgram, name);
	glUniform1fARB(floatID, value);
}

void Shader::SetVec4(char* name, float x, float y, float z, float w)
{
	GLint vecID = glGetUniformLocationARB(shaderProgram, name);
	glUniform4fARB(vecID, x, y, z, w);
}

void Shader::SetVec3(char* name, float x, float y, float z)
{
	GLint vecID = glGetUniformLocationARB(shaderProgram, name);
	glUniform3fARB(vecID, x, y, z);
}

void Shader::Blend(int RenderMode)
{
	glEnable(GL_BLEND);

	//Transparency Mode
	if(RenderMode == 0)      //Opaque – no transparency
	{
		glDisable(GL_ALPHA_TEST);
		glDisable(GL_BLEND);
	}
	else if(RenderMode == 1) //Threshold – all or nothing transparency
	{
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.5f);
		glDisable(GL_BLEND);
	}
	else if(RenderMode == 2) //Blend – Normally
	{
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	else if(RenderMode == 3)       //Blend - Additively
	{
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	}
	else if(RenderMode == 4)       //Blend - Subtractive
	{
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		glBlendEquationEXT(GL_FUNC_REVERSE_SUBTRACT);//GL_FUNC_REVERSE_SUBTRACT
	}
	else      //Out of range! defualt to Opaque – no transparency
	{
		glDisable(GL_ALPHA_TEST);
		glDisable(GL_BLEND);
	}
}
