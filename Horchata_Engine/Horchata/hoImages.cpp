#include "hoImages.h"
#include "../SDL/include/SDL_image.h"

hoImages::hoImages()
{

}

hoImages::~hoImages()
{

}

bool hoImages::LoadImage(const char *_dirImages)
{
	const char* dirImage = ("../Resources/%s", _dirImages);
	SDL_Surface *surface = IMG_Load(dirImage);

	if (surface != nullptr)
	{
		return true;
	}
	return false;
}