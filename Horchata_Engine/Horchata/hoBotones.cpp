#include "hoBotones.h"
#include <stdio.h>

hoBotones::hoBotones()
{
}


hoBotones::~hoBotones()
{
}

void hoBotones::CreateButton(double _x1, double _y1, double _x2, double _y2, float _Rojo, float _Verde, float _Azul, void(*_Funcion)(void))
{
	//coordenadas
	x =_x1;
	y = _y1;
	//tamaño
	y2 = _y2;
	x2 = _x2;
	//valores RGB para color del boton ( sin sprites)
	r = _Rojo;
	g = _Verde;
	b = _Azul;
	//Nos permite agregar una funcion al boton mediante un apuntador
	funcionBoton = _Funcion;

	// Le indicamos al boton que no se usara un Sprite
	SpriteActivo = false;
}

void hoBotones::CreateButton(double _x1, double _y1, float _ScaleX, float _ScaleY,const char* _NombreSprite, void(*_Funcion)(void))
{
	//coordenadas
	x =_x1;
	y = _y1;

	// Creamos un nuevo sprite
	Sprite = new hoSprite();

	// Seteamos su escala
	Sprite->scalex = _ScaleX;
	Sprite->scaley = _ScaleY;
	
	// Cargamos el Sprite
	Sprite->LoadImage_(_NombreSprite);

	// Le indicamos al boton que funcion usara al ser presionado
	funcionBoton = _Funcion;

	// Le indicamos al boton que estamos usando un Sprite
	SpriteActivo = true;
}

void hoBotones::DrawButton()
{
	// Si usamos un Sprite
	if (SpriteActivo == true)
	{
		// Dibujamos el boto con el Sprite
		Sprite->Draw(x, y);
	}
	else
	{
		// Sino usamos Sprite
		// Dibujamos el boton con el color que el usuario defina
		glBegin(GL_POLYGON);
		glColor3f(r, g, b);
		glVertex2d(x, y);
		glVertex2d(x, y2);
		glVertex2d(x2, y2);
		glVertex2d(x2, y);
		glEnd();
	}
}

void hoBotones::OnClickDown(float _MouseX, float _MouseY) 
{
	// Cuando no se usa Sprite
	if (SpriteActivo == false)
	{
		// Comparamos por posiciones el rango del boton para ser presionado
		if (_MouseX >= x && _MouseX <= x2 && _MouseY >= y && _MouseY <= y2)
		{
			// Ejecutamos la funcion que se define al ser creado el boton
			cout << "CLICK en boton sin sprite ejemplo 2" << endl;
			funcionBoton();
		}
	}
	else
	{
		// Sino usamos Sprite
		// Comparamos por posicion y tamaño del boton el rango para que sea presionado
		if (_MouseX >= x - Sprite->width / 100.0f * Sprite->scalex / 2 && _MouseX <= Sprite->width / 100.0f * Sprite->scalex/2 && _MouseY >= y - Sprite->height / 100.0f * Sprite->scaley / 2 && _MouseY <= Sprite->height / 100.0f * Sprite->scaley/2)
		{
			// Ejecutamos la funcion que se define al ser creado el boton
			cout << "CLICK en Boton con Sprite ejemplo 1" << endl;
			funcionBoton();
		}
	}
	
}
