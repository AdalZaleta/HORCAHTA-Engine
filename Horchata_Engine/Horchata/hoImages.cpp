#include "hoImages.h"
#include "SDL_image.h"
#include <iostream>

hoImages::hoImages()
{

}

hoImages::~hoImages()
{

}

hoImages::hoImages(const char* _dirImages)
{
	dirImage = _dirImages;

}

bool hoImages::LoadImage_(const char *_dirImages)
{
	//This const char will be the prefix of the image
	const char *prefix = "Resources/";
	//This char array will be concatenate the path
	char result[100];
	//This add a the array the prefix
	strcpy_s(result, prefix);
	//Then will be add the final path
	strcat_s(result, _dirImages);
	//This make a SDL_Surface from the function load with the final path
	SDL_Surface *surface = IMG_Load(result);
	//Verify if the surface is loaded
	if (surface)
	{
		//Is assigned to the variable of the class
		imageSurface = surface;
		//No se que va aquí
		SDL_LockSurface(imageSurface);
	//if doesn't loaded
	} else if(surface == nullptr){
		//The function will be return false
		return false;
	}
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	int mode = GL_RGB;

	if (imageSurface->format->BytesPerPixel == 4) {
		mode = GL_RGBA;
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexImage2D(GL_TEXTURE_2D, 0, mode, imageSurface->w, imageSurface->h, 0, mode, GL_UNSIGNED_BYTE, imageSurface->pixels);
	SDL_FreeSurface(imageSurface);


	//imageSurface = NULL;
	return true;
}

void hoImages::DrawImage(int _x, int _y, int _width, int _height)
{
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0); glVertex3f(_x, _y, 0);
		glTexCoord2f(1, 0); glVertex3f(_x + _width, _y, 0);
		glTexCoord2f(1, 1); glVertex3f(_x + _width, _y + _height, 0);
		glTexCoord2f(0, 1); glVertex3f(_x,_y + _height, 0);
	glEnd();
}
