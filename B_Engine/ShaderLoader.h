//Brent Cowan 2013
#ifndef SHADER_LOADER_H
#define SHADER_LOADER_H

#include "Engine.h"

class ShaderLoader
{
private:
	static bool init;
	unsigned int vertex;
	unsigned int fragment;
	unsigned int program;

public:
	bool Load(char *vertexShader, char *fragmentShader, bool debug);
	unsigned int GetVertexHandle();
	unsigned int GetFragmentHandle();
	unsigned int GetProgramHandle();
};

#endif