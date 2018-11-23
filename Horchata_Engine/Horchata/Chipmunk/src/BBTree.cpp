/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "BBTree.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include "SpatialIndex.hpp"
#include "SpatialIndex.hpp"

namespace cp {

BBTree::BBTree(cpSpatialIndexBBFunc bbfunc,cp::SpatialIndex *staticIndex)
	: SpatialIndex(cpBBTreeNew(bbfunc,staticIndex ? staticIndex->get() : 0))
{
		}
void BBTree::optimize()
{
		cpBBTreeOptimize(SpatialIndex::get());
}
void BBTree::setVelocityFunc(cpBBTreeVelocityFunc func)
{
		cpBBTreeSetVelocityFunc(SpatialIndex::get(),func);
}
BBTree::BBTree(BBTree&&o)
	: bbtree(o.bbtree),
	  SpatialIndex(std::move(o))
{
				o.bbtree = 0;
}
};//namespace cp
