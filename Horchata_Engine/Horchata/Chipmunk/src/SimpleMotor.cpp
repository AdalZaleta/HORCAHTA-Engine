/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "SimpleMotor.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Constraint.hpp"
#include "Body.hpp"

namespace cp {

const cpConstraintClass *SimpleMotor::getClass()
{
		return cpSimpleMotorGetClass();
}
SimpleMotor::SimpleMotor(cp::Body *a,cp::Body *b,cpFloat rate)
	: Constraint(cpSimpleMotorNew(a ? a->get() : 0,b ? b->get() : 0,rate))
{
		constraint->data = this;
}
cpFloat SimpleMotor::getRate(void)
{
		return cpSimpleMotorGetRate(constraint);
}
void SimpleMotor::setRate(cpFloat value)
{
		cpSimpleMotorSetRate(constraint,value);
}
SimpleMotor::SimpleMotor(SimpleMotor&&o)
	: simplemotor(o.simplemotor),
	  Constraint(std::move(o))
{
				o.simplemotor = 0;
}
};//namespace cp
