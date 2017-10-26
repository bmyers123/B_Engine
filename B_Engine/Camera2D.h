#ifndef _CAMERA2D_H
#define _CAMERA2D_H

#include "Engine.h"

namespace b_graphics{

	namespace b_prefabs{

		class Camera2D
		{
		public:
			Camera2D();
			Camera2D(sf::Window* window);
			void Activate();

			sf::RenderWindow* initializeWindow(unsigned int windowW, unsigned int windowH, int contextBits, int contextAliasingLvl, bool VSync);
			void displayWindow();

		private:
			sf::ContextSettings contextSettings;//Allows for context/window settings
			sf::RenderWindow *renderWindow;
			sf::Window* window;
			unsigned int windowWidth, windowHeight;
			int contextBits, contextAliasingLvl;
			bool vertSync;
			sf::View myGUI;
			b_math::b_vectors::B_Vec2 camPos;
			float zoom;
		};
	}
}

#endif