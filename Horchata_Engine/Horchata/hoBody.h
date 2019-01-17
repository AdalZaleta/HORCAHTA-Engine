#pragma once

#include "Horchata.h"
#include "chipmunk/chipmunk_private.h"
#include "chipmunk/chipmunk.h"
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
	void AddShape(cpShape* _shape);
	void SetShape(cpShape* _shape, int _index, std::string _shapeName);
	hoShape GetShape(int _index);
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

	void SetAllPhysics(float _elasticity, float _friction);
	void SetPhysics(int _index, float _elasticity, float _friction);

	virtual void Update();
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