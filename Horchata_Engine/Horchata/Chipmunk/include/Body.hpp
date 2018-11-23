/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#pragma once

#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include <functional>

namespace cp {
/// Body/shape iterator callback function type. 
	typedef std::function<void (cp::Body *,cp::Shape *)> BodyShapeIteratorFunc ;
/// Body/constraint iterator callback function type. 
	typedef std::function<void (cp::Body *,cp::Constraint *)> BodyConstraintIteratorFunc ;
/// Body/arbiter iterator callback function type. 
	typedef std::function<void (cp::Body *,cp::Arbiter *)> BodyArbiterIteratorFunc ;

class Body {
friend class Space;
protected:
	cpBody* body;
	cpDataPointer data;
public:
	inline cpBody* get(){
		return body;
}
/// Allocate and initialize a cpBody.
	Body(cpFloat m,cpFloat i);
/// Allocate and initialize a static cpBody.
	Body(void);
/// Destroy and free a cpBody.
	~Body();
// Defined in cpSpace.c
/// Wake up a sleeping or idle body.
	void activate();
/// Wake up any sleeping or idle bodies touching a static body.
	void activateStatic(cp::Shape *filter);
/// Force a body to fall asleep immediately.
	void sleep();
/// Force a body to fall asleep immediately along with other bodies in a group.
	void sleepWithGroup(cp::Body *group);
/// Returns true if the body is sleeping.
	cpBool isSleeping();
/// Returns true if the body is static.
	cpBool isStatic();
/// Returns true if the body has not been added to a space.
	cpBool isRogue();
/// Set the mass of a body.
	void setMass(cpFloat m);
/// Set the moment of a body.
	void setMoment(cpFloat i);
/// Set the position of a body.
	void setPos(const cp::Vect& pos);
/// Set the angle of a body.
	void setAngle(cpFloat a);
/// Default Integration functions.
	void updateVelocity(const cp::Vect& gravity,cpFloat damping,cpFloat dt);
	void updatePosition(cpFloat dt);
/// Convert body relative/local coordinates to absolute/world coordinates.
	cp::Vect local2World(const cp::Vect& v);
/// Convert body absolute/world coordinates to  relative/local coordinates.
	cp::Vect world2Local(const cp::Vect& v);
/// Set the forces and torque or a body to zero.
	void resetForces();
/// Apply an force (in world coordinates) to the body at a point relative to the center of gravity (also in world coordinates).
	void applyForce(const cp::Vect& f,const cp::Vect& r);
/// Apply an impulse (in world coordinates) to the body at a point relative to the center of gravity (also in world coordinates).
	void applyImpulse(const cp::Vect& j,const cp::Vect& r);
/// Get the velocity on a body (in world units) at a point on the body in world coordinates.
	cp::Vect getVelAtWorldPoint(const cp::Vect& point);
/// Get the velocity on a body (in world units) at a point on the body in local coordinates.
	cp::Vect getVelAtLocalPoint(const cp::Vect& point);
/// Get the kinetic energy of a body.
	cpFloat kineticEnergy();
	void eachShape(cpBodyShapeIteratorFunc func,void *data);
/// Call @c func once for each shape attached to @c body and added to the space.
	void eachShape(BodyShapeIteratorFunc func);
	void eachConstraint(cpBodyConstraintIteratorFunc func,void *data);
/// Call @c func once for each constraint attached to @c body and added to the space.
	void eachConstraint(BodyConstraintIteratorFunc func);
	void eachArbiter(cpBodyArbiterIteratorFunc func,void *data);
/// Call @c func once for each arbiter that is currently active on the body.
	void eachArbiter(BodyArbiterIteratorFunc func);
	cp::Space* getSpace(void);
	cpFloat getMass(void);
	cpFloat getMoment(void);
	cp::Vect getPos(void);
	cp::Vect getVel(void);
	void setVel(const cp::Vect&  value);
	cp::Vect getForce(void);
	void setForce(const cp::Vect&  value);
	cpFloat getAngle(void);
	cpFloat getAngVel(void);
	void setAngVel(cpFloat value);
	cpFloat getTorque(void);
	void setTorque(cpFloat value);
	cp::Vect getRot(void);
	cpFloat getVelLimit(void);
	void setVelLimit(cpFloat value);
	cpFloat getAngVelLimit(void);
	void setAngVelLimit(cpFloat value);
	cpDataPointer getUserData(void);
	void setUserData(cpDataPointer value);
	Body(cpBody* v);
	Body(Body&&o);
private:
//Hiding copy constructor and assignment
Body(const Body&);
Body& operator=(const Body&);

};
};//namespace cp
