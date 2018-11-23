/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#pragma once

#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"

namespace cp {

class Shape {
protected:
	cpShape* shape;
	cpDataPointer data;
public:
	inline cpShape* get(){
		return shape;
}
/// Destroy and Free a shape.
	~Shape();
/// Update, cache and return the bounding box of a shape based on the body it's attached to.
	cp::BB cacheBB();
/// Update, cache and return the bounding box of a shape with an explicit transformation.
	cp::BB update(const cp::Vect& pos,const cp::Vect& rot);
/// Test if a point lies within a shape.
	cpBool pointQuery(const cp::Vect& p);
/// Perform a nearest point query. It finds the closest point on the surface of shape to a specific point.
/// The value returned is the distance between the points. A negative distance means the point is inside the shape.
	cpFloat nearestPointQuery(const cp::Vect& p,cpNearestPointQueryInfo *out);
/// Perform a segment query against a shape. @c info must be a pointer to a valid cpSegmentQueryInfo structure.
	cpBool segmentQuery(const cp::Vect& a,const cp::Vect& b,cpSegmentQueryInfo *info);
	void setBody(cp::Body *body);
	cp::Space* getSpace(void);
	cp::Body* getBody(void);
	cp::BB getBB(void);
	cpBool getSensor(void);
	void setSensor(cpBool value);
	cpFloat getElasticity(void);
	void setElasticity(cpFloat value);
	cpFloat getFriction(void);
	void setFriction(cpFloat value);
	cp::Vect getSurfaceVelocity(void);
	void setSurfaceVelocity(const cp::Vect&  value);
	cpDataPointer getUserData(void);
	void setUserData(cpDataPointer value);
	cpCollisionType getCollisionType(void);
	void setCollisionType(cpCollisionType value);
	cpGroup getGroup(void);
	void setGroup(cpGroup value);
	cpLayers getLayers(void);
	void setLayers(cpLayers value);
	Shape(cpShape* v);
	Shape(Shape&&o);
private:
//Hiding copy constructor and assignment
Shape(const Shape&);
Shape& operator=(const Shape&);

};
};//namespace cp
