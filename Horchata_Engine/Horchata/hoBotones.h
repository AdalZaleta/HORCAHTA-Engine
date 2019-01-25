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

		// Variables de posicion del boton
		double x, y;

		double x2;
		double y2;

		// Sprite que el boton usara al ser creado
		hoSprite* Sprite;

		// Variable para indicarle al boton que esta usando un Sprite
		bool SpriteActivo;

		//Variables para color 
		float r;
		float g;
		float b;

		void OnClickDown(float x, float y);

		//Funcion del ejemplo sin sprite - Los parametros son (posx ,posy, tamañoX,TamañoY,R,G,B,Funcion) 
		void CreateButton(double _x1, double _y1, double _x2, double _y2, float _Rojo, float _Verde, float _Azul, void(*_Funcion)(void));

		//Funcion del ejemplo con sprite - Los parametros son (x , y, tamañoX,TamañoY,Imagen,Funcion)
		void CreateButton(double _x1, double _y1, float _ScaleX, float _ScaleY, const char* _NombreSprite, void(*_Funcion)(void));

		// Funcion permite la implementacion de funciones dentro del boton
		void(*funcionBoton)(void);

		//Dibuja el boton
		void DrawButton();
};

