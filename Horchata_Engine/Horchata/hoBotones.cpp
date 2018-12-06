#include "hoBotones.h"
#include <GL/glew.h>


hoBotones::hoBotones()
{
}


hoBotones::~hoBotones()
{
}

void hoBotones::CreateButton(double _x1, double _y1, double _x2, double _y2)
{
	//coordenadas
	x =_x1;
	y = _x2;
	//tamaño
	y2 = _y2;
	x2 = _x2;


	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2d(x+10, y);
	glVertex2d(x+10, y2);
	glVertex2d(x2, y2);             
	glVertex2d(x2, y);
	glEnd();
	
}
void hoBotones::OnClickDown(int x, int y) {

	
}
