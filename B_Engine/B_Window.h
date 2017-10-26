#ifndef B_WINDOW_H
#define B_WINDOW_H

#include <SFML\Window.hpp>

class B_Window
{
public:
	
	B_Window(void);
	~B_Window(void);

	//Requires a window to be passed to it
	// --- OpenGL doesn't allow you to recopy renderwindows?
	void B_initialize_and_Create_Window(char* windowTitle, bool verticalSync, unsigned int antialiasingLevel, unsigned int depthBits, unsigned int windowWidth, unsigned int windowHeight, sf::Window glrenderWindow);
	void B_activateWindow(sf::Window glrenderWindow);
	void B_Window_Display(sf::Window glrenderWindow);

	//Create the event handling as well
	void B_initialize_EventHandling(sf::Event event);

	//sf::Window getGLRenderWindow();

private:

	//sf::Window *glrenderWindow;
	sf::ContextSettings contextSettings;
	bool vertSync;

};

#endif