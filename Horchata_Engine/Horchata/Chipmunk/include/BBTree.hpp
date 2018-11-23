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

class BBTree : public SpatialIndex {
protected:
	cpBBTree* bbtree;
public:
	inline cpBBTree* get(){
		return bbtree;
}
/// Allocate and initialize a bounding box tree.
	BBTree(cpSpatialIndexBBFunc bbfunc,cp::SpatialIndex *staticIndex);
/// Perform a static top down optimization of the tree.
	void optimize();
/// Set the velocity function for the bounding box tree to enable temporal coherence.
	void setVelocityFunc(cpBBTreeVelocityFunc func);
	BBTree(BBTree&&o);
private:
//Hiding copy constructor and assignment
BBTree(const BBTree&);
BBTree& operator=(const BBTree&);

};
};//namespace cp
