#ifndef _Shader_
#define _Shader_

#include "GLee\GLee.h"
#include "SFML\OpenGL.hpp"


class Shader
{
private:
	GLhandleARB vertexShader;
	GLhandleARB fragmentShader;
	GLhandleARB shaderProgram;

public:
	Shader();
	~Shader();
	bool Load(char *vertexFile, char *pixelFile, bool debug);
	void Activate();
	void SetImage(GLuint imageID, char* name, int imageNum);
	void SetFloat(char* name, float value);
	void SetVec4(char* name, float x, float y, float z, float w);
	void SetVec3(char* name, float x, float y, float z);


	GLhandleARB getProgramHandle();

	static void Deactivate();
	static void Blend(int RenderMode);
};

#endif