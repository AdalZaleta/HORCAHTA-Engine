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

void hoPrimitives::DrawCircle(float _x, float _y, float _r, int _seg)
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		*drawables[index] = hoCircle(_x, _y, _r, _seg);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoCircle(_x, _y, _r, _seg));
	}
}

void hoPrimitives::DrawCircle(hoVector2f _pos, float _r, int _seg)
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		*drawables[index] = hoCircle(_pos, _r, _seg);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoCircle(_pos, _r, _seg));
	}
}

void hoPrimitives::DrawPoint(float _x, float _y, float _size)
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		*drawables[index] = hoPoint(hoVector2f(_x, _y), _size);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoPoint(hoVector2f(_x, _y), _size));
	}
}

void hoPrimitives::DrawPoint(hoVector2f _pos, float _size)
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		*drawables[index] = hoPoint(_pos, _size);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoPoint(_pos, _size));
	}
}

void hoPrimitives::DrawRect(float _x, float _y, float _w, float _h)
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		*drawables[index] = hoRect(hoVector2f(_x, _y), hoVector2f(_w, _h));
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoRect(hoVector2f(_x, _y), hoVector2f(_w, _h)));
	}
}

void hoPrimitives::DrawRect(hoVector2f _pos, float _w, float _h)
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		*drawables[index] = hoRect(_pos, hoVector2f(_w, _h));
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoRect(_pos, hoVector2f(_w, _h)));
	}
}

void hoPrimitives::DrawRect(hoVector2f _pos, hoVector2f _sizes)
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		*drawables[index] = hoRect(_pos, _sizes);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoRect(_pos, _sizes));
	}
}

int hoPrimitives::GetFirstInactive(DrawableType _type)
{
	for (int i = 0; i < drawables.size(); i++) {
		if (drawableTypes[i] == _type)
			if (!drawables[i]->isActive)
				return i;
	}
	return -1;
}

void hoPoint::Draw()
{
	glPointSize(size);
	glBegin(GL_POINTS);
		glVertex2f(position.x, position.y);
	glEnd();
}

void hoLine::Draw()
{
	glBegin(GL_LINES);
		glVertex2f(point1.x, point1.y);
		glVertex2f(point2.x, point2.y);
	glEnd();
}

void hoCircle::Draw()
{
	glBegin(GL_LINE_LOOP);
		for (int i = 0; i < segments; i++)
		{
			float degInRad = i*(360.0f / segments) * M_PI / 180.0f;
			glVertex2f(cos(degInRad)*radius, sin(degInRad)*radius);
		}
	glEnd();
}

void hoEllipse::Draw()
{
	printf("hola desde ellipse");
}

void hoDrawable::Draw()
{
	printf("Hola desde hoDrawable");
	
}

void hoRect::Draw()
{
	glBegin(GL_LINE_LOOP);
		glVertex2f(position.x + sizes.x / 2.0f, position.y + sizes.y / 2.0f);
		glVertex2f(position.x + sizes.x / 2.0f, position.y - sizes.y / 2.0f);
		glVertex2f(position.x - sizes.x / 2.0f, position.y - sizes.y / 2.0f);
		glVertex2f(position.x - sizes.x / 2.0f, position.y + sizes.y / 2.0f);
	glEnd();
}
