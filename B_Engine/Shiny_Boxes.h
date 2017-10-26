#ifndef _SHINY_BOXES_H
#define _SHINY_BOXES_H

#include "B_Mat4.h"
#include "B_Vec2.h"
#include "Camera2D.h"
#include "Camera3D.h"
#include "B_World.h"
#include "B_Window.h"
#include "ObjLoad.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\OpenGL.hpp>
#include "GLSLShader.h"



class Shiny_Boxes
{

public:
	Shiny_Boxes();
	~Shiny_Boxes();

	void initializeTestWorld();

	void initialize2DWorld();
	void GameLoop();
	void Update();
	void updateClock();
	void updateCameraMatrices();
	void updateObjectMatrices(b_graphics::b_parsers::ObjLoader *obj);
	void drawTestWorld();

	float dt;

	//Tests for Camera movements
		void mouseUpdate();
		void keyChecks();
	//

private:

	//Tests for Camera movements
	float zoom;
	float rotValue;
	float yRot;
	//sf::Vector2i diff;
	//B_Vec2 center;
	sf::Mouse mouse;
	//
	GLint tex;

	//B_2DWorld *ShinyBoxesGrid;
	b_graphics::b_prefabs::Camera2D *world2DCam;
	b_graphics::b_prefabs::Camera3D *world3DCam;
	sf::Event event;
	sf::ContextSettings contextSettings;
	sf::Window glrenderWindow;

	B_Window window;
	//B_RenderWindow B_RW;


	bool key[sf::Keyboard::KeyCount];
	sf::Clock Clock;

	b_graphics::b_parsers::ObjLoader *testObj;
	float *testVData, *testNData, *testTexData;
	sf::Image testTexImg;
	unsigned int testTex;
	int testLoc, psmMVP, psmMV, texture1;

	//Shader testObjShader;
	b_graphics::b_shaders::GLSLShaderProgram *passThruProgram;
	b_graphics::b_shaders::GLSLShader vertShader, fragShader;
	int mvMat, mvpMat, color, worldToObj;
	b_math::b_vectors::B_Vec4 colorVec;

	bool endOfGame;
	bool shaderDebug;

	sf::Vector2i diff;

	b_math::b_matrices::B_Mat3 rotationMat;

	//Pipeline Transforms
	b_math::b_matrices::B_Mat4 modelMatrix;

	//Concatenated Mats
	b_math::b_matrices::B_Mat4 viewMat, projectionMat, modelViewMatrix, viewProjectionMatrix, modelViewProjectionMatrix;

	//Inverse Mats
	b_math::b_matrices::B_Mat4 eyeToWorld, worldToObject;
	
};

#endif
