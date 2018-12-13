#include "hoSprite.h"

hoSprite::hoSprite()
{
}


hoSprite::~hoSprite()
{
}

void hoSprite::Draw(int _x, int _y)
{
	glPushMatrix(); //Se hace un PushMatrix() para poder trasladarnos en las 4 esquinas de la imagen
		glColor4f(color[0], color[1], color[2], color[3]); //Dibujamos el color (blanco por default)
		glRotatef(angle, 0, 0, 1); //rotamos en Z
		DrawImage(_x, _y, width / 100.0f * scalex, height / 100.0f * scaley); //Se dibuja como imagen
	glPopMatrix(); //Termina la fase de render
}

void hoSprite::Draw(int _x, int _y, float rotation) //Sobrecarga que settea la rotacion
{
	angle = rotation;
	Draw(_x, _y);
}

void hoSprite::SetScale(float scaleX, float scaleY) //Settea la escala
{
	scalex = scaleX;
	scaley = scaleY;
}

void hoSprite::SetScale(float scale) //Sobrecarga del metodo de setteo de escala
{
	scalex = scale;
	scaley = scale;
}

void hoSprite::SetRotation(float _angle) //Settea la rotacion
{
	angle = _angle;
}

void hoSprite::SetColor(float _color[4]) //Settea el color (recibe un float[4] {r, g, b, a})
{
	for (int i = 0; i < 4; i++) color[i] = _color[i];
}

void hoSprite::SetAlpha(float alpha) //Settea solo el alpha, manteniendo el color
{
	color[3] = alpha;
}
