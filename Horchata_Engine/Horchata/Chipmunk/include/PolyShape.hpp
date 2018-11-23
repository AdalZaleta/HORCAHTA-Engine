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

class PolyShape : public Shape {
protected:
	cpPolyShape* polyshape;
public:
	inline cpPolyShape* get(){
		return polyshape;
}
/// Allocate and initialize a polygon shape.
/// A convex hull will be created from the vertexes.
	PolyShape(cp::Body *body,int numVerts,cpVect *verts,cpVect offset);
/// Allocate and initialize a box shaped polygon shape.
	PolyShape(cp::Body *body,cpFloat width,cpFloat height);
/// Allocate and initialize an offset box shaped polygon shape.
	PolyShape(cp::Body *body,const cp::BB& box);
/// Get the number of verts in a polygon shape.
	int getNumVerts();
/// Get the @c ith vertex of a polygon shape.
	cp::Vect getVert(int idx);
	PolyShape(PolyShape&&o);
private:
//Hiding copy constructor and assignment
PolyShape(const PolyShape&);
PolyShape& operator=(const PolyShape&);

};
};//namespace cp
