#pragma once
#include <iostream>
#include <vector>
#include"hoVector.h"

class hoDrawable {
public:
	hoDrawable() {}
	~hoDrawable(){}

	virtual void Draw(float _pxw, float _pxh);

	bool isActive = true;
	float r, g, b, a;
};

class hoPoint : public hoDrawable {
public:
	hoPoint() {}
	~hoPoint() {}

	virtual void Draw(float _pxw, float _pxh);

	hoVector2f position;
};

class hoLine : public hoDrawable {
public:
	hoLine() {}
	hoLine(hoVector2f _point1, hoVector2f _point2) {
		point1 = _point1;
		point2 = _point2;
	}
	~hoLine() {}

	virtual void Draw(float _pxw, float _pxh);

	hoVector2f point1, point2;
};

class hoCircle : public hoDrawable {
public:
	hoCircle() {}
	~hoCircle() {}

	virtual void Draw(float _pxw, float _pxh);

	hoVector2f center;
	float radius;
};

class hoEllipse : public hoDrawable {
public:
	hoEllipse() {}
	~hoEllipse() {}

	virtual void Draw(float _pxw, float _pxh);
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

