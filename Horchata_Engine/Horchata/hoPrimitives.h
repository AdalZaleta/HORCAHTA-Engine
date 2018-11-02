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

	bool isActive = true, fill = false;
	float rgba[4] = { 1, 1, 1, 1 };
protected:
	void setColor(float _rgba[4]);
};

class hoPoint : public hoDrawable {
public:
	hoPoint() {}
	hoPoint(hoVector2f _pos, int _size) {
		position = _pos;
		size = _size;
	}
	hoPoint(hoVector2f _pos, int _size, float _rgba[4]) {
		position = _pos;
		size = _size;
		setColor(_rgba);
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
	hoLine(hoVector2f _point1, hoVector2f _point2, int _rgba[4]) {
		point1 = _point1;
		point2 = _point2;
		setColor(_rgba);
	}
	~hoLine() {}

	virtual void Draw();

	hoVector2f point1, point2;
};

class hoCircle : public hoDrawable {
public:
	hoCircle() {}
	hoCircle(hoVector2f _pos, float _r, int _seg) {
		position = _pos;
		radius = _r;
		segments = _seg;
	}
	hoCircle(hoVector2f _pos, float _r, int _seg, int _rgba[4]) {
		position = _pos;
		radius = _r;
		segments = _seg;
		setColor(_rgba);
	}
	~hoCircle() {}

	virtual void Draw();

	hoVector2f position;
	int segments;
	float radius;
};

class hoEllipse : public hoDrawable {
public:
	hoEllipse() {}
	hoEllipse(hoVector2f _pos, hoVector2f _sizes, int _seg) {
		position = _pos;
		sizes = _sizes;
		segments = _seg;
	}
	hoEllipse(hoVector2f _pos, hoVector2f _sizes, int _seg, int _rgba[4]) {
		position = _pos;
		sizes = _sizes;
		segments = _seg;
		setColor(_rgba);
	}
	~hoEllipse() {}

	virtual void Draw();

	int segments;
	hoVector2f position, sizes;
};

class hoRect : public hoDrawable {
public:
	hoRect() {}
	hoRect(hoVector2f _pos, hoVector2f _sizes) {
		position = _pos;
		sizes = _sizes;
	}
	hoRect(hoVector2f _pos, hoVector2f _sizes, int _rgba[4]) {
		position = _pos;
		sizes = _sizes;
		setColor(_rgba);
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
	//Draws
	void DrawLine(float _x1, float _y1, float _x2, float _y2);
	void DrawLine(hoVector2f _pos1, hoVector2f _pos2);
	void DrawCircle(float _x, float _y, float _r, int _seg);
	void DrawCircle(hoVector2f _pos, float _r, int _seg);
	void DrawPoint(float _x, float _y, float _size);
	void DrawPoint(hoVector2f _pos, float _size);
	void DrawRect(float _x, float _y, float _w, float _h);
	void DrawRect(hoVector2f _pos, float _w, float _h);
	void DrawRect(hoVector2f _pos, hoVector2f _sizes);
	void DrawEllipse(float _x, float _y, float _W, float _h, int _seg);
	void DrawEllipse(hoVector2f _pos, float _w, float _h, int _seg);
	//Fills
	void FillCircle(float _x, float _y, float _r, int _seg);
	void FillCircle(hoVector2f _pos, float _r, int _seg);
	void FillRect(float _x, float _y, float _w, float _h);
	void FillRect(hoVector2f _pos, float _w, float _h);
	void FillRect(hoVector2f _pos, hoVector2f _sizes);
	void FillEllipse(float _x, float _y, float _W, float _h, int _seg);
	void FillEllipse(hoVector2f _pos, float _w, float _h, int _seg);
	//Same but with color
	void DrawLine(float _x1, float _y1, float _x2, float _y2, int _rgba[4]);
	void DrawLine(hoVector2f _pos1, hoVector2f _pos2, int _rgba[4]);
	void DrawCircle(float _x, float _y, float _r, int _seg, int _rgba[4]);
	void DrawCircle(hoVector2f _pos, float _r, int _seg, int _rgba[4]);
	void DrawPoint(float _x, float _y, float _size, int _rgba[4]);
	void DrawPoint(hoVector2f _pos, float _size, int _rgba[4]);
	void DrawRect(float _x, float _y, float _w, float _h, int _rgba[4]);
	void DrawRect(hoVector2f _pos, float _w, float _h, int _rgba[4]);
	void DrawRect(hoVector2f _pos, hoVector2f _sizes, int _rgba[4]);
	void DrawEllipse(float _x, float _y, float _W, float _h, int _seg, int _rgba[4]);
	void DrawEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rgba[4]);
	//Fills with color
	void FillCircle(float _x, float _y, float _r, int _seg, float _rgba[4]);
	void FillCircle(hoVector2f _pos, float _r, int _seg, float _rgba[4]);
	void FillRect(float _x, float _y, float _w, float _h, float _rgba[4]);
	void FillRect(hoVector2f _pos, float _w, float _h, float _rgba[4]);
	void FillRect(hoVector2f _pos, hoVector2f _sizes, float _rgba[4]);
	void FillEllipse(float _x, float _y, float _W, float _h, int _seg, float _rgba[4]);
	void FillEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rgba[4]);


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

