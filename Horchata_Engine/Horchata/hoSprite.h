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

	virtual void Draw(int x, int y, int xini, int yini, int xw, int yh);
	void Draw(int x, int y);
	void Draw(int x, int y, float rotation);
	void SetScale(float scaleX, float scaleY);
	void SetScale(float scale);
	void SetRotation(float angle);
	void SetColor(float color[4]);
	void SetAlpha(float alpha);
};

