#pragma once
#include "hoImages.h"

class hoSprite : public hoImages
{
public:
	hoSprite();
	~hoSprite();

	float scalex = 1;
	float scaley = 1;
	float angle = 0;
	float color[4] = { 1, 1, 1, 1 }; //El color del sprite inicia en blanco, 1 de alpha

	void DrawSprite(int x, int y);
	void DrawSprite(int x, int y, float rotation);
	void SetScaleSprite(float scaleX, float scaleY);
	void SetScaleSprite(float scale);
	void SetRotationSprite(float angle);
	void SetColorSprite(float color[4]);
	void SetAlphaSprite(float alpha);
};

