#pragma once

#include "chipmunk/chipmunk_private.h"
#include "chipmunk/chipmunk.h"
#include "chipmunk/ChipmunkDebugDraw.h"
#include <stdlib.h>
#include <string.h>

struct hoCollisionArgs{

};

struct hoShape{

	hoShape(std::string _name, cpShape *_shape) {
		name = _name;
		shape = _shape;
	};

	std::string name;
	cpShape *shape;
};

class hoBody {
public:

	hoBody();
	hoBody(hoVector2f _pos, float _angle, bool _isStatic);
	hoBody(hoVector2f _pos, float _angle, bool _isStatic, hoVector2f _vel);
	~hoBody();

	cpBody* GetBody();
	//Add shapes
	void AddShape(cpShape* _shape);
	void AddShape(cpShape* _shape, std::string _name);
	void AddCircle(hoVector2f _offset, float _r);
	void AddCircle(hoVector2f _offset, float _r, std::string _name);
	void AddRect(float _w, float _h, float _r = 0);
	void AddRect(float _w, float _h, std::string _name, float _r = 0);
	void AddPoly(int _count, cpVect* _vert, float _radius, cpTransform _transform = cpTransformIdentity);
	void AddPoly(int _count, cpVect* _vert, float _radius, std::string _name, cpTransform _transform = cpTransformIdentity);
	void AddSegment(hoVector2f _point1, hoVector2f _point2, float _radius);
	void AddSegment(hoVector2f _point1, hoVector2f _point2, float _radius, std::string _name);
	//Shape management
	void SetShape(cpShape* _shape, int _index, std::string _shapeName);
	hoShape GetShape(int _index);
	hoShape GetShape(std::string _name);
	void DeleteShape(int _index);
	void SetPosition(hoVector2f _position);
	hoVector2f GetPosition();
	void SetVelocity(hoVector2f _velocity);
	hoVector2f GetVelocity();
	hoVector2f GetAcceleration();
	void SetAgularVelocity(float _angularVelocity);
	float GetAngularVelocity();
	float GetAngularAcceleration();
	void SetEnabled(bool _enabled);
	bool IsEnabled();
	void SetDebugDraw(bool _debugDraw);
	bool IsDebugDrawEnabled();
	void SetAllCollisionTypes(int _collisionType);
	void SetCollisionType(int _index, int _collisionType);
	void SetCollisionCallback(void (*_callback)(void));
	void SetMass(float _mass);
	float GetMass();
	void SetCenterOfMass(hoVector2f _center);
	hoVector2f GetCenterOfMass();
	//void SetSprite(hoSprite* _sprite, int _index);
	//hoSprite GetSprite(int _index);
	//void AddSprite(hoSprite* _sprite);

	// Source Transforms
	cpVect GetSourcePosition();
	cpVect GetSourceVelocity();
	cpFloat GetSourceAngularVelocity();

	void SetAllPhysics(float _elasticity, float _friction);
	void SetPhysics(int _index, float _elasticity, float _friction);

	void SetAllFilters(cpShapeFilter _filter);

	virtual void Update(float _dt);

	static cpSpaceDebugColor ColorForShape(cpShape *shape, cpDataPointer data);
	static void DrawCircle(cpVect p, cpFloat a, cpFloat r, cpSpaceDebugColor outline, cpSpaceDebugColor fill, cpDataPointer data);
	static void DrawSegment(cpVect a, cpVect b, cpSpaceDebugColor color, cpDataPointer data);
	static void DrawFatSegment(cpVect a, cpVect b, cpFloat r, cpSpaceDebugColor outline, cpSpaceDebugColor fill, cpDataPointer data);
	static void DrawPolygon(int count, const cpVect *verts, cpFloat r, cpSpaceDebugColor outline, cpSpaceDebugColor fill, cpDataPointer data);
	static void DrawDot(cpFloat size, cpVect pos, cpSpaceDebugColor color, cpDataPointer data);

	void Draw();


	//methods

	/*
	- Constructor
		> position
		> rotation
		> isStatic?
	- Destructor
	- SetShape / GetShape
		> Index
		> Shape
	- AddShape
		> Shape
	- DeleteShape
		> Index
	- SetPosition / GetPosition
		> Vector2
	- SetVelocity / GetVelocity
		> Vector2
	- SetAcceleration / GetAcceleration
		> Vector2
	- SetAngularVelocity / GetAngularVelocity
		> Vector2
	- SetAngularAcceleraiton / GetAngularAcceleration
		> Vector2
	- SetEnabled / IsEnabled
		> bool
	- SetDebugDraw
		> bool
	- SetCollisionCallback
		> function
	- SetSprite / GetSprite
		> hoSprite
	- SetMass / GetMass
		> float
	- SetCenterOfMass / GetCenterOfMass
		> vector2
	- Update
	- Draw
	- AddSprite
		> *sprite
	- SetSprite
		> *sprite
	- GetSprite
		> *sprite
	*/

private:

	void UpdateBodyData();
	cpVect CCPV(float _x, float _y);
	cpVect CCPV(hoVector2f _vec);
	void ShapeFree();
	std::string GetNextDefaultName();

	cpBody *body;
	float mass;
	float rotation;
	hoVector2f centerOfMass;
	hoVector2f position;
	hoVector2f velocity;
	hoVector2f acceleration;
	float angularVelocity;
	float angularAcceleration;
	bool isStatic;
	bool enabled;
	bool debugDraw;
	bool debbugging;
	void (*callbackFunc)(void);
	std::vector <hoShape> shapes;
	//std::vector <hoSprite*> sprites;

	// Variables

	/*
	cpBody
	mass
	centerOfMass
	position
	velocity
	acceleration
	enabled
	debugging
	callback
	shapeArray
	*/

	

};