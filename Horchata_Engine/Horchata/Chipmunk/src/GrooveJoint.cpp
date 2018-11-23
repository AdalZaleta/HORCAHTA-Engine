/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "GrooveJoint.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Constraint.hpp"
#include "Vect.hpp"
#include "Body.hpp"

namespace cp {

const cpConstraintClass *GrooveJoint::getClass()
{
		return cpGrooveJointGetClass();
}
GrooveJoint::GrooveJoint(cp::Body *a,cp::Body *b,const cp::Vect& groove_a,const cp::Vect& groove_b,const cp::Vect& anchr2)
	: Constraint(cpGrooveJointNew(a ? a->get() : 0,b ? b->get() : 0,groove_a,groove_b,anchr2))
{
		constraint->data = this;
}
void GrooveJoint::setGrooveA(const cp::Vect& value)
{
		cpGrooveJointSetGrooveA(Constraint::get(),value);
}
void GrooveJoint::setGrooveB(const cp::Vect& value)
{
		cpGrooveJointSetGrooveB(Constraint::get(),value);
}
cp::Vect GrooveJoint::getGrooveA(void)
{
		return cpGrooveJointGetGrooveA(constraint);
}
cp::Vect GrooveJoint::getGrooveB(void)
{
		return cpGrooveJointGetGrooveB(constraint);
}
cp::Vect GrooveJoint::getAnchr2(void)
{
		return cpGrooveJointGetAnchr2(constraint);
}
void GrooveJoint::setAnchr2(const cp::Vect&  value)
{
		cpGrooveJointSetAnchr2(constraint,value);
}
GrooveJoint::GrooveJoint(GrooveJoint&&o)
	: groovejoint(o.groovejoint),
	  Constraint(std::move(o))
{
				o.groovejoint = 0;
}
};//namespace cp
