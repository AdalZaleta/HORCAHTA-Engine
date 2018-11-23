/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "SpatialIndex.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include <functional>
#include "Vect.hpp"
#include "BB.hpp"
#include "SpatialIndex.hpp"

class SpatialIndex;
namespace {
	void SpatialIndexCollideStatic(void *obj1,void *obj2,void *data);
	void SpatialIndexEach(void *obj,void *data);
	void SpatialIndexQuery(void *obj1,void *obj2,void *data);
	cpFloat SpatialIndexSegmentQuery(void *obj1,void *obj2,void *data);
	void SpatialIndexReindexQuery(void *obj1,void *obj2,void *data);
}

namespace cp {

SpatialIndex::~SpatialIndex()
{
		cpSpatialIndexFree(index);
}
void SpatialIndex::collideStatic(cp::SpatialIndex *staticIndex,cpSpatialIndexQueryFunc func,void *data)
{
		cpSpatialIndexCollideStatic(index,staticIndex ? staticIndex->get() : 0,func,data);
}
void SpatialIndex::collideStatic(cpSpatialIndex *staticIndex,SpatialIndexQueryFunc func)
{
		cpSpatialIndexCollideStatic(index,staticIndex,*SpatialIndexCollideStatic,&func);
}
int SpatialIndex::count()
{
		return cpSpatialIndexCount(index);
}
void SpatialIndex::each(cpSpatialIndexIteratorFunc func,void *data)
{
		cpSpatialIndexEach(index,func,data);
}
void SpatialIndex::each(SpatialIndexIteratorFunc func)
{
		cpSpatialIndexEach(index,*SpatialIndexEach,&func);
}
cpBool SpatialIndex::contains(void *obj,cpHashValue hashid)
{
		return cpSpatialIndexContains(index,obj,hashid);
}
void SpatialIndex::insert(void *obj,cpHashValue hashid)
{
		cpSpatialIndexInsert(index,obj,hashid);
}
void SpatialIndex::remove(void *obj,cpHashValue hashid)
{
		cpSpatialIndexRemove(index,obj,hashid);
}
void SpatialIndex::reindex()
{
		cpSpatialIndexReindex(index);
}
void SpatialIndex::reindexObject(void *obj,cpHashValue hashid)
{
		cpSpatialIndexReindexObject(index,obj,hashid);
}
void SpatialIndex::query(void *obj,const cp::BB& bb,cpSpatialIndexQueryFunc func,void *data)
{
		cpSpatialIndexQuery(index,obj,bb,func,data);
}
void SpatialIndex::query(void *obj,cpBB bb,SpatialIndexQueryFunc func)
{
		cpSpatialIndexQuery(index,obj,bb,*SpatialIndexQuery,&func);
}
void SpatialIndex::segmentQuery(void *obj,const cp::Vect& a,const cp::Vect& b,cpFloat t_exit,cpSpatialIndexSegmentQueryFunc func,void *data)
{
		cpSpatialIndexSegmentQuery(index,obj,a,b,t_exit,func,data);
}
void SpatialIndex::segmentQuery(void *obj,cpVect a,cpVect b,cpFloat t_exit,SpatialIndexSegmentQueryFunc func)
{
		cpSpatialIndexSegmentQuery(index,obj,a,b,t_exit,*SpatialIndexSegmentQuery,&func);
}
void SpatialIndex::reindexQuery(cpSpatialIndexQueryFunc func,void *data)
{
		cpSpatialIndexReindexQuery(index,func,data);
}
void SpatialIndex::reindexQuery(SpatialIndexQueryFunc func)
{
		cpSpatialIndexReindexQuery(index,*SpatialIndexReindexQuery,&func);
}
SpatialIndex::SpatialIndex(cpSpatialIndex* v)
{
		index = v;
}
SpatialIndex::SpatialIndex(SpatialIndex&&o)
	: index(o.index)
{
				o.index = 0;
}
};//namespace cp
namespace {
	void SpatialIndexCollideStatic(void *obj1,void *obj2,void *data)
	{
				(*reinterpret_cast<std::function<void (void *,void *)> *>(data))(obj1,obj2);
	}

	void SpatialIndexEach(void *obj,void *data)
	{
				(*reinterpret_cast<std::function<void (void *)> *>(data))(obj);
	}

	void SpatialIndexQuery(void *obj1,void *obj2,void *data)
	{
				(*reinterpret_cast<std::function<void (void *,void *)> *>(data))(obj1,obj2);
	}

	cpFloat SpatialIndexSegmentQuery(void *obj1,void *obj2,void *data)
	{
				return (*reinterpret_cast<std::function<cpFloat (void *,void *)> *>(data))(obj1,obj2);
	}

	void SpatialIndexReindexQuery(void *obj1,void *obj2,void *data)
	{
				(*reinterpret_cast<std::function<void (void *,void *)> *>(data))(obj1,obj2);
	}

}

