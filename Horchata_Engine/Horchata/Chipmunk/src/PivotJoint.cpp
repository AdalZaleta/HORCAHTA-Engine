/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "PivotJoint.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Constraint.hpp"
#include "Vect.hpp"
#include "Body.hpp"

namespace cp {

const cpConstraintClass *PivotJoint::getClass()
{
		return cpPivotJointGetClass();
}
PivotJoint::PivotJoint(cp::Body *a,cp::Body *b,const cp::Vect& pivot)
	: Constraint(cpPivotJointNew(a ? a->get() : 0,b ? b->get() : 0,pivot))
{
		constraint->data = this;
}
PivotJoint::PivotJoint(cp::Body *a,cp::Body *b,const cp::Vect& anchr1,const cp::Vect& anchr2)
	: Constraint(cpPivotJointNew2(a ? a->get() : 0,b ? b->get() : 0,anchr1,anchr2))
{
		constraint->data = this;
}
cp::Vect PivotJoint::getAnchr1(void)
{
		return cpPivotJointGetAnchr1(constraint);
}
void PivotJoint::setAnchr1(const cp::Vect&  value)
{
		cpPivotJointSetAnchr1(constraint,value);
}
cp::Vect PivotJoint::getAnchr2(void)
{
		return cpPivotJointGetAnchr2(constraint);
}
void PivotJoint::setAnchr2(const cp::Vect&  value)
{
		cpPivotJointSetAnchr2(constraint,value);
}
PivotJoint::PivotJoint(PivotJoint&&o)
	: pivotjoint(o.pivotjoint),
	  Constraint(std::move(o))
{
				o.pivotjoint = 0;
}
};//namespace cp
