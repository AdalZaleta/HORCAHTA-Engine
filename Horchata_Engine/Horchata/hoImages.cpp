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

	const char *prefix = "Resources/";
	char result[100];

	strcpy_s(result, prefix);
	strcat_s(result, _dirImages);

	const char* dirImage = result;
	SDL_Surface *surface = IMG_Load(result);
	std::cout << result << std::endl;

	if (surface)
	{
		std::cout << "pitito" << std::endl;
		imageSurface = surface;
		return true;
	}
	std::cout << "!pitito" << std::endl;
	//imageSurface = NULL;
	return false;
}

void hoImages::DrawImage(int _x, int _y, int _width, int _height, const char *_dirImages)
{
	LoadImage_(_dirImages);
	GLuint textureID = 0;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	int mode = GL_RGB;

	if (imageSurface->format->BytesPerPixel == 4) {
		mode = GL_RGBA;
	}
	glTexImage2D(GL_TEXTURE_2D, 0, mode, imageSurface->w, imageSurface->h, 0, mode, GL_UNSIGNED_BYTE, imageSurface->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(_x, _y, 0);
	glTexCoord2f(1, 0); glVertex3f(_x + _width, _y, 0);
	glTexCoord2f(1, 1); glVertex3f(_x + _width, _y + _height, 0);
	glTexCoord2f(0, 1); glVertex3f(_x,_y + _height, 0);
	glEnd();
}
