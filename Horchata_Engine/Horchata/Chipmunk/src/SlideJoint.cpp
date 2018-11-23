/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "SlideJoint.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Constraint.hpp"
#include "Vect.hpp"
#include "Body.hpp"

namespace cp {

const cpConstraintClass *SlideJoint::getClass()
{
		return cpSlideJointGetClass();
}
SlideJoint::SlideJoint(cp::Body *a,cp::Body *b,const cp::Vect& anchr1,const cp::Vect& anchr2,cpFloat min,cpFloat max)
	: Constraint(cpSlideJointNew(a ? a->get() : 0,b ? b->get() : 0,anchr1,anchr2,min,max))
{
		constraint->data = this;
}
cp::Vect SlideJoint::getAnchr1(void)
{
		return cpSlideJointGetAnchr1(constraint);
}
void SlideJoint::setAnchr1(const cp::Vect&  value)
{
		cpSlideJointSetAnchr1(constraint,value);
}
cp::Vect SlideJoint::getAnchr2(void)
{
		return cpSlideJointGetAnchr2(constraint);
}
void SlideJoint::setAnchr2(const cp::Vect&  value)
{
		cpSlideJointSetAnchr2(constraint,value);
}
cpFloat SlideJoint::getMin(void)
{
		return cpSlideJointGetMin(constraint);
}
void SlideJoint::setMin(cpFloat value)
{
		cpSlideJointSetMin(constraint,value);
}
cpFloat SlideJoint::getMax(void)
{
		return cpSlideJointGetMax(constraint);
}
void SlideJoint::setMax(cpFloat value)
{
		cpSlideJointSetMax(constraint,value);
}
SlideJoint::SlideJoint(SlideJoint&&o)
	: slidejoint(o.slidejoint),
	  Constraint(std::move(o))
{
				o.slidejoint = 0;
}
};//namespace cp
