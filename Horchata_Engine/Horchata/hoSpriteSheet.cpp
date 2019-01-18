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
	hoAtlas::SpriteItem spriteItem = atlas.GetSpriteDetails(_nameImage);


	hoSprite::Draw(_x, _y, spriteItem.x, spriteItem.y, spriteItem.width, spriteItem.height);
}

void hoSpriteSheet::Draw(const char * _nameImage, int _x, int _y, int _rotation)
{
	angle = _rotation;
	Draw(_nameImage, _x, _y);
}

hoSpriteSheet::~hoSpriteSheet()
{
}
