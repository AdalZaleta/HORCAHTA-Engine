#pragma once
#include "hoSprite.h"
#include "hoAtlas.h"

class hoSpriteSheet : hoSprite
{
public:
	hoSpriteSheet();

	//hoAtlas atlas;
	
	bool Load(const char *_dirImages, const char *_dirJson);
	void Draw(const char *_nameImage, int _x, int _y);
	void Draw(const char *_nameImage, int _x, int _y, int _rotation);

	hoAtlas atlas;
	~hoSpriteSheet();
};

