#pragma once

#include "Horchata/Horchata.h"
#include "chipmunk/chipmunk.h"
#include <stdlib.h>

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

	hoBody(hoVector2f _pos, float _angle, bool _isStatic);
	hoBody(hoVector2f _pos, float _angle, bool _isStatic, hoVector2f _vel);
	~hoBody();

	void AddShape(cpShape* _shape);
	void SetShape(cpShape* _shape, int _index);
	cpShape GetShape(int _index);
	void DeleteShape(int _index);



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
	*/

private:

	cpBody *body;
	float mass;
	float rotation;
	hoVector2f centerOfMass;
	hoVector2f position;
	hoVector2f velocity;
	hoVector2f acceleration;
	bool isStatic;
	bool enabled;
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