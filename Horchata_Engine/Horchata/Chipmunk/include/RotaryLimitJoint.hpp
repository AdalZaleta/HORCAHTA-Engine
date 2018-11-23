/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#pragma once

#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Constraint.hpp"

namespace cp {

class RotaryLimitJoint : public Constraint {
protected:
	cpRotaryLimitJoint* rotarylimitjoint;
public:
	inline cpRotaryLimitJoint* get(){
		return rotarylimitjoint;
}
	const cpConstraintClass *getClass();
/// Allocate and initialize a damped rotary limit joint.
	RotaryLimitJoint(cp::Body *a,cp::Body *b,cpFloat min,cpFloat max);
	cpFloat getMin(void);
	void setMin(cpFloat value);
	cpFloat getMax(void);
	void setMax(cpFloat value);
	RotaryLimitJoint(RotaryLimitJoint&&o);
private:
//Hiding copy constructor and assignment
RotaryLimitJoint(const RotaryLimitJoint&);
RotaryLimitJoint& operator=(const RotaryLimitJoint&);

};
};//namespace cp
