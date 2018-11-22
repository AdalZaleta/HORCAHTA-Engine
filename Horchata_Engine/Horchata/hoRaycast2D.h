#pragma once
#include "hoVector.h"

class hoRaycast2D {
public:
	hoRaycast2D();
	~hoRaycast2D();

	hoVector2f ScreenToWorldPoint(hoVector2f _screen);
	hoVector2f ScreenToWorldPoint(int _x, int _y);
	hoVector2f WorldToScreenPoint(hoVector2f _world);


private:

};