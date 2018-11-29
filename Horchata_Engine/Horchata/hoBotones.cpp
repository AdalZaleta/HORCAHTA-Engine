#include "hoBotones.h"
#include <GL/glew.h>


hoBotones::hoBotones()
{
}


hoBotones::~hoBotones()
{
}

void hoBotones::CreateButton(float _x, float _y, float _w, float _h)
{
	//Coordenadas
	x = _x;
	y = _y;
	//Tamaño
	w = _w;
	h = _h;


	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2d(0,0);
	glVertex2d(0, 5);
	glVertex2d(5, 5);
	glVertex2d(5, 0);
	glEnd();
	
}

