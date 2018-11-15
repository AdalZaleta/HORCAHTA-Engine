#include "hoVector.h"

// -------------- Vector2f --------------

float hoVector2f::GetMagnitude()
{
	return sqrt(x * x + y * y);
}

float hoVector2f::GetSquaredMagnitude()
{
	return x * x + y * y;
}

hoVector2f hoVector2f::Normalized()
{
	float magnitude = GetMagnitude();
	return hoVector2f(x / magnitude, y / magnitude);
}

void hoVector2f::Invert()
{
	*(this) *= -1;
}

void hoVector2f::Normalize()
{
	*(this) *= (1 / GetMagnitude());
}

void hoVector2f::SetMagnitude(float _scalar)
{
	Normalize();
	*(this) *= _scalar;
}

hoVector2f hoVector2f::operator*(float _v)
{
	return hoVector2f(x*_v, y*_v);
}

void hoVector2f::operator*=(float _v)
{
	x *= _v;
	y *= _v;
}

hoVector2f hoVector2f::operator+(hoVector2f _vec)
{
	return hoVector2f(x + _vec.x, y + _vec.y);
}

void hoVector2f::operator+=(hoVector2f _vec)
{
	x += _vec.x;
	y += _vec.y;
}

hoVector2f hoVector2f::operator-(hoVector2f _vec)
{
	return hoVector2f(x-_vec.x,y-_vec.y);
}

void hoVector2f::operator-=(hoVector2f _vec)
{
	x -= _vec.x;
	y -= _vec.y;
}

float hoVector2f::DotProduct(hoVector2f _vector1, hoVector2f _vector2)
{
	return _vector1.x*_vector2.x + _vector1.y * _vector2.y;
}

hoVector2f hoVector2f::Scale(hoVector2f _vector1, hoVector2f _vector2)
{
	return hoVector2f(_vector1.x * _vector2.x, _vector1.y * _vector2.y);
}

float hoVector2f::Distance(hoVector2f _vector1, hoVector2f _vector2)
{
	return (_vector1 - _vector2).GetMagnitude();
}

float hoVector2f::Angle(hoVector2f _vector1, hoVector2f _vector2)
{
	return acos(hoVector2f::DotProduct(_vector1.Normalized(), _vector2.Normalized())) *(180/3.14159);
}
