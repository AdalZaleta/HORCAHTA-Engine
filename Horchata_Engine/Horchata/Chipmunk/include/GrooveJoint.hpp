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

class GrooveJoint : public Constraint {
protected:
	cpGrooveJoint* groovejoint;
public:
	inline cpGrooveJoint* get(){
		return groovejoint;
}
	const cpConstraintClass *getClass();
/// Allocate and initialize a groove joint.
	GrooveJoint(cp::Body *a,cp::Body *b,const cp::Vect& groove_a,const cp::Vect& groove_b,const cp::Vect& anchr2);
/// Set endpoint a of a groove joint's groove
	void setGrooveA(const cp::Vect& value);
/// Set endpoint b of a groove joint's groove
	void setGrooveB(const cp::Vect& value);
	cp::Vect getGrooveA(void);
	cp::Vect getGrooveB(void);
	cp::Vect getAnchr2(void);
	void setAnchr2(const cp::Vect&  value);
	GrooveJoint(GrooveJoint&&o);
private:
//Hiding copy constructor and assignment
GrooveJoint(const GrooveJoint&);
GrooveJoint& operator=(const GrooveJoint&);

};
};//namespace cp
