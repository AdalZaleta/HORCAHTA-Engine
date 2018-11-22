#include "hoRaycast2D.h"

hoRaycast2D::hoRaycast2D()
{
}

hoRaycast2D::~hoRaycast2D()
{
}

void hoRaycast2D::SetScreenDimentions(float _w, float _h, float _zoom)
{
	screenWidth = _w;
	screenHeight = _h;
	zoom = _zoom;
}

hoVector2f hoRaycast2D::ScreenToWorldPoint(hoVector2f _screen)
{
	float chosen = screenWidth > screenHeight ? screenWidth : screenHeight;
	float aspect = screenWidth / screenHeight;
	float x1 = (_screen.x / (chosen / (2 * aspect))) - aspect;
	float y1 = (-_screen.y / (chosen / (2 * aspect))) + 1;
	return hoVector2f(x1, y1) * zoom; //Cambiar cuando se le haga cambio a renderGL
}

hoVector2f hoRaycast2D::ScreenToWorldPoint(int _x, int _y)
{
	return ScreenToWorldPoint(hoVector2f(_x, _y));
}