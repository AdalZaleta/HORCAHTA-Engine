/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "DampedSpring.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Constraint.hpp"
#include "Vect.hpp"
#include "Body.hpp"

namespace cp {

const cpConstraintClass *DampedSpring::getClass()
{
		return cpDampedSpringGetClass();
}
DampedSpring::DampedSpring(cp::Body *a,cp::Body *b,const cp::Vect& anchr1,const cp::Vect& anchr2,cpFloat restLength,cpFloat stiffness,cpFloat damping)
	: Constraint(cpDampedSpringNew(a ? a->get() : 0,b ? b->get() : 0,anchr1,anchr2,restLength,stiffness,damping))
{
		constraint->data = this;
}
cp::Vect DampedSpring::getAnchr1(void)
{
		return cpDampedSpringGetAnchr1(constraint);
}
void DampedSpring::setAnchr1(const cp::Vect&  value)
{
		cpDampedSpringSetAnchr1(constraint,value);
}
cp::Vect DampedSpring::getAnchr2(void)
{
		return cpDampedSpringGetAnchr2(constraint);
}
void DampedSpring::setAnchr2(const cp::Vect&  value)
{
		cpDampedSpringSetAnchr2(constraint,value);
}
cpFloat DampedSpring::getRestLength(void)
{
		return cpDampedSpringGetRestLength(constraint);
}
void DampedSpring::setRestLength(cpFloat value)
{
		cpDampedSpringSetRestLength(constraint,value);
}
cpFloat DampedSpring::getStiffness(void)
{
		return cpDampedSpringGetStiffness(constraint);
}
void DampedSpring::setStiffness(cpFloat value)
{
		cpDampedSpringSetStiffness(constraint,value);
}
cpFloat DampedSpring::getDamping(void)
{
		return cpDampedSpringGetDamping(constraint);
}
void DampedSpring::setDamping(cpFloat value)
{
		cpDampedSpringSetDamping(constraint,value);
}
cpDampedSpringForceFunc DampedSpring::getSpringForceFunc(void)
{
		return cpDampedSpringGetSpringForceFunc(constraint);
}
void DampedSpring::setSpringForceFunc(cpDampedSpringForceFunc value)
{
		cpDampedSpringSetSpringForceFunc(constraint,value);
}
DampedSpring::DampedSpring(DampedSpring&&o)
	: dampedspring(o.dampedspring),
	  Constraint(std::move(o))
{
				o.dampedspring = 0;
}
};//namespace cp
