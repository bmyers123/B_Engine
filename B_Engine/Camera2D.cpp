#include "Engine.h"

using namespace b_graphics;
using namespace b_prefabs;

Camera2D::Camera2D()
{
	windowWidth = 800;
	windowHeight = 600;
	zoom = 1.0f;
	contextBits = 32;
	contextAliasingLvl = 4;
	vertSync = true;
	camPos = b_math::b_vectors::B_Vec2(0.0f, 0.0f);
	renderWindow = new sf::RenderWindow();
	window = new sf::Window();
}

Camera2D::Camera2D(sf::Window* window)
{
	this->window = window;
	zoom = float(window->getSize().x);
}

void Camera2D::Activate()
{
	//Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspect = float(windowWidth) / float(windowHeight);
	float zoomX = zoom*0.5f;
	float zoomY = (1.0f/aspect)*zoom*0.5f;
	glOrtho(camPos.x-zoomX, camPos.x+zoomX, camPos.y-zoomY, camPos.y+zoomY, -100.0f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

sf::RenderWindow* Camera2D::initializeWindow(unsigned int windowW, unsigned int windowH, int contextBits, int contextAliasingLvl, bool VSync)
{
	windowWidth = windowW;
	windowHeight = windowH;

	vertSync = VSync;

	contextSettings.depthBits = 32;
	contextSettings.antialiasingLevel = 4;

	// Create the main window
	renderWindow->create(sf::VideoMode(windowWidth, windowHeight), "Test Window", sf::Style::Default, contextSettings);

	
	renderWindow->setVerticalSyncEnabled(vertSync);

	// Make it the active window for OpenGL calls
	renderWindow->setActive();
	//window.setMouseCursorVisible(false);

	// Clear color and depth buffers
	
	glClearDepth(1.f);
	glClearColor(0.2f, 0.5f, 0.6f, 1.f);//black

	glEnable(GL_DEPTH_TEST);

	// glDisable(GL_LIGHTING);

	glViewport(0, 0, renderWindow->getSize().x, renderWindow->getSize().y);

	//Camera3D cam(&window);


	myGUI = sf::View(renderWindow->getDefaultView());

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	return renderWindow;
}

void Camera2D::displayWindow()
{
	window->display();
}