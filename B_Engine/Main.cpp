//#include <Windows.h>
//#include "Engine.h"
//#include "GLee\GLee.h"
//#include "GL.h"

//#include "B_RenderWindow.h"
#include "Shiny_Boxes.h"


int main()
{

	Shiny_Boxes SB;

	SB.initializeTestWorld();
	SB.GameLoop();


	return 0;
}