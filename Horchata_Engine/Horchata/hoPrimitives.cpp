#include "hoPrimitives.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>


hoPrimitives::hoPrimitives()
{

}


hoPrimitives::~hoPrimitives()
{
	for (int i = 0; i < drawables.size(); i++)
		delete drawables[i];
}

void hoPrimitives::DrawAll()
{
	glPointSize(1);
	glBegin(GL_POINTS);
	for (int i = 0; i < drawables.size(); i++)
	{
		if (drawables[i]->isActive) {
			drawables[i]->Draw(pixelWidth, pixelHeight);
			drawables[i]->isActive = false;
		}
	}
	glEnd();
}

void hoPrimitives::SetPixelDimentions(float _w, float _h)
{
	pixelWidth = _w;
	pixelHeight = _h;
}

void hoPrimitives::SetWindowDimentions(float _w, float _h)
{
	windowWidth = _w;
	windowHeight = _h;
}

float hoPrimitives::GetWindowWidth()
{
	return windowWidth;
}

float hoPrimitives::GetWindowHeight()
{
	return windowHeight;
}

void hoPrimitives::DrawLine(float _x1, float _y1, float _x2, float _y2)
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		*drawables[index] = hoLine(hoVector2f(_x1, _y1), hoVector2f(_x2, _y2));
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoLine(hoVector2f(_x1, _y1), hoVector2f(_x2, _y2)));
	}
}

void hoPrimitives::DrawLine(hoVector2f _pos1, hoVector2f _pos2)
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		*drawables[index] = hoLine(_pos1, _pos2);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoLine(_pos1, _pos2));
	}
}

int hoPrimitives::GetFirstInactive(DrawableType _type)
{
	for (int i = 0; i < drawables.size(); i++) {
		if (drawableTypes[i] == _type)
			if (drawables[i]->isActive)
				return i;
	}
	return -1;
}

void hoPoint::Draw(float _pxw, float _pxh)
{
	printf("Hola desde point");
}

void hoLine::Draw(float _pxw, float _pxh)
{
	printf("Hola desde line");
	for (int i = 0; i < 200; i++) {
		glVertex2f(point1.x + i*_pxw, point1.y);
	}
}

void hoCircle::Draw(float _pxw, float _pxh)
{
	printf("Holda desde circle");
}

void hoEllipse::Draw(float _pxw, float _pxh)
{
	printf("hola desde ellipse");
}

void hoDrawable::Draw(float _pxw, float _pxh)
{
	printf("Hola desde hoDrawable");
	
}
