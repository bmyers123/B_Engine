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
#include "B_Sprites.h"
//2D and 3D World Creation Classes (3D not yet included)
#include "B_World.h"
//Object Loader Class
#include "ObjLoad.h"

/*

***************************************************************

Non-personal Files that were created by third-party personnel
that I use for graphics loading and rendering

***************************************************************

*/

#include "GLee\GLee.h"
#include "glext.h"
//SFML
#include <SFML\Graphics.hpp>
//#include "SFML\Graphics.hpp"
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
//OpenGL
#include <SFML\OpenGL.hpp>
//FreeGlut

#include "FreeGlut\include\GL\GLU.h"
#include "FreeGlut\include\GL\glut.h"

//Glee (part of FreeGlut?)

//Brent Cowan's Shader Loader Code
#include "Shader.h"
#include "ShaderLoader.h"

/*
***************************************************************
*/