/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "RotaryLimitJoint.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Constraint.hpp"
#include "Body.hpp"

namespace cp {

const cpConstraintClass *RotaryLimitJoint::getClass()
{
		return cpRotaryLimitJointGetClass();
}
RotaryLimitJoint::RotaryLimitJoint(cp::Body *a,cp::Body *b,cpFloat min,cpFloat max)
	: Constraint(cpRotaryLimitJointNew(a ? a->get() : 0,b ? b->get() : 0,min,max))
{
		constraint->data = this;
}
cpFloat RotaryLimitJoint::getMin(void)
{
		return cpRotaryLimitJointGetMin(constraint);
}
void RotaryLimitJoint::setMin(cpFloat value)
{
		cpRotaryLimitJointSetMin(constraint,value);
}
cpFloat RotaryLimitJoint::getMax(void)
{
		return cpRotaryLimitJointGetMax(constraint);
}
void RotaryLimitJoint::setMax(cpFloat value)
{
		cpRotaryLimitJointSetMax(constraint,value);
}
RotaryLimitJoint::RotaryLimitJoint(RotaryLimitJoint&&o)
	: rotarylimitjoint(o.rotarylimitjoint),
	  Constraint(std::move(o))
{
				o.rotarylimitjoint = 0;
}
};//namespace cp
