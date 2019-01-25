#pragma once
#include "hoSprite.h"
#include "hoAtlas.h"

class hoSpriteSheet : hoSprite
{
public:
	hoSpriteSheet();

	bool Load(const char *_dirImages, const char *_dirJson);
	void Draw(const char *_nameImage, int _x, int _y);
	void Draw(const char *_nameImage, int _x, int _y, int _rotation);
	void Draw(hoAtlas::SpriteItem _item, int _x, int _y);
	void Draw(hoAtlas::SpriteItem _item, int _x, int _y, int _rotation);
	void SetScale(float _scale) {
		hoSprite::SetScale(_scale);
	}

	hoAtlas atlas;

	~hoSpriteSheet();
};

