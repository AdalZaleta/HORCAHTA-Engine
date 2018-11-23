/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "Shape.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Space.hpp"
#include "Vect.hpp"
#include "BB.hpp"
#include "Body.hpp"

namespace cp {

Shape::~Shape()
{
		cpShapeFree(shape);
}
cp::BB Shape::cacheBB()
{
		return cpShapeCacheBB(shape);
}
cp::BB Shape::update(const cp::Vect& pos,const cp::Vect& rot)
{
		return cpShapeUpdate(shape,pos,rot);
}
cpBool Shape::pointQuery(const cp::Vect& p)
{
		return cpShapePointQuery(shape,p);
}
cpFloat Shape::nearestPointQuery(const cp::Vect& p,cpNearestPointQueryInfo *out)
{
		return cpShapeNearestPointQuery(shape,p,out);
}
cpBool Shape::segmentQuery(const cp::Vect& a,const cp::Vect& b,cpSegmentQueryInfo *info)
{
		return cpShapeSegmentQuery(shape,a,b,info);
}
void Shape::setBody(cp::Body *body)
{
		cpShapeSetBody(shape,body ? body->get() : 0);
}
cp::Space* Shape::getSpace(void)
{
		cpSpace *temp = cpShapeGetSpace(shape);
		return static_cast<cp::Space*>(temp ? temp->data : 0);
}
cp::Body* Shape::getBody(void)
{
		cpBody *temp = cpShapeGetBody(shape);
		return static_cast<cp::Body*>(temp ? temp->data : 0);
}
cp::BB Shape::getBB(void)
{
		return cpShapeGetBB(shape);
}
cpBool Shape::getSensor(void)
{
		return cpShapeGetSensor(shape);
}
void Shape::setSensor(cpBool value)
{
		cpShapeSetSensor(shape,value);
}
cpFloat Shape::getElasticity(void)
{
		return cpShapeGetElasticity(shape);
}
void Shape::setElasticity(cpFloat value)
{
		cpShapeSetElasticity(shape,value);
}
cpFloat Shape::getFriction(void)
{
		return cpShapeGetFriction(shape);
}
void Shape::setFriction(cpFloat value)
{
		cpShapeSetFriction(shape,value);
}
cp::Vect Shape::getSurfaceVelocity(void)
{
		return cpShapeGetSurfaceVelocity(shape);
}
void Shape::setSurfaceVelocity(const cp::Vect&  value)
{
		cpShapeSetSurfaceVelocity(shape,value);
}
cpDataPointer Shape::getUserData(void)
{
		return data;
}
void Shape::setUserData(cpDataPointer value)
{
		data = value;
}
cpCollisionType Shape::getCollisionType(void)
{
		return cpShapeGetCollisionType(shape);
}
void Shape::setCollisionType(cpCollisionType value)
{
		cpShapeSetCollisionType(shape,value);
}
cpGroup Shape::getGroup(void)
{
		return cpShapeGetGroup(shape);
}
void Shape::setGroup(cpGroup value)
{
		cpShapeSetGroup(shape,value);
}
cpLayers Shape::getLayers(void)
{
		return cpShapeGetLayers(shape);
}
void Shape::setLayers(cpLayers value)
{
		cpShapeSetLayers(shape,value);
}
Shape::Shape(cpShape* v)
	: data(0)
{
		shape = v;
		data = v->data;
		v->data = this;
}
Shape::Shape(Shape&&o)
	: shape(o.shape),
	  data(o.data)
{
				o.shape = 0;
		o.data = 0;
		get()->data = this;
}
};//namespace cp
