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

class GearJoint : public Constraint {
protected:
	cpGearJoint* gearjoint;
public:
	inline cpGearJoint* get(){
		return gearjoint;
}
	const cpConstraintClass *getClass();
/// Allocate and initialize a gear joint.
	GearJoint(cp::Body *a,cp::Body *b,cpFloat phase,cpFloat ratio);
/// Set the ratio of a gear joint.
	void setRatio(cpFloat value);
	cpFloat getPhase(void);
	void setPhase(cpFloat value);
	cpFloat getRatio(void);
	GearJoint(GearJoint&&o);
private:
//Hiding copy constructor and assignment
GearJoint(const GearJoint&);
GearJoint& operator=(const GearJoint&);

};
};//namespace cp
