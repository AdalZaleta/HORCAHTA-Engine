#pragma once
#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include"hoVector.h"

class hoDrawable {
public:
	hoDrawable() {}
	~hoDrawable(){}

	virtual void Draw();

	bool isActive = true;
	float r, g, b, a;
};

class hoPoint : public hoDrawable {
public:
	hoPoint() {}
	hoPoint(hoVector2f _pos, int _size) {
		position = _pos;
		size = _size;
	}
	~hoPoint() {}

	virtual void Draw();

	hoVector2f position;
	int size;
};

class hoLine : public hoDrawable {
public:
	hoLine() {}
	hoLine(hoVector2f _point1, hoVector2f _point2) {
		point1 = _point1;
		point2 = _point2;
	}
	~hoLine() {}

	virtual void Draw();

	hoVector2f point1, point2;
};

class hoCircle : public hoDrawable {
public:
	hoCircle() {}
	hoCircle(float _x, float _y, float _r, int _seg) {
		center = hoVector2f(_x, _y);
		radius = _r;
		segments = _seg;
	}
	hoCircle(hoVector2f _pos, float _r, int _seg) {
		center = _pos;
		radius = _r;
		segments = _seg;
	}
	~hoCircle() {}

	virtual void Draw();

	hoVector2f center;
	int segments;
	float radius;
};

class hoEllipse : public hoDrawable {
public:
	hoEllipse() {}
	~hoEllipse() {}

	virtual void Draw();
};

class hoRect : public hoDrawable {
public:
	hoRect() {}
	hoRect(hoVector2f _pos, hoVector2f _sizes) {
		position = _pos;
		sizes = _sizes;
	}
	~hoRect() {}

	virtual void Draw();

	hoVector2f position, sizes;
};

enum DrawableType {
	HO_POINT,
	HO_LINE,
	HO_RECT,
	HO_CIRCLE,
	HO_ELLIPSE
};

class hoPrimitives
{
public:
	hoPrimitives();
	~hoPrimitives();

	void DrawAll();
	void SetPixelDimentions(float _w, float _h);
	void SetWindowDimentions(float _w, float _h);
	float GetWindowWidth();
	float GetWindowHeight();
	void DrawLine(float _x1, float _y1, float _x2, float _y2);
	void DrawLine(hoVector2f _pos1, hoVector2f _pos2);
	void DrawCircle(float _x, float _y, float _r, int _seg);
	void DrawCircle(hoVector2f _pos, float _r, int _seg);
	void DrawPoint(float _x, float _y, float _size);
	void DrawPoint(hoVector2f _pos, float _size);
	void DrawRect(float _x, float _y, float _w, float _h);
	void DrawRect(hoVector2f _pos, float _w, float _h);
	void DrawRect(hoVector2f _pos, hoVector2f _sizes);

private:
	int GetFirstInactive(DrawableType _type);
	float pixelWidth, pixelHeight;
	std::vector<hoDrawable*> drawables;
	std::vector<DrawableType> drawableTypes;
	float windowWidth, windowHeight;
};


/*
TODO:
	- Lines
		- poin1, point2, width, color
	- Squares
		- pos, maybe rotation, maybe round edges, color
	- Circles
		- pos, height, width, color
	- Fills
		- Flood fill at point or something
	- Point
		- a point draw;

	==
	Ponerle su draw a cada uno
	==


*/

