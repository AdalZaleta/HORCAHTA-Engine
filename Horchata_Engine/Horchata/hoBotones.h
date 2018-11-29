#pragma once


class hoBotones
{
	public:
		hoBotones();
		~hoBotones();

		float x, y,h,w;
		bool onClick;

		void OnClickDown();
		void OnClickUp();

		void CreateButton(float _x, float _y, float _w, float _h);

};

