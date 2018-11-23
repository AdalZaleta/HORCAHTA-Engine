/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "RatchetJoint.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Constraint.hpp"
#include "Body.hpp"

namespace cp {

const cpConstraintClass *RatchetJoint::getClass()
{
		return cpRatchetJointGetClass();
}
RatchetJoint::RatchetJoint(cp::Body *a,cp::Body *b,cpFloat phase,cpFloat ratchet)
	: Constraint(cpRatchetJointNew(a ? a->get() : 0,b ? b->get() : 0,phase,ratchet))
{
		constraint->data = this;
}
cpFloat RatchetJoint::getAngle(void)
{
		return cpRatchetJointGetAngle(constraint);
}
void RatchetJoint::setAngle(cpFloat value)
{
		cpRatchetJointSetAngle(constraint,value);
}
cpFloat RatchetJoint::getPhase(void)
{
		return cpRatchetJointGetPhase(constraint);
}
void RatchetJoint::setPhase(cpFloat value)
{
		cpRatchetJointSetPhase(constraint,value);
}
cpFloat RatchetJoint::getRatchet(void)
{
		return cpRatchetJointGetRatchet(constraint);
}
void RatchetJoint::setRatchet(cpFloat value)
{
		cpRatchetJointSetRatchet(constraint,value);
}
RatchetJoint::RatchetJoint(RatchetJoint&&o)
	: ratchetjoint(o.ratchetjoint),
	  Constraint(std::move(o))
{
				o.ratchetjoint = 0;
}
};//namespace cp
