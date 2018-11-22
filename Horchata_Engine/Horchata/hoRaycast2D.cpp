#include "hoRaycast2D.h"

hoRaycast2D::hoRaycast2D()
{
}

hoRaycast2D::~hoRaycast2D()
{
}

hoVector2f hoRaycast2D::ScreenToWorldPoint(hoVector2f _screen)
{
	return hoVector2f(0, 0);
}

hoVector2f hoRaycast2D::ScreenToWorldPoint(int _x, int _y)
{
	return ScreenToWorldPoint(hoVector2f(_x, _y));
}

hoVector2f hoRaycast2D::WorldToScreenPoint(hoVector2f _world)
{
	return hoVector2f();
}
