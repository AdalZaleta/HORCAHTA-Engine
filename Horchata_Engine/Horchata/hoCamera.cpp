#include "hoCamera.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>


hoCamera::hoCamera()
{
}


hoCamera::~hoCamera()
{
}

//MUEVE CAMARA TANTO EN X COMO EN Y
void hoCamera::MoveCamera(float _x, float _y, float _time)
{
	
	x += _x * _time;
	y += _y * _time;
	glTranslatef(x , y , 0);
}


//MUEVE LA CAMARA SOLO A LA IZQUIERDA
void hoCamera::MoveCameraLeft(float _velocidad)
{
	if (_velocidad < 0)
		_velocidad = _velocidad * -1;

	x -= _velocidad;

	glTranslatef(x, 0, 0);
}

//MUEVE LA CAMARA SOLO A LA DERECHA
void hoCamera::MoveCameraRight(float _velocidad)
{
	if (_velocidad < 0)
		_velocidad = _velocidad * -1;

	x += _velocidad;
	glTranslatef(x, 0, 0);
}


//hace zoom in (acerca la camara escalando todo el mundo)
void hoCamera::ZoomIn(float _zoomd)
{
	glPushMatrix();
	zoom = _zoomd;
	glScalef(zoom, zoom, 1.0f); // scale the matrix
	
}

//hace zoomout (escalando el mundo)
void hoCamera::ZoomOut(float _zoomd)
{
	zoom += _zoomd;
	glScalef(zoom, zoom, 1.0f); // scale the matrix

}

