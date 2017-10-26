#ifndef B_TEXTURES_H
#define B_TEXTURES_H

/*
	Texture Loading, Applying, and Settings.

	1. Load a texture.
	
	2. When you render your object:
		a. Apply Texture
		b. Apply Settings (only default atm)
		c. Render Object
		d. Disable Texture

*/

#include "SFML\Graphics\Image.hpp"

class B_Textures
{
public:
	B_Textures(void);
	~B_Textures(void);

	void loadTextureImage(const char* filepath);

	void applyTexture(unsigned int texID);
	void disableTexture();
	
	void defaultTexSettings();

	unsigned int getTexID();
	
private:

	unsigned int texID;
	sf::Image texImg;
};

#endif