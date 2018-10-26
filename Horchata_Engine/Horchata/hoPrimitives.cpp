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
	for (int i = 0; i < drawables.size(); i++)
	{
		if (drawables[i]->isActive) {
			drawables[i]->Draw();
			drawables[i]->isActive = false;
		}
	}
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

void hoPoint::Draw()
{
	printf("Hola desde point");
}

void hoLine::Draw()
{
	printf("Hola desde line");
}

void hoCircle::Draw()
{
	printf("Holda desde circle");
}

void hoEllipse::Draw()
{
	printf("hola desde ellipse");
}

void hoDrawable::Draw()
{
	printf("Hola desde hoDrawable");
	
}
