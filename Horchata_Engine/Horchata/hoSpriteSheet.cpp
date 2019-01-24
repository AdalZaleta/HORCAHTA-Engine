#include "hoSpriteSheet.h"



hoSpriteSheet::hoSpriteSheet(){}

bool hoSpriteSheet::Load(const char * _dirImages, const char * _dirJson) //cargamos la spritesheet junto con el json
{
	bool ImageLoaded = LoadImage_(_dirImages);
	atlas.loadAtlas(_dirImages, _dirJson);
	return false;
}

void hoSpriteSheet::Draw(const char * _nameImage, int _x, int _y)
{
	hoAtlas::SpriteItem spriteItem = atlas.GetSpriteDetails(_nameImage); //carga el item de la estructura con su informacion 


	hoSprite::Draw(_x, _y, spriteItem.x, spriteItem.y, spriteItem.width, spriteItem.height); //la dibuja acorde a los datos de la struct
}

void hoSpriteSheet::Draw(const char * _nameImage, int _x, int _y, int _rotation) //draw con sobrecarga de rotación
{
	angle = _rotation;
	Draw(_nameImage, _x, _y);
}

hoSpriteSheet::~hoSpriteSheet()
{
}
