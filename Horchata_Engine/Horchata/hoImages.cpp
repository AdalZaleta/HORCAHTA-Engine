#include "hoImages.h"
#include "SDL_image.h"

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

	const char *prefix = "../Resources/";
	char result[100];

	strcpy_s(result, prefix);
	strcat_s(result, _dirImages);

	const char* dirImage = result;
	SDL_Surface *surface = IMG_Load(dirImage);

	if (surface)
	{
		imageSurface = surface;
		return true;
	}
	imageSurface = NULL;
	return false;
}

void hoImages::DrawImage(const char *_dirImages)
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

	// For Ortho mode, of course
	int X = 0;
	int Y = 0;
	int Width = 100;
	int Height = 100;

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(X, Y, 0);
	glTexCoord2f(1, 0); glVertex3f(X + Width, Y, 0);
	glTexCoord2f(1, 1); glVertex3f(X + Width, Y + Height, 0);
	glTexCoord2f(0, 1); glVertex3f(X, Y + Height, 0);
	glEnd();
}