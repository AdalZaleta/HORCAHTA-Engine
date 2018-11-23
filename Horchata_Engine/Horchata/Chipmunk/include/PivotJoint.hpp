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

class PivotJoint : public Constraint {
protected:
	cpPivotJoint* pivotjoint;
public:
	inline cpPivotJoint* get(){
		return pivotjoint;
}
	const cpConstraintClass *getClass();
/// Allocate and initialize a pivot joint.
	PivotJoint(cp::Body *a,cp::Body *b,const cp::Vect& pivot);
/// Allocate and initialize a pivot joint with specific anchors.
	PivotJoint(cp::Body *a,cp::Body *b,const cp::Vect& anchr1,const cp::Vect& anchr2);
	cp::Vect getAnchr1(void);
	void setAnchr1(const cp::Vect&  value);
	cp::Vect getAnchr2(void);
	void setAnchr2(const cp::Vect&  value);
	PivotJoint(PivotJoint&&o);
private:
//Hiding copy constructor and assignment
PivotJoint(const PivotJoint&);
PivotJoint& operator=(const PivotJoint&);

};
};//namespace cp
