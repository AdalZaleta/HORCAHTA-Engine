#include "Horchata.h"
#include "hoBody.h"

//TODO: Fix Filters' Bullshit Errors

hoBody::hoBody(BodyType _type)
{
	position = hoVector2f();
	rotation = 0;
	bodyType = _type;
	velocity = hoVector2f();
	angularVelocity = 0;

	switch (_type) {
	case DYNAMIC:
		body = cpSpaceAddBody(g_ho.space, cpBodyNew(1.0f, cpMomentForCircle(1.0f, 0.0f, 1.0f, cpvzero)));
		break;
	case KINEMATIC:
		body = cpBodyNewKinematic();
		break;
	case STATIC:
		body = cpBodyNewStatic();
		break;
	default:
		body = cpSpaceAddBody(g_ho.space, cpBodyNew(1.0f, cpMomentForCircle(1.0f, 0.0f, 1.0f, cpvzero)));
		break;
	}

	UpdateCpData();
}

hoBody::hoBody(hoVector2f _pos, float _angle, BodyType _type, hoVector2f _vel) {
	position = _pos;
	rotation = _angle;
	bodyType = _type;
	velocity = hoVector2f();
	angularVelocity = 0;

	switch (_type) {
	case DYNAMIC:
		body = cpSpaceAddBody(g_ho.space, cpBodyNew(1.0f, cpMomentForCircle(1.0f, 0.0f, 1.0f, cpvzero)));
		break;
	case KINEMATIC:
		body = cpSpaceAddBody(g_ho.space, cpBodyNewKinematic());
		break;
	case STATIC:
		body = cpSpaceAddBody(g_ho.space, cpBodyNewStatic());
		break;
	default:
		body = cpSpaceAddBody(g_ho.space, cpBodyNew(1.0f, cpMomentForCircle(1.0f, 0.0f, 1.0f, cpvzero)));
		break;
	}

	//Set al cpBody data according to the values in this constructor
}

hoBody::~hoBody() {
	// Must remove these BEFORE freeing the body or you will access dangling pointers.
	ShapeFree();

	cpSpaceRemoveBody(g_ho.space, body);
	cpBodyFree(body);
}

cpBody * hoBody::GetBody()
{
	return body;
}

void hoBody::AddShape(cpShape * _shape) {
	AddShape(_shape, GetNextDefaultName());
}

void hoBody::AddShape(cpShape * _shape, std::string _name)
{
	hoShape newHoShape(_name, _shape);
	shapes.push_back(newHoShape);
}

void hoBody::AddCircle(hoVector2f _offset, float _r)
{
	AddCircle(_offset, _r,  GetNextDefaultName());
}

void hoBody::AddCircle(hoVector2f _offset, float _r, std::string _name)
{
	AddShape(cpSpaceAddShape(g_ho.space, cpCircleShapeNew(body, _r, CCPV(_offset))));
}

void hoBody::AddRect(float _w, float _h, float _r)
{
	AddRect(_w, _h, GetNextDefaultName(), _r);
}

void hoBody::AddRect(float _w, float _h, std::string _name, float _r)
{
	AddShape(cpSpaceAddShape(g_ho.space, cpBoxShapeNew(body, _w, _h, _r)));
}

void hoBody::AddPoly(int _count, cpVect * _vert, float _radius, cpTransform _transform)
{
	AddPoly(_count, _vert, _radius, GetNextDefaultName(), _transform);
}

void hoBody::AddPoly(int _count, cpVect * _vert, float _radius, std::string _name, cpTransform _transform)
{
	AddShape(cpSpaceAddShape(g_ho.space, cpPolyShapeNew(body, _count, _vert, _transform, _radius)), _name);
}

void hoBody::AddSegment(hoVector2f _point1, hoVector2f _point2, float _radius)
{
	AddSegment(_point1, _point2, _radius, GetNextDefaultName());
}

void hoBody::AddSegment(hoVector2f _point1, hoVector2f _point2, float _radius, std::string _name)
{
	AddShape(cpSpaceAddShape(g_ho.space, cpSegmentShapeNew(body, CCPV(_point1), CCPV(_point2), _radius)), _name);
}

void hoBody::SetShape(cpShape * _shape, int _index, std::string _shapeName) {
	cpSpaceRemoveShape(g_ho.space, shapes[_index].shape);
	shapes[_index] = hoShape(_shapeName, _shape);
}

hoShape hoBody::GetShape(int _index) {
	return shapes[_index];
}

hoShape hoBody::GetShape(std::string _name)
{
	for (int i = 0; i < shapes.size(); i++) {
		if (shapes[i].name == _name)
			return shapes[i];
	}
	return hoShape("not found", NULL);
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
	cpBodySetVelocity(body, CCPV(_velocity));
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

cpVect hoBody::GetSourcePosition()
{
	return cpBodyGetPosition(body);
}

cpVect hoBody::GetSourceVelocity()
{
	return cpBodyGetVelocity(body);
}

cpFloat hoBody::GetSourceAngularVelocity()
{
	return cpBodyGetAngularVelocity(body);
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

void hoBody::SetAllFilters(cpShapeFilter _filter)
{
	for (int i = 0; i < shapes.size(); i++) {
		cpShapeSetFilter(shapes[i].shape, _filter);
	}	
}

void hoBody::Update(float _dt)
{
	UpdateBodyData();
	cpSpaceStep(g_ho.space, _dt);
}

void hoBody::Draw()
{
}

void hoBody::UpdateBodyData()
{
	position = CHOV(cpBodyGetPosition(body));
	rotation = cpBodyGetAngle(body);
	velocity = CHOV(cpBodyGetVelocity(body));
	angularVelocity = cpBodyGetAngularVelocity(body);
	//La masa ni su centro no deberian cambiar todos los frames así que no la actualizo aquí

	std::cout << "X Position: " << cpBodyGetPosition(body).x << "  _  ";
	std::cout << "Y Position: " << cpBodyGetPosition(body).y << std::endl;
}

void hoBody::UpdateCpData()
{
	SetPosition(position);
	SetVelocity(velocity);
	SetAgularVelocity(angularVelocity);
	if (bodyType == DYNAMIC)
	{
		SetMass(mass);	//Aqui si actualizo la masa porque no se supone que se llame esta fución seguido, solo los dinamicos tienen masa
		SetCenterOfMass(centerOfMass);
	}
}

cpVect hoBody::CCPV(float _x, float _y)
{
	cpVect temp;
	temp.x = _x;
	temp.y = _y;
	return temp;
}

cpVect hoBody::CCPV(hoVector2f _vec)
{
	cpVect temp;
	temp.x = _vec.x;
	temp.y = _vec.y;
	return temp;
}

hoVector2f hoBody::CHOV(cpVect _vec)
{
	return hoVector2f(_vec.x, _vec.y);
}

void hoBody::ShapeFree()
{
	for (int i = 0; i < shapes.size(); i++) {
		cpSpaceRemoveShape(g_ho.space, shapes[i].shape);
		cpShapeFree(shapes[i].shape);
	}
	shapes.clear();
}

std::string hoBody::GetNextDefaultName()
{
	char temp = '0';
	temp += shapes.size();
	return "shape" + temp;
}
