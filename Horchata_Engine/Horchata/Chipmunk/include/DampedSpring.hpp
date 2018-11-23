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

class DampedSpring : public Constraint {
protected:
	cpDampedSpring* dampedspring;
public:
	inline cpDampedSpring* get(){
		return dampedspring;
}
	const cpConstraintClass *getClass();
/// Allocate and initialize a damped spring.
	DampedSpring(cp::Body *a,cp::Body *b,const cp::Vect& anchr1,const cp::Vect& anchr2,cpFloat restLength,cpFloat stiffness,cpFloat damping);
	cp::Vect getAnchr1(void);
	void setAnchr1(const cp::Vect&  value);
	cp::Vect getAnchr2(void);
	void setAnchr2(const cp::Vect&  value);
	cpFloat getRestLength(void);
	void setRestLength(cpFloat value);
	cpFloat getStiffness(void);
	void setStiffness(cpFloat value);
	cpFloat getDamping(void);
	void setDamping(cpFloat value);
	cpDampedSpringForceFunc getSpringForceFunc(void);
	void setSpringForceFunc(cpDampedSpringForceFunc value);
	DampedSpring(DampedSpring&&o);
private:
//Hiding copy constructor and assignment
DampedSpring(const DampedSpring&);
DampedSpring& operator=(const DampedSpring&);

};
};//namespace cp
