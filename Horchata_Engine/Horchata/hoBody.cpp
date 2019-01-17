#include "hoBody.h"

hoBody::hoBody()
{
	///body = cpSpaceAddBody(g_ho.space, cpBodyNew(1.0f, cpMomentForCircle(1.0f, 0.0f, 0.0f, cpvzero)));
}

hoBody::hoBody(hoVector2f _pos, float _angle, bool _isStatic) {
	position = _pos;
	rotation = _angle;
	isStatic = _isStatic; 
	velocity = hoVector2f();

	body = cpSpaceAddBody(g_ho.space, cpBodyNew(1.0f, cpMomentForCircle(1.0f, 0.0f, 0.0f, cpvzero)));

}

hoBody::hoBody(hoVector2f _pos, float _angle, bool _isStatic, hoVector2f _vel) {
	position = _pos;
	rotation = _angle;
	isStatic = _isStatic;
	velocity = _vel;

	body = cpSpaceAddBody(g_ho.space, cpBodyNew(1.0f, cpMomentForCircle(1.0f, 0.0f, 1.0f, cpvzero)));
	cpBodySetVelocity(body, CCPV(_vel.x, _vel.y));
}

hoBody::~hoBody() {
	// delet dis
}

cpBody * hoBody::GetBody()
{
	return body;
}

void hoBody::AddShape(cpShape * _shape) {
	hoShape newHoShape("test", _shape);
	shapes.push_back(newHoShape);
}

void hoBody::SetShape(cpShape * _shape, int _index, std::string _shapeName) {
	cpSpaceRemoveShape(g_ho.space, shapes[_index].shape);
	shapes[_index] = hoShape(_shapeName, _shape);
}

hoShape hoBody::GetShape(int _index) {
	return shapes[_index];
}

void hoBody::DeleteShape(int _index) {
	cpSpaceRemoveShape(g_ho.space, shapes[_index].shape);
	shapes.erase(shapes.begin()+_index);
}

void hoBody::SetPosition(hoVector2f _position)
{
	position = _position;
	cpBodySetPosition(body, CCPV(_position.x, _position.y));
}

hoVector2f hoBody::GetPosition()
{
	return position;
}

void hoBody::SetVelocity(hoVector2f _velocity)
{
	velocity = _velocity;
	cpBodySetVelocity(body, CCPV(_velocity.x, _velocity.y));
}

hoVector2f hoBody::GetVelocity()
{
	return velocity;
}

hoVector2f hoBody::GetAcceleration()
{
	return acceleration;
}

void hoBody::SetAgularVelocity(float _angularVelocity)
{
	angularVelocity = _angularVelocity;
	cpBodySetAngularVelocity(body, _angularVelocity);
}

float hoBody::GetAngularVelocity()
{
	return angularVelocity;
}

float hoBody::GetAngularAcceleration()
{
	return angularAcceleration;
}

void hoBody::SetEnabled(bool _enabled)
{
	enabled = _enabled;
}

bool hoBody::IsEnabled()
{
	return enabled;
}

void hoBody::SetDebugDraw(bool _debugDraw)
{
	debugDraw = _debugDraw;
}

bool hoBody::IsDebugDrawEnabled()
{
	return debugDraw;
}

void hoBody::SetAllCollisionTypes(int _collisionType) 
{
	for (int i = 0; i < shapes.size(); i++) {
		cpShapeSetCollisionType(shapes[i].shape, _collisionType);
	}
}

void hoBody::SetCollisionType(int _index, int _collisionType)
{
	cpShapeSetCollisionType(shapes[_index].shape, _collisionType);
}

void hoBody::SetCollisionCallback(void(*_callback)(void))
{
	callbackFunc = _callback;
}

void hoBody::SetMass(float _mass)
{
	mass = _mass;
	cpBodySetMass(body, _mass);
}

float hoBody::GetMass()
{
	return mass;
}

void hoBody::SetCenterOfMass(hoVector2f _center)
{
	centerOfMass = _center;
	cpBodySetCenterOfGravity(body, CCPV(_center.x, _center.y));
}

hoVector2f hoBody::GetCenterOfMass()
{
	return centerOfMass;
}

void hoBody::SetAllPhysics(float _elasticity, float _friction)
{
	for (int i = 0; i < shapes.size(); i++) {
		cpShapeSetElasticity(shapes[i].shape, _elasticity);
		cpShapeSetFriction(shapes[i].shape, _friction);
	}
}

void hoBody::SetPhysics(int _index, float _elasticity, float _friction)
{
	cpShapeSetElasticity(shapes[_index].shape, _elasticity);
	cpShapeSetFriction(shapes[_index].shape, _friction);
}

void hoBody::Update()
{
	UpdateBodyData();
}

void hoBody::Draw()
{
}

void hoBody::UpdateBodyData()
{
	cpVect temp = cpBodyGetPosition(body);
	position = hoVector2f(temp.x, temp.y);
}

cpVect hoBody::CCPV(float _x, float _y)
{
	cpVect temp;
	temp.x = _x;
	temp.y = _y;
	return temp;
}


