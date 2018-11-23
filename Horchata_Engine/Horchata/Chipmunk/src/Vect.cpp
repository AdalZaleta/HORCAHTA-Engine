/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 11/13/12 23:23:23.
 */
#include "Vect.hpp"
#include <utility>
#include "chipmunk.h"
#include "Vect.hpp"

namespace cp {

Vect::Vect(cpVect cv)
{
		this->x = cv.x; this->y = cv.y;
}
Vect::Vect(const cp::Vect& cv)
{
		this->x = cv.x; this->y = cv.y;
}
Vect::Vect(const cpFloat x,const cpFloat y)
{
		this->x = x; this->y = y;
}
cp::Vect Vect::slerp(Vect& v2,const cpFloat t) const
{
		return cpvslerp(*this,v2,t);
}
cp::Vect Vect::slerpconst(Vect& v2,const cpFloat a) const
{
		return cpvslerpconst(*this,v2,a);
}
char* Vect::str() const
{
		return cpvstr(*this);
}
cpBool Vect::operator==(const Vect& v2) const
{
		return cpveql(*this,v2);
}
cp::Vect Vect::operator+(const Vect& v2) const
{
		return cpvadd(*this,v2);
}
cp::Vect Vect::operator-(const Vect& v2) const
{
		return cpvsub(*this,v2);
}
cp::Vect Vect::operator-() const
{
		return cpvneg(*this);
}
cp::Vect Vect::operator*(cpFloat s) const
{
		return cpvmult(*this,s);
}
cpFloat Vect::dot(Vect& v2) const
{
		return cpvdot(*this,v2);
}
cpFloat Vect::cross(Vect& v2) const
{
		return cpvcross(*this,v2);
}
cp::Vect Vect::perp() const
{
		return cpvperp(*this);
}
cp::Vect Vect::rperp() const
{
		return cpvrperp(*this);
}
cp::Vect Vect::project(Vect& v2) const
{
		return cpvproject(*this,v2);
}
cp::Vect Vect::forangle(const cpFloat a) const
{
		return cpvforangle(a);
}
cpFloat Vect::toangle() const
{
		return cpvtoangle(*this);
}
cp::Vect Vect::rotate(Vect& v2) const
{
		return cpvrotate(*this,v2);
}
cp::Vect Vect::unrotate(Vect& v2) const
{
		return cpvunrotate(*this,v2);
}
cpFloat Vect::lengthsq() const
{
		return cpvlengthsq(*this);
}
cpFloat Vect::length() const
{
		return cpvlength(*this);
}
cp::Vect Vect::lerp(Vect& v2,const cpFloat t) const
{
		return cpvlerp(*this,v2,t);
}
cp::Vect Vect::normalize() const
{
		return cpvnormalize(*this);
}
cp::Vect Vect::normalize_safe() const
{
		return cpvnormalize_safe(*this);
}
cp::Vect Vect::clamp(const cpFloat len) const
{
		return cpvclamp(*this,len);
}
cp::Vect Vect::lerpconst(Vect& v2,cpFloat d) const
{
		return cpvlerpconst(*this,v2,d);
}
cpFloat Vect::dist(Vect& v2) const
{
		return cpvdist(*this,v2);
}
cpFloat Vect::distsq(Vect& v2) const
{
		return cpvdistsq(*this,v2);
}
cpBool Vect::near(Vect& v2,const cpFloat dist) const
{
		return cpvnear(*this,v2,dist);
}
};//namespace cp
