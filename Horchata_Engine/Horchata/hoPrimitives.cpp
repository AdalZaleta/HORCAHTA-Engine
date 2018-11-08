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
	int index = GetFirstInactive(HO_CIRCLE);
	if (index != -1) {
		*drawables[index] = hoCircle(hoVector2f(_x, _y), _r, _seg);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_CIRCLE);
		drawables.push_back(new hoCircle(hoVector2f(_x, _y), _r, _seg));
	}
}

void hoPrimitives::DrawCircle(hoVector2f _pos, float _r, int _seg)
{
	int index = GetFirstInactive(HO_CIRCLE);
	if (index != -1) {
		*drawables[index] = hoCircle(_pos, _r, _seg);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_CIRCLE);
		drawables.push_back(new hoCircle(_pos, _r, _seg));
	}
}

void hoPrimitives::DrawPoint(float _x, float _y, float _size)
{
	int index = GetFirstInactive(HO_POINT);
	if (index != -1) {
		*drawables[index] = hoPoint(hoVector2f(_x, _y), _size);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_POINT);
		drawables.push_back(new hoPoint(hoVector2f(_x, _y), _size));
	}
}

void hoPrimitives::DrawPoint(hoVector2f _pos, float _size)
{
	int index = GetFirstInactive(HO_POINT);
	if (index != -1) {
		*drawables[index] = hoPoint(_pos, _size);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_POINT);
		drawables.push_back(new hoPoint(_pos, _size));
	}
}

void hoPrimitives::DrawRect(float _x, float _y, float _w, float _h)
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		*drawables[index] = hoRect(hoVector2f(_x, _y), hoVector2f(_w, _h));
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(hoVector2f(_x, _y), hoVector2f(_w, _h)));
	}
}

void hoPrimitives::DrawRect(hoVector2f _pos, float _w, float _h)
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		*drawables[index] = hoRect(_pos, hoVector2f(_w, _h));
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(_pos, hoVector2f(_w, _h)));
	}
}

void hoPrimitives::DrawRect(hoVector2f _pos, hoVector2f _sizes)
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		*drawables[index] = hoRect(_pos, _sizes);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(_pos, _sizes));
	}
}

void hoPrimitives::DrawEllipse(float _x, float _y, float _w, float _h, int _seg)
{
	int index = GetFirstInactive(HO_ELLIPSE);
	if (index != -1) {
		*drawables[index] = hoEllipse(hoVector2f(_x, _y), hoVector2f(_w, _h), _seg);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_ELLIPSE);
		drawables.push_back(new hoEllipse(hoVector2f(_x, _y), hoVector2f(_w, _h), _seg));
	}
}

void hoPrimitives::DrawEllipse(hoVector2f _pos, float _w, float _h, int _seg)
{
	int index = GetFirstInactive(HO_ELLIPSE);
	if (index != -1) {
		*drawables[index] = hoEllipse(_pos, hoVector2f(_w, _h), _seg);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_ELLIPSE);
		drawables.push_back(new hoEllipse(_pos, hoVector2f(_w, _h), _seg));
	}
}

void hoPrimitives::FillCircle(float _x, float _y, float _r, int _seg)
{
	int index = GetFirstInactive(HO_CIRCLE);
	if (index != -1) {
		*drawables[index] = hoCircle(hoVector2f(_x, _y), _r, _seg);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_CIRCLE);
		drawables.push_back(new hoCircle(hoVector2f(_x, _y), _r, _seg));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillCircle(hoVector2f _pos, float _r, int _seg)
{
	int index = GetFirstInactive(HO_CIRCLE);
	if (index != -1) {
		*drawables[index] = hoCircle(_pos, _r, _seg);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_CIRCLE);
		drawables.push_back(new hoCircle(_pos, _r, _seg));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillRect(float _x, float _y, float _w, float _h)
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		*drawables[index] = hoRect(hoVector2f(_x, _y), hoVector2f(_w, _h));
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(hoVector2f(_x, _y), hoVector2f(_w, _h)));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillRect(hoVector2f _pos, float _w, float _h)
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		*drawables[index] = hoRect(_pos, hoVector2f(_w, _h));
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(_pos, hoVector2f(_w, _h)));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillRect(hoVector2f _pos, hoVector2f _sizes)
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		*drawables[index] = hoRect(_pos, _sizes);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(_pos, _sizes));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillEllipse(float _x, float _y, float _w, float _h, int _seg)
{
	int index = GetFirstInactive(HO_ELLIPSE);
	if (index != -1) {
		*drawables[index] = hoEllipse(hoVector2f(_x, _y), hoVector2f(_w, _h), _seg);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_ELLIPSE);
		drawables.push_back(new hoEllipse(hoVector2f(_x, _y), hoVector2f(_w, _h), _seg));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillEllipse(hoVector2f _pos, float _w, float _h, int _seg)
{
	int index = GetFirstInactive(HO_ELLIPSE);
	if (index != -1) {
		*drawables[index] = hoEllipse(_pos, hoVector2f(_w, _h), _seg);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_ELLIPSE);
		drawables.push_back(new hoEllipse(_pos, hoVector2f(_w, _h), _seg));
		drawables[drawables.size()-1]->fill = true;
	}
}

//With color

void hoPrimitives::DrawLine(float _x1, float _y1, float _x2, float _y2, float _rgba[4])
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		*drawables[index] = hoLine(hoVector2f(_x1, _y1), hoVector2f(_x2, _y2), _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoLine(hoVector2f(_x1, _y1), hoVector2f(_x2, _y2), _rgba));
	}
}

void hoPrimitives::DrawLine(hoVector2f _pos1, hoVector2f _pos2, float _rgba[4])
{
	int index = GetFirstInactive(HO_LINE);
	if (index != -1) {
		*drawables[index] = hoLine(_pos1, _pos2, _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_LINE);
		drawables.push_back(new hoLine(_pos1, _pos2, _rgba));
	}
}

void hoPrimitives::DrawCircle(float _x, float _y, float _r, int _seg, float _rgba[4])
{
	int index = GetFirstInactive(HO_CIRCLE);
	if (index != -1) {
		*drawables[index] = hoCircle(hoVector2f(_x, _y), _r, _seg, _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_CIRCLE);
		drawables.push_back(new hoCircle(hoVector2f(_x, _y), _r, _seg, _rgba));
	}
}

void hoPrimitives::DrawCircle(hoVector2f _pos, float _r, int _seg, float _rgba[4])
{
	int index = GetFirstInactive(HO_CIRCLE);
	if (index != -1) {
		*drawables[index] = hoCircle(_pos, _r, _seg, _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_CIRCLE);
		drawables.push_back(new hoCircle(_pos, _r, _seg, _rgba));
	}
}

void hoPrimitives::DrawPoint(float _x, float _y, float _size, float _rgba[4])
{
	int index = GetFirstInactive(HO_POINT);
	if (index != -1) {
		*drawables[index] = hoPoint(hoVector2f(_x, _y), _size, _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_POINT);
		drawables.push_back(new hoPoint(hoVector2f(_x, _y), _size, _rgba));
	}
}

void hoPrimitives::DrawPoint(hoVector2f _pos, float _size, float _rgba[4])
{
	int index = GetFirstInactive(HO_POINT);
	if (index != -1) {
		*drawables[index] = hoPoint(_pos, _size, _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_POINT);
		drawables.push_back(new hoPoint(_pos, _size, _rgba));
	}
}

void hoPrimitives::DrawRect(float _x, float _y, float _w, float _h, float _rgba[4])
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		*drawables[index] = hoRect(hoVector2f(_x, _y), hoVector2f(_w, _h), _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(hoVector2f(_x, _y), hoVector2f(_w, _h), _rgba));
	}
}

void hoPrimitives::DrawRect(hoVector2f _pos, float _w, float _h, float _rgba[4])
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		*drawables[index] = hoRect(_pos, hoVector2f(_w, _h), _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(_pos, hoVector2f(_w, _h), _rgba));
	}
}

void hoPrimitives::DrawRect(hoVector2f _pos, hoVector2f _sizes, float _rgba[4])
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		*drawables[index] = hoRect(_pos, _sizes, _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(_pos, _sizes, _rgba));
	}
}

void hoPrimitives::DrawEllipse(float _x, float _y, float _w, float _h, int _seg, float _rgba[4])
{
	int index = GetFirstInactive(HO_ELLIPSE);
	if (index != -1) {
		*drawables[index] = hoEllipse(hoVector2f(_x, _y), hoVector2f(_w, _h), _seg, _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_ELLIPSE);
		drawables.push_back(new hoEllipse(hoVector2f(_x, _y), hoVector2f(_w, _h), _seg, _rgba));
	}
}

void hoPrimitives::DrawEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rgba[4])
{
	int index = GetFirstInactive(HO_ELLIPSE);
	if (index != -1) {
		*drawables[index] = hoEllipse(_pos, hoVector2f(_w, _h), _seg, _rgba);
		drawables[index]->isActive = true;
	}
	else
	{
		drawableTypes.push_back(HO_ELLIPSE);
		drawables.push_back(new hoEllipse(_pos, hoVector2f(_w, _h), _seg, _rgba));
	}
}

void hoPrimitives::FillCircle(float _x, float _y, float _r, int _seg, float _rgba[4])
{
	int index = GetFirstInactive(HO_CIRCLE);
	if (index != -1) {
		*drawables[index] = hoCircle(hoVector2f(_x, _y), _r, _seg, _rgba);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_CIRCLE);
		drawables.push_back(new hoCircle(hoVector2f(_x, _y), _r, _seg, _rgba));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillCircle(hoVector2f _pos, float _r, int _seg, float _rgba[4])
{
	int index = GetFirstInactive(HO_CIRCLE);
	if (index != -1) {
		*drawables[index] = hoCircle(_pos, _r, _seg, _rgba);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_CIRCLE);
		drawables.push_back(new hoCircle(_pos, _r, _seg, _rgba));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillRect(float _x, float _y, float _w, float _h, float _rgba[4])
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		*drawables[index] = hoRect(hoVector2f(_x, _y), hoVector2f(_w, _h), _rgba);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(hoVector2f(_x, _y), hoVector2f(_w, _h), _rgba));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillRect(hoVector2f _pos, float _w, float _h, float _rgba[4])
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		*drawables[index] = hoRect(_pos, hoVector2f(_w, _h), _rgba);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(_pos, hoVector2f(_w, _h), _rgba));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillRect(hoVector2f _pos, hoVector2f _sizes, float _rgba[4])
{
	int index = GetFirstInactive(HO_RECT);
	if (index != -1) {
		*drawables[index] = hoRect(_pos, _sizes, _rgba);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_RECT);
		drawables.push_back(new hoRect(_pos, _sizes, _rgba));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillEllipse(float _x, float _y, float _w, float _h, int _seg, float _rgba[4])
{
	int index = GetFirstInactive(HO_ELLIPSE);
	if (index != -1) {
		*drawables[index] = hoEllipse(hoVector2f(_x, _y), hoVector2f(_w, _h), _seg, _rgba);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_ELLIPSE);
		drawables.push_back(new hoEllipse(hoVector2f(_x, _y), hoVector2f(_w, _h), _seg, _rgba));
		drawables[drawables.size() - 1]->fill = true;
	}
}

void hoPrimitives::FillEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rgba[4])
{
	int index = GetFirstInactive(HO_ELLIPSE);
	if (index != -1) {
		*drawables[index] = hoEllipse(_pos, hoVector2f(_w, _h), _seg, _rgba);
		drawables[index]->isActive = true;
		drawables[index]->fill = true;
	}
	else
	{
		drawableTypes.push_back(HO_ELLIPSE);
		drawables.push_back(new hoEllipse(_pos, hoVector2f(_w, _h), _seg, _rgba));
		drawables[drawables.size() - 1]->fill = true;
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
	hoDrawable::Draw();
	glPointSize(size);
	glBegin(GL_POINTS);
		glVertex2f(position.x, position.y);
	glEnd();
}

void hoLine::Draw()
{
	hoDrawable::Draw();
	glBegin(GL_LINES);
		glVertex2f(point1.x, point1.y);
		glVertex2f(point2.x, point2.y);
	glEnd();
}

void hoCircle::Draw()
{
	hoDrawable::Draw();
	if (!fill) {
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < segments; i++)
		{
			float degInRad = i * (360.0f / segments) * M_PI / 180.0f;
			glVertex2f(position.x + cos(degInRad)*radius, position.y + sin(degInRad)*radius);
		}
		glEnd();
	}
	else {
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < segments; i++)
		{
			float degInRad1 = i * (360.0f / segments) * M_PI / 180.0f;
			float degInRad2 = (i+1) * (360.0f / segments) * M_PI / 180.0f;
			glVertex2f(position.x + cos(degInRad1)*radius, position.y + sin(degInRad1)*radius);
			glVertex2f(position.x + cos(degInRad2)*radius, position.y + sin(degInRad2)*radius);
			glVertex2f(position.x, position.y);
		}
		glEnd();
	}
}

void hoEllipse::Draw()
{
	hoDrawable::Draw();
	if (!fill) {
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < segments; i++)
		{
			float degInRad = i * (360.0f / segments) * M_PI / 180.0f;
			glVertex2f(position.x + cos(degInRad)*sizes.x, position.y + sin(degInRad)*sizes.y);
		}
		glEnd();
	}
	else {
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < segments; i++)
		{
			float degInRad1 = i * (360.0f / segments) * M_PI / 180.0f;
			float degInRad2 = (i+1) * (360.0f / segments) * M_PI / 180.0f;
			glVertex2f(position.x + cos(degInRad1)*sizes.x, position.y + sin(degInRad1)*sizes.y);
			glVertex2f(position.x + cos(degInRad2)*sizes.x, position.y + sin(degInRad2)*sizes.y);
			glVertex2f(position.x, position.y);
		}
		glEnd();
	}
}

void hoDrawable::Draw()
{
	glColor4f(1, 1, 1, 1);
}

void hoDrawable::setColor(float _rgba[4])
{
	for (int i = 0; i < 4; i++) {
		rgba[i] = _rgba[i];
	}
}

void hoRect::Draw()
{
	hoDrawable::Draw();
	if (!fill) {
		glBegin(GL_LINE_LOOP);
			glVertex2f(position.x + sizes.x / 2.0f, position.y + sizes.y / 2.0f);
			glVertex2f(position.x + sizes.x / 2.0f, position.y - sizes.y / 2.0f);
			glVertex2f(position.x - sizes.x / 2.0f, position.y - sizes.y / 2.0f);
			glVertex2f(position.x - sizes.x / 2.0f, position.y + sizes.y / 2.0f);
		glEnd();
	}
	else {
		glBegin(GL_QUADS);
			glVertex2f(position.x + sizes.x / 2.0f, position.y + sizes.y / 2.0f);
			glVertex2f(position.x + sizes.x / 2.0f, position.y - sizes.y / 2.0f);
			glVertex2f(position.x - sizes.x / 2.0f, position.y - sizes.y / 2.0f);
			glVertex2f(position.x - sizes.x / 2.0f, position.y + sizes.y / 2.0f);
		glEnd();
	}
}
