/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "GearJoint.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Constraint.hpp"
#include "Body.hpp"

namespace cp {

const cpConstraintClass *GearJoint::getClass()
{
		return cpGearJointGetClass();
}
GearJoint::GearJoint(cp::Body *a,cp::Body *b,cpFloat phase,cpFloat ratio)
	: Constraint(cpGearJointNew(a ? a->get() : 0,b ? b->get() : 0,phase,ratio))
{
		constraint->data = this;
}
void GearJoint::setRatio(cpFloat value)
{
		cpGearJointSetRatio(Constraint::get(),value);
}
cpFloat GearJoint::getPhase(void)
{
		return cpGearJointGetPhase(constraint);
}
void GearJoint::setPhase(cpFloat value)
{
		cpGearJointSetPhase(constraint,value);
}
cpFloat GearJoint::getRatio(void)
{
		return cpGearJointGetRatio(constraint);
}
GearJoint::GearJoint(GearJoint&&o)
	: gearjoint(o.gearjoint),
	  Constraint(std::move(o))
{
				o.gearjoint = 0;
}
};//namespace cp
