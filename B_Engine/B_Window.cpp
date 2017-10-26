#include "Engine.h"

B_Window::B_Window(void)
{
	contextSettings.antialiasingLevel = 0;
	contextSettings.depthBits = 0;
	vertSync = true;
}


B_Window::~B_Window(void)
{
}

void B_Window::B_initialize_and_Create_Window(char* windowTitle, bool verticalSync, unsigned int antialiasingLevel, unsigned int depthBits, unsigned int windowWidth, unsigned int windowHeight, sf::Window glrenderWindow)
{

	contextSettings.depthBits = depthBits;
	contextSettings.antialiasingLevel = antialiasingLevel;
	vertSync = verticalSync;

	glrenderWindow.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Default, contextSettings);
	glrenderWindow.setVerticalSyncEnabled(vertSync);

}

void B_Window::B_activateWindow(sf::Window glrenderWindow)
{
	glrenderWindow.setActive();
}

void B_Window::B_Window_Display(sf::Window glrenderWindow)
{
	glrenderWindow.display();
}

//sf::Window B_Window::getGLRenderWindow()
//{
//	return *glrenderWindow;
//}
