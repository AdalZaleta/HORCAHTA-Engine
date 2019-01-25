#pragma once
#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include"hoVector.h"

/*
	En la funcion RenderGL::render() solo se tiene que poner el tipo de primitiva que quieres y por supuesto sus variables

	Ejemplo:
	g_ho.primitives.FillRectColor(hoVector2f(-300, 0), 30, 60, g_ho.colorchata.moonstone);

*/

class hoDrawable {		//Clase padre de un objeto que se puede dibujar
public:
	hoDrawable() {}
	~hoDrawable(){}

	virtual void Draw();

	bool isActive = true, fill = false;		//isActive es un booleano que indica si la primitiva deberia ser dibujada o no, fill indica si deberia de ser rellenada o no
	float rgba[4] = { 1, 1, 1, 1 };			//Valor de color que cada quien guarda
	float rotation;							//Valor de rotación en el unico eje que puede rotar
protected:
	void setColor(float _rgba[4]);			//Seteo el color
};

class hoPoint : public hoDrawable {		//Para dibujar puntos
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

	hoVector2f position;			//Posicion en (x,y) de el punto
	int size;						//Tamaño del punto, en valores de OpenGl
};

class hoLine : public hoDrawable {		//Lineas
public:
	hoLine() {}
	hoLine(hoVector2f _point1, hoVector2f _point2) {
		point1 = _point1;
		point2 = _point2;
	}
	hoLine(hoVector2f _point1, hoVector2f _point2, float _rgba[4]) {
		point1 = _point1;
		point2 = _point2;
		setColor(_rgba);
	}
	~hoLine() {}

	virtual void Draw();

	hoVector2f point1, point2;		//Punto A y B de la linea
};

class hoCircle : public hoDrawable {	//Circulo
public:
	hoCircle() {}
	hoCircle(hoVector2f _pos, float _r, int _seg) {
		position = _pos;
		radius = _r;
		segments = _seg;
	}
	hoCircle(hoVector2f _pos, float _r, int _seg, float _rgba[4]) {
		position = _pos;
		radius = _r;
		segments = _seg;
		setColor(_rgba);
	}
	~hoCircle() {}

	virtual void Draw();

	hoVector2f position;		//Centro del circulo
	int segments;				//Segmentos en los que se va a dibujar
	float radius;				//Radio del circulo
};

class hoEllipse : public hoDrawable {	//Elipse
public:
	hoEllipse() {}
	hoEllipse(hoVector2f _pos, hoVector2f _sizes, int _seg) {
		position = _pos;
		sizes = _sizes;
		segments = _seg;
	}
	hoEllipse(hoVector2f _pos, hoVector2f _sizes, int _seg, float _rgba[4]) {
		position = _pos;
		sizes = _sizes;
		segments = _seg;
		setColor(_rgba);
	}
	~hoEllipse() {}

	virtual void Draw();

	int segments;				//Segmentos en los que se va a dibujar
	hoVector2f position, sizes;	//Vector con posicion del centro de la elipse y vector con ancho y alto en X y Y respectivamente
};

class hoRect : public hoDrawable {	//Rectangulos o cuardados
public:
	hoRect() {}
	hoRect(hoVector2f _pos, hoVector2f _sizes) {
		position = _pos;
		sizes = _sizes;
	}
	hoRect(hoVector2f _pos, hoVector2f _sizes, float _rgba[4]) {
		position = _pos;
		sizes = _sizes;
		setColor(_rgba);
	}
	~hoRect() {}

	virtual void Draw();

	hoVector2f position, sizes;		//Vector con posicion del centro de el rect y vector con ancho y alto en X y Y respectivamente
};

enum DrawableType {		//Enumerator de tipos, lo uso para saber de que tipo es lo que tengo guardado en el vector drawables, si alguien sabe una mejor manera ahi me avisa
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

	void DrawAll();									//Manda a dibujar todos los drawables guardados
	void SetPixelDimentions(float _w, float _h);	//No lo uso, me dice el tamaño en unidades de opengl de un pixel en la pantalla
	void SetWindowDimentions(float _w, float _h);	//No lo uso, para setear el tamaño de la pantalla
	float GetWindowWidth();							//Regresa ancho de la pantalla
	float GetWindowHeight();						//Regresa la altura de la pantalla
	//Draws
	/*
		Funciones para llamar a dibujar una primitiva.
			- Todas las primitivas tienen la función basica, que solo dibuja con GL_LINES
			- Todas las primitivas tienen sobrecargas de la function base en las que pueden mandar tanto hoVector2f como dos valores flotantes
			- Todas las funciones de draw basicas tienen una alternativa en donde le puedes mandar un array de floats de tamaño 4 representando el rgba con valores de 0 a 1
			-Circulos, rectangulos y elipses tienen una function Fill para ser rellenadas, se dibujan con GL_TRIANGLES
	*/

	void DrawLine(float _x1, float _y1, float _x2, float _y2);			
	void DrawLine(hoVector2f _pos1, hoVector2f _pos2);
	void DrawLine(hoVector2f _pos1, hoVector2f _pos2, float _rot);
	void DrawCircle(float _x, float _y, float _r, int _seg);
	void DrawCircle(hoVector2f _pos, float _r, int _seg);
	void DrawPoint(float _x, float _y, float _size);
	void DrawPoint(hoVector2f _pos, float _size);
	void DrawRect(float _x, float _y, float _w, float _h);
	void DrawRect(hoVector2f _pos, float _w, float _h);
	void DrawRect(hoVector2f _pos, hoVector2f _sizes);
	void DrawRect(hoVector2f _pos, float _w, float _h, float _rot);
	void DrawEllipse(float _x, float _y, float _W, float _h, int _seg);
	void DrawEllipse(hoVector2f _pos, float _w, float _h, int _seg);
	void DrawEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rot);
	//Fills
	void FillCircle(float _x, float _y, float _r, int _seg);
	void FillCircle(hoVector2f _pos, float _r, int _seg);
	void FillRect(float _x, float _y, float _w, float _h);
	void FillRect(hoVector2f _pos, float _w, float _h);
	void FillRect(hoVector2f _pos, hoVector2f _sizes);
	void FillRect(hoVector2f _pos, float _w, float _h, float _rot);
	void FillEllipse(float _x, float _y, float _W, float _h, int _seg);
	void FillEllipse(hoVector2f _pos, float _w, float _h, int _seg);
	void FillEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rot);
	//Same but with color
	void DrawLine(float _x1, float _y1, float _x2, float _y2, float _rgba[4]);
	void DrawLine(hoVector2f _pos1, hoVector2f _pos2, float _rgba[4]);
	void DrawLine(hoVector2f _pos1, hoVector2f _pos2, float _rot, float _rgba[4]);
	void DrawCircle(float _x, float _y, float _r, int _seg, float _rgba[4]);
	void DrawCircle(hoVector2f _pos, float _r, int _seg, float _rgba[4]);
	void DrawPoint(float _x, float _y, float _size, float _rgba[4]);
	void DrawPoint(hoVector2f _pos, float _size, float _rgba[4]);
	void DrawRect(float _x, float _y, float _w, float _h, float _rgba[4]);
	void DrawRect(hoVector2f _pos, float _w, float _h, float _rgba[4]);
	void DrawRect(hoVector2f _pos, hoVector2f _sizes, float _rgba[4]);
	void DrawRect(hoVector2f _pos, float _w, float _h, float _rot, float _rgba[4]);
	void DrawEllipse(float _x, float _y, float _W, float _h, int _seg, float _rgba[4]);
	void DrawEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rgba[4]);
	void DrawEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rot, float _rgba[4]);
	//Fills with color
	void FillCircle(float _x, float _y, float _r, int _seg, float _rgba[4]);
	void FillCircle(hoVector2f _pos, float _r, int _seg, float _rgba[4]);
	void FillRectColor(float _x, float _y, float _w, float _h, float _rgba[4]);
	void FillRectColor(hoVector2f _pos, float _w, float _h, float _rgba[4]);
	void FillRectColor(hoVector2f _pos, hoVector2f _sizes, float _rgba[4]);
	void FillRectColor(hoVector2f _pos, float _w, float _h, float _rot, float _rgba[4]);
	void FillEllipse(float _x, float _y, float _W, float _h, int _seg, float _rgba[4]);
	void FillEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rgba[4]);
	void FillEllipse(hoVector2f _pos, float _w, float _h, int _seg, float _rot, float _rgba[4]);


private:
	int GetFirstInactive(DrawableType _type);		//Busca el primer drawable inactivo en mi vector de drawables, para reutilizarlo como pool.
	float pixelWidth, pixelHeight;					//Ancho y alto de un pixel en unidades de OpenGl
	std::vector<hoDrawable*> drawables;				//Vector de punteros de drawables, aqui se guardan drawables del tipo que pidas usando las funciones de draw o de fill. Es puntero para poder llamar las funciones de draw de los hijos.
	std::vector<DrawableType> drawableTypes;		//Guardo de que tipo es el drawable paralelo en el otro vector, esto es para poder reutilizarlos.
	float windowWidth, windowHeight;				//Ancho y alto de la pantalla
};