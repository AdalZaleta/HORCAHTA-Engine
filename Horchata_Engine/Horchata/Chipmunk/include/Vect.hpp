/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 11/13/12 23:23:23.
 */
#pragma once

#include <utility>
#include "chipmunk.h"

namespace cp {

class Vect : public cpVect {
protected:
public:
	Vect(cpVect cv);
	Vect(const cp::Vect& cv);
/// Convenience constructor for cpVect structs.
	Vect(const cpFloat x = 0,const cpFloat y = 0);
/// Spherical linearly interpolate between v1 and v2.
	cp::Vect slerp(Vect& v2,const cpFloat t) const;
/// Spherical linearly interpolate between v1 towards v2 by no more than angle a radians
	cp::Vect slerpconst(Vect& v2,const cpFloat a) const;
///	Returns a string representation of v. Intended mostly for debugging purposes and not production use.
///	@attention The string points to a static local and is reset every time the function is called.
///	If you want to print more than one vector you will have to split up your printing onto separate lines.
	char* str() const;
/// Check if two vectors are equal. (Be careful when comparing floating point numbers!)
	cpBool operator==(const Vect& v2) const;
/// Add two vectors
	cp::Vect operator+(const Vect& v2) const;
/// Subtract two vectors.
	cp::Vect operator-(const Vect& v2) const;
/// Negate a vector.
	cp::Vect operator-() const;
/// Scalar multiplication.
	cp::Vect operator*(cpFloat s) const;
/// Vector dot product.
	cpFloat dot(Vect& v2) const;
/// 2D vector cross product analog.
/// The cross product of 2D vectors results in a 3D vector with only a z component.
/// This function returns the magnitude of the z value.
	cpFloat cross(Vect& v2) const;
/// Returns a perpendicular vector. (90 degree rotation)
	cp::Vect perp() const;
/// Returns a perpendicular vector. (-90 degree rotation)
	cp::Vect rperp() const;
/// Returns the vector projection of v1 onto v2.
	cp::Vect project(Vect& v2) const;
/// Returns the unit length vector for the given angle (in radians).
	cp::Vect forangle(const cpFloat a) const;
/// Returns the angular direction v is pointing in (in radians).
	cpFloat toangle() const;
/// Uses complex number multiplication to rotate v1 by v2. Scaling will occur if v1 is not a unit vector.
	cp::Vect rotate(Vect& v2) const;
/// Inverse of cpvrotate().
	cp::Vect unrotate(Vect& v2) const;
/// Returns the squared length of v. Faster than cpvlength() when you only need to compare lengths.
	cpFloat lengthsq() const;
/// Returns the length of v.
	cpFloat length() const;
/// Linearly interpolate between v1 and v2.
	cp::Vect lerp(Vect& v2,const cpFloat t) const;
/// Returns a normalized copy of v.
	cp::Vect normalize() const;
/// Returns a normalized copy of v or cpvzero if v was already cpvzero. Protects against divide by zero errors.
	cp::Vect normalize_safe() const;
/// Clamp v to length len.
	cp::Vect clamp(const cpFloat len) const;
/// Linearly interpolate between v1 towards v2 by distance d.
	cp::Vect lerpconst(Vect& v2,cpFloat d) const;
/// Returns the distance between v1 and v2.
	cpFloat dist(Vect& v2) const;
/// Returns the squared distance between v1 and v2. Faster than cpvdist() when you only need to compare distances.
	cpFloat distsq(Vect& v2) const;
/// Returns true if the distance between v1 and v2 is less than dist.
	cpBool near(Vect& v2,const cpFloat dist) const;
private:
//Hiding copy constructor and assignment

};
};//namespace cp
