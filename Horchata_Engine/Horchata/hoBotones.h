#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include "hoSprite.h"

using namespace std;


class hoBotones
{
	public:
		hoBotones();
		~hoBotones();

		double x, y,h,w;

		double x2;
		double y2;

		hoSprite* Sprite;

		bool SpriteActivo;

		float r;
		float g;
		float b;

		bool onClick;

		void OnClickDown(float x, float y);
		void OnClickUp();

		void CreateButton(double _x1, double _y1, double _x2, double _y2, float Rojo, float Verde, float Azul, void(*Funcion)(void));
		void CreateButton(double _x1, double _y1, float _ScaleX, float _ScaleY, const char* _NombreSprite, void(*Funcion)(void));

		void(*funcionBoton)(void);

		void DrawButton();
};

