#include "hoBody.h"

hoBody::hoBody(hoVector2f _pos, float _angle, bool _isStatic) {
	position = _pos;
	rotation = _angle;
	isStatic = _isStatic; 
	velocity = hoVector2f();
}

hoBody::hoBody(hoVector2f _pos, float _angle, bool _isStatic, hoVector2f _vel) {
	position = _pos;
	rotation = _angle;
	isStatic = _isStatic;
	velocity = _vel;
}

hoBody::~hoBody() {
	// delet dis
}

void hoBody::AddShape(cpShape * _shape) {
	cpShape* newShape = cpSpaceAddShape(g_ho.space, _shape);
	hoShape newHoShape("test", newShape);
	shapes.push_back(newHoShape);
}

void hoBody::SetShape(cpShape * _shape, int _index) {

}

cpShape hoBody::GetShape(int _index) {
	return cpShape();
}

void hoBody::DeleteShape(int _index) {

}
