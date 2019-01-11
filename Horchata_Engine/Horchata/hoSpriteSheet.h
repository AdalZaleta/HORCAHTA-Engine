#pragma once
#include "hoSprite.h"

class hoSpriteSheet : hoSprite
{
public:
	hoSpriteSheet();

	bool Load(const char *_dirImages, const char *_dirJson);
	void Draw(const char *_nameImage, int _x, int _y);
	void Draw(const char *_nameImage, int _x, int _y, int _rotation);
	virtual void DrawImage(int _x, int _y, int _width, int _height) override;
	~hoSpriteSheet();
};

