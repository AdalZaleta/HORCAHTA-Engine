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

class DampedRotarySpring : public Constraint {
protected:
	cpDampedRotarySpring* dampedrotaryspring;
public:
	inline cpDampedRotarySpring* get(){
		return dampedrotaryspring;
}
	const cpConstraintClass *getClass();
/// Allocate and initialize a damped rotary spring.
	DampedRotarySpring(cp::Body *a,cp::Body *b,cpFloat restAngle,cpFloat stiffness,cpFloat damping);
	cpFloat getRestAngle(void);
	void setRestAngle(cpFloat value);
	cpFloat getStiffness(void);
	void setStiffness(cpFloat value);
	cpFloat getDamping(void);
	void setDamping(cpFloat value);
	cpDampedRotarySpringTorqueFunc getSpringTorqueFunc(void);
	void setSpringTorqueFunc(cpDampedRotarySpringTorqueFunc value);
	DampedRotarySpring(DampedRotarySpring&&o);
private:
//Hiding copy constructor and assignment
DampedRotarySpring(const DampedRotarySpring&);
DampedRotarySpring& operator=(const DampedRotarySpring&);

};
};//namespace cp
