#pragma once
#include<math.h>

class hoVector2f {
public:
	hoVector2f() {
		x = 0;
		y = 0;
	};
	hoVector2f(float _x, float _y) {
		x = _x, y = _y;
	}
	~hoVector2f() {};

	//Funciones
	float GetMagnitude();
	float GetSquaredMagnitude();
	hoVector2f Normalized();

	//Metodos
	void Invert();
	void Normalize();
	void SetMagnitude(float _scalar);


	//Variables
	float x, y;

	//Sobrecarga de operadores
	hoVector2f operator*(float _v);
	void operator*=(float _v);
	hoVector2f operator+(hoVector2f _vec);
	void operator+=(hoVector2f _vec);
	hoVector2f operator-(hoVector2f _vec);
	void operator-=(hoVector2f _vec);

	//Funciones estaticas
	static float DotProduct(hoVector2f _vector1, hoVector2f _vector2);
	static hoVector2f Scale(hoVector2f _vector1, hoVector2f _vector2);
	static float Distance(hoVector2f _vector1, hoVector2f _vector2);
	static float Angle(hoVector2f _vector1, hoVector2f _vector2);
};
