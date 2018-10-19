#pragma once

#include <SDL.h>
#include <SDL_opengl.h>
#include <vector>

class hoImages
{
public:
	hoImages();
	hoImages(const char* _dirImages);
	~hoImages();

	void DrawImage();

private:
	const char* dirImage;
	SDL_Surface* imageSurface = NULL;
};
