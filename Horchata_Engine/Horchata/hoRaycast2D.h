#pragma once
#include "hoVector.h"
#include "Chipmunk/include/chipmunk/chipmunk.h"

class hoRaycast2D {
public:
	hoRaycast2D();
	~hoRaycast2D();

	void SetScreenDimentions(float _w, float _h, float _zoom);
	hoVector2f ScreenToWorldPoint(hoVector2f _screen);
	hoVector2f ScreenToWorldPoint(int _x, int _y);

	float screenWidth, screenHeight, zoom;

private:

};