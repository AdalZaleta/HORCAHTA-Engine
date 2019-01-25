#pragma once
#include "hoImages.h"

/*
	Para poder usar hoSprite se tiene que cargar primero la imagen en Inicializar() y ya despues en Render()
	poner que se dibuje la imágen cargada

	Ejemplo:
	-Declarar una variable en RenderGL.h
		hoSprite sprite;

	-RenderGL::Inicializar()
		sprite.LoadImage_("Bolita.png");

	-RenderGL::Render()
		sprite.Draw(0, 0);
		sprite.SetScale(5);
*/

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

