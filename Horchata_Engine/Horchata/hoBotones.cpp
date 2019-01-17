#include "hoBotones.h"
#include <stdio.h>

hoBotones::hoBotones()
{
}


hoBotones::~hoBotones()
{
}

void hoBotones::CreateButton(double _x1, double _y1, double _x2, double _y2, float Rojo, float Verde, float Azul)
{
	//coordenadas
	x =_x1;
	y = _y1;
	//tamaño
	y2 = _y2;
	x2 = _x2;
	
	r = Rojo;
	g = Verde;
	b = Azul;

	SpriteActivo = false;
}

void hoBotones::CreateButton(double _x1, double _y1, double _x2, double _y2, const char* NombreSprite)
{
	//coordenadas
	x =_x1;
	y = _y1;
	//tamaño
	y2 = _y2;
	x2 = _x2;

	Sprite = new hoSprite();

	Sprite->LoadImage_(NombreSprite);
	SpriteActivo = true;
}

void hoBotones::DrawButton()
{

	if (SpriteActivo == true)
	{
		//Sprite->width / 100.0f * scalex //15    -  20
		//PRIMERO DETERMINAMOS DIFERENCIA EN %
		//EN EL EJEMPLO LA IMAGEN ES 25% más pequeña, por lo que
		//AL SPIRTE LE DAREMOS UNA ESCALA DE 1.25
		Sprite->Draw(x2 - x + x, y2 - y + y);
	}
	else
	{
		glBegin(GL_POLYGON);
		glColor3f(r, g, b);
		glVertex2d(x, y);
		glVertex2d(x, y2);
		glVertex2d(x2, y2);
		glVertex2d(x2, y);
		glEnd();
	}
}

void hoBotones::OnClickDown(float MouseX, float MouseY) 
{
	/*cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "x2: " << x2 << endl;
	cout << "y2: " << y2 << endl;*/

	if (MouseX >= x && MouseX <= x2 && MouseY >= y && MouseY <= y2)
	{
		cout << "CLICK" << endl;
	}
	
}
