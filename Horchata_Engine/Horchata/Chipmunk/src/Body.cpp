/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "Body.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Arbiter.hpp"
#include "Constraint.hpp"
#include "Space.hpp"
#include <functional>
#include "Vect.hpp"
#include "Shape.hpp"
#include "Body.hpp"

class Body;
namespace {
	void BodyEachShape(cpBody *body,cpShape *shape,void *data);
	void BodyEachConstraint(cpBody *body,cpConstraint *constraint,void *data);
	void BodyEachArbiter(cpBody *body,cpArbiter *arbiter,void *data);
}

namespace cp {

Body::Body(cpFloat m,cpFloat i)
	: body(cpBodyNew(m,i)),
	  data(0)
{
		body->data = this;
}
Body::Body(void)
	: body(cpBodyNewStatic()),
	  data(0)
{
		body->data = this;
}
Body::~Body()
{
		cpBodyFree(body);
}
void Body::activate()
{
		cpBodyActivate(body);
}
void Body::activateStatic(cp::Shape *filter)
{
		cpBodyActivateStatic(body,filter ? filter->get() : 0);
}
void Body::sleep()
{
		cpBodySleep(body);
}
void Body::sleepWithGroup(cp::Body *group)
{
		cpBodySleepWithGroup(body,group ? group->get() : 0);
}
cpBool Body::isSleeping()
{
		return cpBodyIsSleeping(body);
}
cpBool Body::isStatic()
{
		return cpBodyIsStatic(body);
}
cpBool Body::isRogue()
{
		return cpBodyIsRogue(body);
}
void Body::setMass(cpFloat m)
{
		cpBodySetMass(body,m);
}
void Body::setMoment(cpFloat i)
{
		cpBodySetMoment(body,i);
}
void Body::setPos(const cp::Vect& pos)
{
		cpBodySetPos(body,pos);
}
void Body::setAngle(cpFloat a)
{
		cpBodySetAngle(body,a);
}
void Body::updateVelocity(const cp::Vect& gravity,cpFloat damping,cpFloat dt)
{
		cpBodyUpdateVelocity(body,gravity,damping,dt);
}
void Body::updatePosition(cpFloat dt)
{
		cpBodyUpdatePosition(body,dt);
}
cp::Vect Body::local2World(const cp::Vect& v)
{
		return cpBodyLocal2World(body,v);
}
cp::Vect Body::world2Local(const cp::Vect& v)
{
		return cpBodyWorld2Local(body,v);
}
void Body::resetForces()
{
		cpBodyResetForces(body);
}
void Body::applyForce(const cp::Vect& f,const cp::Vect& r)
{
		cpBodyApplyForce(body,f,r);
}
void Body::applyImpulse(const cp::Vect& j,const cp::Vect& r)
{
		cpBodyApplyImpulse(body,j,r);
}
cp::Vect Body::getVelAtWorldPoint(const cp::Vect& point)
{
		return cpBodyGetVelAtWorldPoint(body,point);
}
cp::Vect Body::getVelAtLocalPoint(const cp::Vect& point)
{
		return cpBodyGetVelAtLocalPoint(body,point);
}
cpFloat Body::kineticEnergy()
{
		return cpBodyKineticEnergy(body);
}
void Body::eachShape(cpBodyShapeIteratorFunc func,void *data)
{
		cpBodyEachShape(body,func,data);
}
void Body::eachShape(BodyShapeIteratorFunc func)
{
		cpBodyEachShape(body,*BodyEachShape,&func);
}
void Body::eachConstraint(cpBodyConstraintIteratorFunc func,void *data)
{
		cpBodyEachConstraint(body,func,data);
}
void Body::eachConstraint(BodyConstraintIteratorFunc func)
{
		cpBodyEachConstraint(body,*BodyEachConstraint,&func);
}
void Body::eachArbiter(cpBodyArbiterIteratorFunc func,void *data)
{
		cpBodyEachArbiter(body,func,data);
}
void Body::eachArbiter(BodyArbiterIteratorFunc func)
{
		cpBodyEachArbiter(body,*BodyEachArbiter,&func);
}
cp::Space* Body::getSpace(void)
{
		cpSpace *temp = cpBodyGetSpace(body);
		return static_cast<cp::Space*>(temp ? temp->data : 0);
}
cpFloat Body::getMass(void)
{
		return cpBodyGetMass(body);
}
cpFloat Body::getMoment(void)
{
		return cpBodyGetMoment(body);
}
cp::Vect Body::getPos(void)
{
		return cpBodyGetPos(body);
}
cp::Vect Body::getVel(void)
{
		return cpBodyGetVel(body);
}
void Body::setVel(const cp::Vect&  value)
{
		cpBodySetVel(body,value);
}
cp::Vect Body::getForce(void)
{
		return cpBodyGetForce(body);
}
void Body::setForce(const cp::Vect&  value)
{
		cpBodySetForce(body,value);
}
cpFloat Body::getAngle(void)
{
		return cpBodyGetAngle(body);
}
cpFloat Body::getAngVel(void)
{
		return cpBodyGetAngVel(body);
}
void Body::setAngVel(cpFloat value)
{
		cpBodySetAngVel(body,value);
}
cpFloat Body::getTorque(void)
{
		return cpBodyGetTorque(body);
}
void Body::setTorque(cpFloat value)
{
		cpBodySetTorque(body,value);
}
cp::Vect Body::getRot(void)
{
		return cpBodyGetRot(body);
}
cpFloat Body::getVelLimit(void)
{
		return cpBodyGetVelLimit(body);
}
void Body::setVelLimit(cpFloat value)
{
		cpBodySetVelLimit(body,value);
}
cpFloat Body::getAngVelLimit(void)
{
		return cpBodyGetAngVelLimit(body);
}
void Body::setAngVelLimit(cpFloat value)
{
		cpBodySetAngVelLimit(body,value);
}
cpDataPointer Body::getUserData(void)
{
		return data;
}
void Body::setUserData(cpDataPointer value)
{
		data = value;
}
Body::Body(cpBody* v)
	: data(0)
{
		body = v;
		data = v->data;
		v->data = this;
}
Body::Body(Body&&o)
	: body(o.body),
	  data(o.data)
{
				o.body = 0;
		o.data = 0;
		get()->data = this;
}
};//namespace cp
namespace {
	void BodyEachShape(cpBody *body,cpShape *shape,void *data)
	{
				(*reinterpret_cast<std::function<void (cp::Body *,cp::Shape *)> *>(data))((cp::Body *)body->data,(cp::Shape *)shape->data);
	}

	void BodyEachConstraint(cpBody *body,cpConstraint *constraint,void *data)
	{
				(*reinterpret_cast<std::function<void (cp::Body *,cp::Constraint *)> *>(data))((cp::Body *)body->data,(cp::Constraint *)constraint->data);
	}

	void BodyEachArbiter(cpBody *body,cpArbiter *arbiter,void *data)
	{
		cp::Arbiter tempArbiter(arbiter);
		(*reinterpret_cast<std::function<void (cp::Body *,cp::Arbiter *)> *>(data))((cp::Body *)body->data,&tempArbiter);
	}

}

