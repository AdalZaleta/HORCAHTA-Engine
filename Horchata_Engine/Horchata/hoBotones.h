#pragma once


class hoBotones
{
	public:
		hoBotones();
		~hoBotones();

		double x, y,h,w;

		double x2;
		double y2;

		bool onClick;

		void OnClickDown(int x, int y);
		void OnClickUp();

		void CreateButton(double _x1, double _y1, double _x2, double _y2);

};

