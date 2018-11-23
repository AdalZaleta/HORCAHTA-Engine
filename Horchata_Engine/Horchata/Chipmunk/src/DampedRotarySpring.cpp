/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "DampedRotarySpring.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Constraint.hpp"
#include "Body.hpp"

namespace cp {

const cpConstraintClass *DampedRotarySpring::getClass()
{
		return cpDampedRotarySpringGetClass();
}
DampedRotarySpring::DampedRotarySpring(cp::Body *a,cp::Body *b,cpFloat restAngle,cpFloat stiffness,cpFloat damping)
	: Constraint(cpDampedRotarySpringNew(a ? a->get() : 0,b ? b->get() : 0,restAngle,stiffness,damping))
{
		constraint->data = this;
}
cpFloat DampedRotarySpring::getRestAngle(void)
{
		return cpDampedRotarySpringGetRestAngle(constraint);
}
void DampedRotarySpring::setRestAngle(cpFloat value)
{
		cpDampedRotarySpringSetRestAngle(constraint,value);
}
cpFloat DampedRotarySpring::getStiffness(void)
{
		return cpDampedRotarySpringGetStiffness(constraint);
}
void DampedRotarySpring::setStiffness(cpFloat value)
{
		cpDampedRotarySpringSetStiffness(constraint,value);
}
cpFloat DampedRotarySpring::getDamping(void)
{
		return cpDampedRotarySpringGetDamping(constraint);
}
void DampedRotarySpring::setDamping(cpFloat value)
{
		cpDampedRotarySpringSetDamping(constraint,value);
}
cpDampedRotarySpringTorqueFunc DampedRotarySpring::getSpringTorqueFunc(void)
{
		return cpDampedRotarySpringGetSpringTorqueFunc(constraint);
}
void DampedRotarySpring::setSpringTorqueFunc(cpDampedRotarySpringTorqueFunc value)
{
		cpDampedRotarySpringSetSpringTorqueFunc(constraint,value);
}
DampedRotarySpring::DampedRotarySpring(DampedRotarySpring&&o)
	: dampedrotaryspring(o.dampedrotaryspring),
	  Constraint(std::move(o))
{
				o.dampedrotaryspring = 0;
}
};//namespace cp
