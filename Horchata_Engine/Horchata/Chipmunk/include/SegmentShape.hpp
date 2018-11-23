/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#pragma once

#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Shape.hpp"

namespace cp {

class SegmentShape : public Shape {
protected:
	cpSegmentShape* segmentshape;
public:
	inline cpSegmentShape* get(){
		return segmentshape;
}
/// Allocate and initialize a segment shape.
	SegmentShape(cp::Body *body,const cp::Vect& a,const cp::Vect& b,cpFloat radius);
	void setNeighbors(const cp::Vect& prev,const cp::Vect& next);
	cp::Vect getA(void);
	cp::Vect getB(void);
	cp::Vect getNormal(void);
	cpFloat getRadius(void);
	SegmentShape(SegmentShape&&o);
private:
//Hiding copy constructor and assignment
SegmentShape(const SegmentShape&);
SegmentShape& operator=(const SegmentShape&);

};
};//namespace cp
