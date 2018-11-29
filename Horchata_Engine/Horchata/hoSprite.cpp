#include "hoSprite.h"

hoSprite::hoSprite()
{
}


hoSprite::~hoSprite()
{
}

void hoSprite::DrawSprite(int _x, int _y)
{
	glPushMatrix(); //Se hace un PushMatrix() para poder trasladarnos en las 4 esquinas de la imagen
		glColor4f(color[0], color[1], color[2], color[3]);
		glRotatef(angle, 0, 0, 1);
		DrawImage(_x, _y, width / 100.0f * scalex, height / 100.0f * scaley);
	glPopMatrix(); //Termina la fase de render
}

void hoSprite::DrawSprite(int _x, int _y, float rotation)
{
	angle = rotation;
	DrawSprite(_x, _y);
}

void hoSprite::SetScaleSprite(float scaleX, float scaleY)
{
	scalex = scaleX;
	scaley = scaleY;
}

void hoSprite::SetScaleSprite(float scale)
{
	scalex = scale;
	scaley = scale;
}

void hoSprite::SetRotationSprite(float _angle)
{
	angle = _angle;
}

void hoSprite::SetColorSprite(float _color[4])
{
	for (int i = 0; i < 4; i++) color[i] = _color[i];
}

void hoSprite::SetAlphaSprite(float alpha)
{
	color[3] = alpha;
}
