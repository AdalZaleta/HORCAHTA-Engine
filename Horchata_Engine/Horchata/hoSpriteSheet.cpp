#include "hoSpriteSheet.h"



hoSpriteSheet::hoSpriteSheet(){}

bool hoSpriteSheet::Load(const char * _dirImages, const char * _dirJson)
{
	bool ImageLoaded = LoadImage_(_dirImages);
	atlas.loadAtlas(_dirImages, _dirJson);
	// TODO: Cargar el json
	return false;
}

void hoSpriteSheet::Draw(const char * _nameImage, int _x, int _y)
{
	//TO DO: cargar datos desde el atlas
	//Esto es provisional

	int xi, yi, w, h;

	//hoSprite::Draw(_x, _y, xi, yi, w, h);
}

void hoSpriteSheet::Draw(const char * _nameImage, int _x, int _y, int _rotation)
{
	angle = _rotation;
	Draw(_nameImage, _x, _y);
}

hoSpriteSheet::~hoSpriteSheet()
{
}
