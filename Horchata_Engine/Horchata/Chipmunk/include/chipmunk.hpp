/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 11/13/12 21:59:52.
 */
#pragma once
#include "chipmunk_declarations.hpp"
#include "Vect.hpp"
#include "BB.hpp"
#include "Constraint.hpp"
#include "Arbiter.hpp"
#include "PivotJoint.hpp"
#include "BBTree.hpp"
#include "Body.hpp"
#include "SpaceHash.hpp"
#include "Shape.hpp"
#include "PinJoint.hpp"
#include "GearJoint.hpp"
#include "Sweep1D.hpp"
#include "SimpleMotor.hpp"
#include "DampedRotarySpring.hpp"
#include "SpatialIndex.hpp"
#include "RatchetJoint.hpp"
#include "BB.hpp"
#include "RotaryLimitJoint.hpp"
#include "Vect.hpp"
#include "SlideJoint.hpp"
#include "DampedSpring.hpp"
#include "SegmentShape.hpp"
#include "PolyShape.hpp"
#include "GrooveJoint.hpp"
#include "Space.hpp"
#include "CircleShape.hpp"
namespace cp {
/// Calculate the moment of inertia for a circle.
/// @c r1 and @c r2 are the inner and outer diameters. A solid circle has an inner diameter of 0.
	inline cpFloat momentForCircle(cpFloat m,cpFloat r1,cpFloat r2,const cp::Vect& offset){
		return cpMomentForCircle(m,r1,r2,offset);
}

/// Calculate area of a hollow circle.
/// @c r1 and @c r2 are the inner and outer diameters. A solid circle has an inner diameter of 0.
	inline cpFloat areaForCircle(cpFloat r1,cpFloat r2){
		return cpAreaForCircle(r1,r2);
}

/// Calculate the moment of inertia for a line segment.
/// Beveling radius is not supported.
	inline cpFloat momentForSegment(cpFloat m,const cp::Vect& a,const cp::Vect& b){
		return cpMomentForSegment(m,a,b);
}

/// Calculate the area of a fattened (capsule shaped) line segment.
	inline cpFloat areaForSegment(const cp::Vect& a,const cp::Vect& b,cpFloat r){
		return cpAreaForSegment(a,b,r);
}

/// Calculate the moment of inertia for a solid polygon shape assuming it's center of gravity is at it's centroid. The offset is added to each vertex.
	inline cpFloat momentForPoly(cpFloat m,int numVerts,const cp::Vect *verts,const cp::Vect& offset){
		return cpMomentForPoly(m,numVerts,verts,offset);
}

/// Calculate the signed area of a polygon. A Clockwise winding gives positive area.
/// This is probably backwards from what you expect, but matches Chipmunk's the winding for poly shapes.
	inline cpFloat areaForPoly(const int numVerts,const cp::Vect *verts){
		return cpAreaForPoly(numVerts,verts);
}

/// Calculate the natural centroid of a polygon.
	inline cp::Vect centroidForPoly(const int numVerts,const cp::Vect *verts){
		return cpCentroidForPoly(numVerts,verts);
}

/// Center the polygon on the origin. (Subtracts the centroid of the polygon from each vertex)
	inline void recenterPoly(const int numVerts,cp::Vect *verts){
		cpRecenterPoly(numVerts,verts);
}

/// Calculate the moment of inertia for a solid box.
	inline cpFloat momentForBox(cpFloat m,cpFloat width,cpFloat height){
		return cpMomentForBox(m,width,height);
}

/// Calculate the moment of inertia for a solid box.
	inline cpFloat momentForBox2(cpFloat m,const cp::BB& box){
		return cpMomentForBox2(m,box);
}

/// Calculate the convex hull of a given set of points. Returns the count of points in the hull.
/// @c result must be a pointer to a @c cpVect array with at least @c count elements. If @c result is @c NULL, then @c verts will be reduced instead.
/// @c first is an optional pointer to an integer to store where the first vertex in the hull came from (i.e. verts[first] == result[0])
/// @c tol is the allowed amount to shrink the hull when simplifying it. A tolerance of 0.0 creates an exact hull.
	inline int convexHull(int count,cp::Vect *verts,cp::Vect *result,int *first,cpFloat tol){
		return cpConvexHull(count,verts,result,first,tol);
}

/// Check that a set of vertexes is convex and has a clockwise winding.
/// NOTE: Due to floating point precision issues, hulls created with cpQuickHull() are not guaranteed to validate!
	inline cpBool polyValidate(const cp::Vect *verts,const int numVerts){
		return cpPolyValidate(verts,numVerts);
}

/// Get the hit point for a segment query.
	inline cp::Vect segmentQueryHitPoint(const cp::Vect& start,const cp::Vect& end,const cpSegmentQueryInfo info){
		return cpSegmentQueryHitPoint(start,end,info);
}

/// Get the hit distance for a segment query.
	inline cpFloat segmentQueryHitDist(const cp::Vect& start,const cp::Vect& end,const cpSegmentQueryInfo info){
		return cpSegmentQueryHitDist(start,end,info);
}

/// When initializing a shape, it's hash value comes from a counter.
/// Because the hash value may affect iteration order, you can reset the shape ID counter
/// when recreating a space. This will make the simulation be deterministic.
	inline void resetShapeIdCounter(void){
		cpResetShapeIdCounter();
}

}//namespace cp
