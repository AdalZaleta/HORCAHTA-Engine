#pragma once
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;


class hoBotones
{
	public:
		hoBotones();
		~hoBotones();

		double x, y,h,w;

		double x2;
		double y2;

		bool onClick;

		void OnClickDown(float x, float y);
		void OnClickUp();

		void CreateButton(double _x1, double _y1, double _x2, double _y2, float Rojo, float Verde, float Azul);

};

