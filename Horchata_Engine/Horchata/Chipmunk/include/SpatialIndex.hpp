/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#pragma once

#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include <functional>

namespace cp {
/// Spatial query callback function type.
	typedef std::function<void (void *,void *)> SpatialIndexQueryFunc ;
/// Spatial index/object iterator callback function type.
	typedef std::function<void (void *)> SpatialIndexIteratorFunc ;
/// Spatial query callback function type.
	typedef std::function<void (void *,void *)> SpatialIndexQueryFunc ;
/// Spatial segment query callback function type.
	typedef std::function<cpFloat (void *,void *)> SpatialIndexSegmentQueryFunc ;
/// Spatial query callback function type.
	typedef std::function<void (void *,void *)> SpatialIndexQueryFunc ;

class SpatialIndex {
protected:
	cpSpatialIndex* index;
public:
	inline cpSpatialIndex* get(){
		return index;
}
/// Destroy and free a spatial index.
	~SpatialIndex();
	void collideStatic(cp::SpatialIndex *staticIndex,cpSpatialIndexQueryFunc func,void *data);
/// Collide the objects in @c dynamicIndex against the objects in @c staticIndex using the query callback function.
	void collideStatic(cpSpatialIndex *staticIndex,SpatialIndexQueryFunc func);
/// Get the number of objects in the spatial index.
	int count();
	void each(cpSpatialIndexIteratorFunc func,void *data);
/// Iterate the objects in the spatial index. @c func will be called once for each object.
	void each(SpatialIndexIteratorFunc func);
/// Returns true if the spatial index contains the given object.
/// Most spatial indexes use hashed storage, so you must provide a hash value too.
	cpBool contains(void *obj,cpHashValue hashid);
/// Add an object to a spatial index.
/// Most spatial indexes use hashed storage, so you must provide a hash value too.
	void insert(void *obj,cpHashValue hashid);
/// Remove an object from a spatial index.
/// Most spatial indexes use hashed storage, so you must provide a hash value too.
	void remove(void *obj,cpHashValue hashid);
/// Perform a full reindex of a spatial index.
	void reindex();
/// Reindex a single object in the spatial index.
	void reindexObject(void *obj,cpHashValue hashid);
	void query(void *obj,const cp::BB& bb,cpSpatialIndexQueryFunc func,void *data);
/// Perform a rectangle query against the spatial index, calling @c func for each potential match.
	void query(void *obj,cpBB bb,SpatialIndexQueryFunc func);
	void segmentQuery(void *obj,const cp::Vect& a,const cp::Vect& b,cpFloat t_exit,cpSpatialIndexSegmentQueryFunc func,void *data);
/// Perform a segment query against the spatial index, calling @c func for each potential match.
	void segmentQuery(void *obj,cpVect a,cpVect b,cpFloat t_exit,SpatialIndexSegmentQueryFunc func);
	void reindexQuery(cpSpatialIndexQueryFunc func,void *data);
/// Simultaneously reindex and find all colliding objects.
/// @c func will be called once for each potentially overlapping pair of objects found.
/// If the spatial index was initialized with a static index, it will collide it's objects against that as well.
	void reindexQuery(SpatialIndexQueryFunc func);
	SpatialIndex(cpSpatialIndex* v);
	SpatialIndex(SpatialIndex&&o);
private:
//Hiding copy constructor and assignment
SpatialIndex(const SpatialIndex&);
SpatialIndex& operator=(const SpatialIndex&);

};
};//namespace cp
