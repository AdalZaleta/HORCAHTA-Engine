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

class SlideJoint : public Constraint {
protected:
	cpSlideJoint* slidejoint;
public:
	inline cpSlideJoint* get(){
		return slidejoint;
}
	const cpConstraintClass *getClass();
/// Allocate and initialize a slide joint.
	SlideJoint(cp::Body *a,cp::Body *b,const cp::Vect& anchr1,const cp::Vect& anchr2,cpFloat min,cpFloat max);
	cp::Vect getAnchr1(void);
	void setAnchr1(const cp::Vect&  value);
	cp::Vect getAnchr2(void);
	void setAnchr2(const cp::Vect&  value);
	cpFloat getMin(void);
	void setMin(cpFloat value);
	cpFloat getMax(void);
	void setMax(cpFloat value);
	SlideJoint(SlideJoint&&o);
private:
//Hiding copy constructor and assignment
SlideJoint(const SlideJoint&);
SlideJoint& operator=(const SlideJoint&);

};
};//namespace cp
