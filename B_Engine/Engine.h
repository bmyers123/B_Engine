
/*----------------------------------------------------------------
 Includes all Math Library Classes Made by:

	Brayden Myers 
		copyright 2014 :)


	This Engine File Contains all of my (Brayden Myers) Math files for:

		- Matrices
		- Vectors
*/

/*
	**** BRAYDEN'S CLASSES ****

	Brayden's Math Library Engine
*/

//#include "B_MathEngine.h"

//----------------------------------------------------------------
//Constants

#define GRAVITY -9.8f
#define PI  3.14159265f
#define DTR 0.01745329f
#define RTD 57.2957795f

/*

***************************************************************

Non-personal Files that were created by third-party personnel
that I use for graphics loading and rendering

***************************************************************

*/

#include "GLee\GLee.h"
#include "GL.h"
//#include "FreeGlut\include\GL\GLU.h"
//#include "FreeGlut\include\GL\glew.h"


#include "glext.h"

#include "FreeGlut\include\GL\glut.h"

//#include "FreeGlut\include\GL\freeglut.h"
//#include "FreeGlut\include\GL\freeglut_ext.h"
//#include "FreeGlut\include\GL\freeglut_std.h"

//SFML
#include "SFML\Graphics.hpp"
//#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
//OpenGL
#include "SFML\OpenGL.hpp"
//FreeGlut


//#include "GL\GLU.h"



//----------------------------------------------------------------
//Matrix Classes
//------------------
//2x2 Matrices
#include "B_Mat2.h"
//3x3 Matrices
#include "B_Mat3.h"
//4x4 Matrices
#include "B_Mat4.h"

//----------------------------------------------------------------
//Vector Classes
//------------------
//Vec2s
#include "B_Vec2.h" 
//Vec3s
#include "B_Vec3.h"
//Vec4s
#include "B_Vec4.h"


/*----------------------------------------------------------------
 Includes all Graphics Library and Classes Made by:

	Brayden Myers 
		copyright 2014 :)


	This Engine File Contains all of my (Brayden Myers) Math files for:

		- Sprites
		- 2D/3D World Creation/Rendering


		****

		This engine also uses SFML, OpenGL, and FreeGlut code 
		that was NOT created by me.

		****

*/

/*
	**** BRAYDEN'S CLASSES ****

	Personal classes/files that I have created
	These are used by me for rendering/creating certain:

		- Objects
		- Characters/Sprites
		- Worlds
		- ...Etc (more to come)
*/

//Sprite Class
//#include "B_Sprites.h"
//2D and 3D World Creation Classes (3D not yet included)
//#include "B_World.h"
//Object Loader Class
#include "ObjLoad.h"

/*
	Other Personally Made Files
*/

#include "B_2D_Player.h"
//#include "B_World.h"
//#include "B_3DWorld.h"
#include "Shiny_Boxes.h"



//#pragma comment(lib, "glu32.lib")
//#pragma comment(lib, "opengl32.lib")

//Glee (part of FreeGlut?)

//My Shader Loader Code
#include "GLSLShader.h"

//Everything Textures
#include "B_Textures.h"

//#include "B_RenderWindow.h"
#include "B_Window.h"

/*
***************************************************************
*/

/*
	Other non-Personally made files
*/

#include "Camera2D.h"
#include "Camera3D.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <windows.h>


