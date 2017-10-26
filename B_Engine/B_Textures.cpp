#include "Engine.h"

B_Textures::B_Textures(void)
{
	texID = 0;
}


B_Textures::~B_Textures(void)
{
}


void B_Textures::loadTextureImage(const char* filepath)
{
	if(!texImg.loadFromFile(filepath))
	{
		std::cout << "Error loading image from filepath: " << filepath << std::endl;
	}
	else
	{
		texImg.flipVertically();
	}
}

void B_Textures::applyTexture(unsigned int texID)
{
	glBindTexture(GL_TEXTURE_2D, texID);
}

void B_Textures::defaultTexSettings()
{
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, texImg.getSize().x, texImg.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE, texImg.getPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void B_Textures::disableTexture()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int B_Textures::getTexID()
{
	return texID;
}