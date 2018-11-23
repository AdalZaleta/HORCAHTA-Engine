/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "PolyShape.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "Shape.hpp"
#include "Vect.hpp"
#include "BB.hpp"
#include "Body.hpp"

namespace cp {

PolyShape::PolyShape(cp::Body *body,int numVerts,cpVect *verts,cpVect offset)
	: Shape(cpPolyShapeNew(body ? body->get() : 0,numVerts,verts,offset))
{
		}
PolyShape::PolyShape(cp::Body *body,cpFloat width,cpFloat height)
	: Shape(cpBoxShapeNew(body ? body->get() : 0,width,height))
{
		shape->data = this;
}
PolyShape::PolyShape(cp::Body *body,const cp::BB& box)
	: Shape(cpBoxShapeNew2(body ? body->get() : 0,box))
{
		shape->data = this;
}
int PolyShape::getNumVerts()
{
		return cpPolyShapeGetNumVerts(Shape::get());
}
cp::Vect PolyShape::getVert(int idx)
{
		return cpPolyShapeGetVert(Shape::get(),idx);
}
PolyShape::PolyShape(PolyShape&&o)
	: polyshape(o.polyshape),
	  Shape(std::move(o))
{
				o.polyshape = 0;
}
};//namespace cp
