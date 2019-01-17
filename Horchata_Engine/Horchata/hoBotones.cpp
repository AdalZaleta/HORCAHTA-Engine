#include "hoBotones.h"
#include <stdio.h>

hoBotones::hoBotones()
{
}


hoBotones::~hoBotones()
{
}

void hoBotones::CreateButton(double _x1, double _y1, double _x2, double _y2, float Rojo, float Verde, float Azul, void(*Funcion)(void))
{
	//coordenadas
	x =_x1;
	y = _y1;
	//tamaño
	y2 = _y2;
	x2 = _x2;
	//valores RGB para color del boton ( sin sprites)
	r = Rojo;
	g = Verde;
	b = Azul;
	//Nos permite agregar una funcion al boton mediante un apuntador
	funcionBoton = Funcion;

	SpriteActivo = false;
}

void hoBotones::CreateButton(double _x1, double _y1, float _ScaleX, float _ScaleY,const char* _NombreSprite, void(*Funcion)(void))
{
	//coordenadas
	x =_x1;
	y = _y1;

	Sprite = new hoSprite();

	Sprite->scalex = _ScaleX;
	Sprite->scaley = _ScaleY;
	
	Sprite->LoadImage_(_NombreSprite);

	funcionBoton = Funcion;

	SpriteActivo = true;
}

void hoBotones::DrawButton()
{
	if (SpriteActivo == true)
	{
		Sprite->Draw(x, y);
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
	if (SpriteActivo == false)
	{
		if (MouseX >= x && MouseX <= x2 && MouseY >= y && MouseY <= y2)
		{
			cout << "CLICK en boton sin sprite ejemplo 2" << endl;
			funcionBoton();
		}
	}
	else
	{
		if (MouseX >= x - Sprite->width / 100.0f * Sprite->scalex / 2 && MouseX <= Sprite->width / 100.0f * Sprite->scalex/2 && MouseY >= y - Sprite->height / 100.0f * Sprite->scaley / 2 && MouseY <= Sprite->height / 100.0f * Sprite->scaley/2)
		{
			cout << "CLICK en Boton con Sprite ejemplo 1" << endl;
			funcionBoton();
		}
	}
	
}
