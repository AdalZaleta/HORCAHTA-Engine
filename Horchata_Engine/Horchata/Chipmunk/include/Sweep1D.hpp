/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#pragma once

#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "SpatialIndex.hpp"

namespace cp {

class Sweep1D : public SpatialIndex {
protected:
	cpSweep1D* sweep1d;
public:
	inline cpSweep1D* get(){
		return sweep1d;
}
/// Allocate and initialize a 1D sort and sweep broadphase.
	Sweep1D(cpSpatialIndexBBFunc bbfunc,cp::SpatialIndex *staticIndex);
	Sweep1D(Sweep1D&&o);
private:
//Hiding copy constructor and assignment
Sweep1D(const Sweep1D&);
Sweep1D& operator=(const Sweep1D&);

};
};//namespace cp
