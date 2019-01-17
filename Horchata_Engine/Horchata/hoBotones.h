#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include "hoSprite.h"

using namespace std;

	// Ejemplo CrearBotones con sprite(x , y, tamañoX,TamañoY,Imagen,Funcion) parametros
	//Boton.CreateButton(0.0f, 0.0f, 5.0f, 5.0f, "GABO.jpg", Click);

	// Ejemplo CrearBotones sin sprite(x , y, tamañoX,TamañoY,R,G,B,Funcion) parametros
	//Boton_2.CreateButton(15.0f, 15.0f, 30.0f, 30.0f, 1.0f, 0.0f, 0.0f, Click);

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

		//Variables para color 
		float r;
		float g;
		float b;

		//bool onClick;

		void OnClickDown(float x, float y);
		//void OnClickUp();

		//Funcion del ejemplo sin sprite - Los parametros son (posx ,posy, tamañoX,TamañoY,R,G,B,Funcion) 
		void CreateButton(double _x1, double _y1, double _x2, double _y2, float Rojo, float Verde, float Azul, void(*Funcion)(void));
		//Funcion del ejemplo con sprite - Los parametros son (x , y, tamañoX,TamañoY,Imagen,Funcion)
		void CreateButton(double _x1, double _y1, float _ScaleX, float _ScaleY, const char* _NombreSprite, void(*Funcion)(void));
		// Funcion permite la implementacion de funciones dentro del boton
		void(*funcionBoton)(void);
		//Dibuja el boton
		void DrawButton();
};

