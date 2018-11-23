/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:10:03.
 */
#include "Space.hpp"
#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include <map>
#include "Space.hpp"
#include "Arbiter.hpp"
#include "BB.hpp"
#include "Shape.hpp"
#include <functional>
#include "Vect.hpp"
#include "Constraint.hpp"
#include "Body.hpp"

class Space;
namespace {
	cpBool internal_CollisionBeginFunc (cpArbiter *arb,cpSpace *space,void *data);
	cpBool internal_CollisionPreSolveFunc (cpArbiter *arb,cpSpace *space,void *data);
	void internal_CollisionPostSolveFunc (cpArbiter *arb,cpSpace *space,void *data);
	void internal_CollisionSeparateFunc (cpArbiter *arb,cpSpace *space,void *data);
	void SpaceAddPostStepCallback(cpSpace *space,void *obj,void *data);
	void SpacePointQuery(cpShape *shape,void *data);
	void SpaceNearestPointQuery(cpShape *shape,cpFloat distance,cpVect point,void *data);
	void SpaceSegmentQuery(cpShape *shape,cpFloat t,cpVect n,void *data);
	void SpaceBBQuery(cpShape *shape,void *data);
	void SpaceShapeQuery(cpShape *shape,cpContactPointSet *points,void *data);
	void SpaceEachBody(cpBody *body,void *data);
	void SpaceEachShape(cpShape *shape,void *data);
	void SpaceEachConstraint(cpConstraint *constraint,void *data);
}

namespace cp {

Space::Space(void)
	: space(cpSpaceNew()),
	  data(0),
	  body(new cp::Body(cpSpaceGetStaticBody(space)))
{
		space->data = this;
		cpBodySetUserData(cpSpaceGetStaticBody(space), body);
}
Space::~Space()
{
		cpSpaceFree(space);
		body->body = 0;
		delete body;
}
void Space::setDefaultCollisionHandler(cpCollisionBeginFunc begin,cpCollisionPreSolveFunc preSolve,cpCollisionPostSolveFunc postSolve,cpCollisionSeparateFunc separate,void *data)
{
		cpSpaceSetDefaultCollisionHandler(space,begin,preSolve,postSolve,separate,data);
}
void Space::addCollisionHandler(cpCollisionType a,cpCollisionType b,const CollisionBeginFunc & begin,const CollisionPreSolveFunc & preSolve,const CollisionPostSolveFunc & postSolve,const CollisionSeparateFunc & separate,void *data)
{
		CollisionHandler& handler = collisionHandlers[std::make_pair(a,b)];
			handler.begin = begin;
			handler.preSolve = preSolve;
			handler.postSolve = postSolve;
			handler.separate = separate;
			handler.data = data;
			cpSpaceAddCollisionHandler(space, a, b, !begin ?  0 : internal_CollisionBeginFunc , !preSolve ?  0 : internal_CollisionPreSolveFunc , !postSolve ?  0 : internal_CollisionPostSolveFunc , !separate ?  0 : internal_CollisionSeparateFunc ,  &handler);
}
void Space::addCollisionHandler(cpCollisionType a,cpCollisionType b,cpCollisionBeginFunc begin,cpCollisionPreSolveFunc preSolve,cpCollisionPostSolveFunc postSolve,cpCollisionSeparateFunc separate,void *data)
{
		cpSpaceAddCollisionHandler(space,a,b,begin,preSolve,postSolve,separate,data);
}
void Space::removeCollisionHandler(cpCollisionType a,cpCollisionType b)
{
		collisionHandlers.erase(std::make_pair(a, b));
cpSpaceRemoveCollisionHandler(get(),a,b);
}
cp::Shape* Space::addShape(cp::Shape *shape)
{
		cpShape*  temp = cpSpaceAddShape(space,shape ? shape->get() : 0);
		return static_cast<cp::Shape* >(temp ? temp->data : 0);
}
cp::Shape* Space::addStaticShape(cp::Shape *shape)
{
		cpShape*  temp = cpSpaceAddStaticShape(space,shape ? shape->get() : 0);
		return static_cast<cp::Shape* >(temp ? temp->data : 0);
}
cp::Body* Space::addBody(cp::Body *body)
{
		cpBody*  temp = cpSpaceAddBody(space,body ? body->get() : 0);
		return static_cast<cp::Body* >(temp ? temp->data : 0);
}
cp::Constraint* Space::addConstraint(cp::Constraint *constraint)
{
		cpConstraint*  temp = cpSpaceAddConstraint(space,constraint ? constraint->get() : 0);
		return static_cast<cp::Constraint* >(temp ? temp->data : 0);
}
void Space::removeShape(cp::Shape *shape)
{
		cpSpaceRemoveShape(space,shape ? shape->get() : 0);
}
void Space::removeStaticShape(cp::Shape *shape)
{
		cpSpaceRemoveStaticShape(space,shape ? shape->get() : 0);
}
void Space::removeBody(cp::Body *body)
{
		cpSpaceRemoveBody(space,body ? body->get() : 0);
}
void Space::removeConstraint(cp::Constraint *constraint)
{
		cpSpaceRemoveConstraint(space,constraint ? constraint->get() : 0);
}
cpBool Space::containsShape(cp::Shape *shape)
{
		return cpSpaceContainsShape(space,shape ? shape->get() : 0);
}
cpBool Space::containsBody(cp::Body *body)
{
		return cpSpaceContainsBody(space,body ? body->get() : 0);
}
cpBool Space::containsConstraint(cp::Constraint *constraint)
{
		return cpSpaceContainsConstraint(space,constraint ? constraint->get() : 0);
}
cpBool Space::addPostStepCallback(cpPostStepFunc func,void *key,void *data)
{
		return cpSpaceAddPostStepCallback(space,func,key,data);
}
cpBool Space::addPostStepCallback(PostStepFunc func,void *key)
{
		return cpSpaceAddPostStepCallback(space,*SpaceAddPostStepCallback,key,&func);
}
void Space::pointQuery(const cp::Vect& point,cpLayers layers,cpGroup group,cpSpacePointQueryFunc func,void *data)
{
		cpSpacePointQuery(space,point,layers,group,func,data);
}
void Space::pointQuery(cpVect point,cpLayers layers,cpGroup group,SpacePointQueryFunc func)
{
		cpSpacePointQuery(space,point,layers,group,*SpacePointQuery,&func);
}
cp::Shape *Space::pointQueryFirst(const cp::Vect& point,cpLayers layers,cpGroup group)
{
		cpShape * temp = cpSpacePointQueryFirst(space,point,layers,group);
		return static_cast<cp::Shape *>(temp ? temp->data : 0);
}
void Space::nearestPointQuery(const cp::Vect& point,cpFloat maxDistance,cpLayers layers,cpGroup group,cpSpaceNearestPointQueryFunc func,void *data)
{
		cpSpaceNearestPointQuery(space,point,maxDistance,layers,group,func,data);
}
void Space::nearestPointQuery(cpVect point,cpFloat maxDistance,cpLayers layers,cpGroup group,SpaceNearestPointQueryFunc func)
{
		cpSpaceNearestPointQuery(space,point,maxDistance,layers,group,*SpaceNearestPointQuery,&func);
}
cp::Shape *Space::nearestPointQueryNearest(const cp::Vect& point,cpFloat maxDistance,cpLayers layers,cpGroup group,cpNearestPointQueryInfo *out)
{
		cpShape * temp = cpSpaceNearestPointQueryNearest(space,point,maxDistance,layers,group,out);
		return static_cast<cp::Shape *>(temp ? temp->data : 0);
}
void Space::segmentQuery(const cp::Vect& start,const cp::Vect& end,cpLayers layers,cpGroup group,cpSpaceSegmentQueryFunc func,void *data)
{
		cpSpaceSegmentQuery(space,start,end,layers,group,func,data);
}
void Space::segmentQuery(cpVect start,cpVect end,cpLayers layers,cpGroup group,SpaceSegmentQueryFunc func)
{
		cpSpaceSegmentQuery(space,start,end,layers,group,*SpaceSegmentQuery,&func);
}
cp::Shape *Space::segmentQueryFirst(const cp::Vect& start,const cp::Vect& end,cpLayers layers,cpGroup group,cpSegmentQueryInfo *out)
{
		cpShape * temp = cpSpaceSegmentQueryFirst(space,start,end,layers,group,out);
		return static_cast<cp::Shape *>(temp ? temp->data : 0);
}
void Space::BBQuery(const cp::BB& bb,cpLayers layers,cpGroup group,cpSpaceBBQueryFunc func,void *data)
{
		cpSpaceBBQuery(space,bb,layers,group,func,data);
}
void Space::BBQuery(cpBB bb,cpLayers layers,cpGroup group,SpaceBBQueryFunc func)
{
		cpSpaceBBQuery(space,bb,layers,group,*SpaceBBQuery,&func);
}
cpBool Space::shapeQuery(cp::Shape *shape,cpSpaceShapeQueryFunc func,void *data)
{
		return cpSpaceShapeQuery(space,shape ? shape->get() : 0,func,data);
}
cpBool Space::shapeQuery(cpShape *shape,SpaceShapeQueryFunc func)
{
		return cpSpaceShapeQuery(space,shape,*SpaceShapeQuery,&func);
}
void Space::activateShapesTouchingShape(cp::Shape *shape)
{
		cpSpaceActivateShapesTouchingShape(space,shape ? shape->get() : 0);
}
void Space::eachBody(cpSpaceBodyIteratorFunc func,void *data)
{
		cpSpaceEachBody(space,func,data);
}
void Space::eachBody(SpaceBodyIteratorFunc func)
{
		cpSpaceEachBody(space,*SpaceEachBody,&func);
}
void Space::eachShape(cpSpaceShapeIteratorFunc func,void *data)
{
		cpSpaceEachShape(space,func,data);
}
void Space::eachShape(SpaceShapeIteratorFunc func)
{
		cpSpaceEachShape(space,*SpaceEachShape,&func);
}
void Space::eachConstraint(cpSpaceConstraintIteratorFunc func,void *data)
{
		cpSpaceEachConstraint(space,func,data);
}
void Space::eachConstraint(SpaceConstraintIteratorFunc func)
{
		cpSpaceEachConstraint(space,*SpaceEachConstraint,&func);
}
void Space::reindexStatic()
{
		cpSpaceReindexStatic(space);
}
void Space::reindexShape(cp::Shape *shape)
{
		cpSpaceReindexShape(space,shape ? shape->get() : 0);
}
void Space::reindexShapesForBody(cp::Body *body)
{
		cpSpaceReindexShapesForBody(space,body ? body->get() : 0);
}
void Space::useSpatialHash(cpFloat dim,int count)
{
		cpSpaceUseSpatialHash(space,dim,count);
}
void Space::step(cpFloat dt)
{
		cpSpaceStep(space,dt);
}
int Space::getIterations(void)
{
		return cpSpaceGetIterations(space);
}
void Space::setIterations(int value)
{
		cpSpaceSetIterations(space,value);
}
cp::Vect Space::getGravity(void)
{
		return cpSpaceGetGravity(space);
}
void Space::setGravity(const cp::Vect&  value)
{
		cpSpaceSetGravity(space,value);
}
cpFloat Space::getDamping(void)
{
		return cpSpaceGetDamping(space);
}
void Space::setDamping(cpFloat value)
{
		cpSpaceSetDamping(space,value);
}
cpFloat Space::getIdleSpeedThreshold(void)
{
		return cpSpaceGetIdleSpeedThreshold(space);
}
void Space::setIdleSpeedThreshold(cpFloat value)
{
		cpSpaceSetIdleSpeedThreshold(space,value);
}
cpFloat Space::getSleepTimeThreshold(void)
{
		return cpSpaceGetSleepTimeThreshold(space);
}
void Space::setSleepTimeThreshold(cpFloat value)
{
		cpSpaceSetSleepTimeThreshold(space,value);
}
cpFloat Space::getCollisionSlop(void)
{
		return cpSpaceGetCollisionSlop(space);
}
void Space::setCollisionSlop(cpFloat value)
{
		cpSpaceSetCollisionSlop(space,value);
}
cpFloat Space::getCollisionBias(void)
{
		return cpSpaceGetCollisionBias(space);
}
void Space::setCollisionBias(cpFloat value)
{
		cpSpaceSetCollisionBias(space,value);
}
cpTimestamp Space::getCollisionPersistence(void)
{
		return cpSpaceGetCollisionPersistence(space);
}
void Space::setCollisionPersistence(cpTimestamp value)
{
		cpSpaceSetCollisionPersistence(space,value);
}
cpBool Space::getEnableContactGraph(void)
{
		return cpSpaceGetEnableContactGraph(space);
}
void Space::setEnableContactGraph(cpBool value)
{
		cpSpaceSetEnableContactGraph(space,value);
}
cpDataPointer Space::getUserData(void)
{
		return data;
}
void Space::setUserData(cpDataPointer value)
{
		data = value;
}
cp::Body* Space::getStaticBody(void)
{
		cpBody *temp = cpSpaceGetStaticBody(space);
		return static_cast<cp::Body*>(temp ? temp->data : 0);
}
cpFloat Space::getCurrentTimeStep(void)
{
		return cpSpaceGetCurrentTimeStep(space);
}
Space::Space(cpSpace* v)
	: data(0)
{
		space = v;
		data = v->data;
		v->data = this;
}
Space::Space(Space&&o)
	: space(o.space),
	  data(o.data),
	  body(o.body),
	  collisionHandlers(std::move(o.collisionHandlers))
{
				o.space = 0;
		o.data = 0;
		o.body = 0;
		get()->data = this;
}
};//namespace cp
namespace {
	cpBool internal_CollisionBeginFunc (cpArbiter *arb,cpSpace *space,void *data)
	{
		cp::CollisionHandler* handler = static_cast<cp::CollisionHandler*>(data);
		cp::Arbiter tempArbiter(arb);
		data = handler->data;
		return (handler->begin)(&tempArbiter,static_cast<cp::Space *>(space->data),data);
	}
	cpBool internal_CollisionPreSolveFunc (cpArbiter *arb,cpSpace *space,void *data)
	{
		cp::CollisionHandler* handler = static_cast<cp::CollisionHandler*>(data);
		cp::Arbiter tempArbiter(arb);
		data = handler->data;
		return (handler->preSolve)(&tempArbiter,static_cast<cp::Space *>(space->data),data);
	}
	void internal_CollisionPostSolveFunc (cpArbiter *arb,cpSpace *space,void *data)
	{
		cp::CollisionHandler* handler = static_cast<cp::CollisionHandler*>(data);
		cp::Arbiter tempArbiter(arb);
		data = handler->data;
		return (handler->postSolve)(&tempArbiter,static_cast<cp::Space *>(space->data),data);
	}
	void internal_CollisionSeparateFunc (cpArbiter *arb,cpSpace *space,void *data)
	{
		cp::CollisionHandler* handler = static_cast<cp::CollisionHandler*>(data);
		cp::Arbiter tempArbiter(arb);
		data = handler->data;
		return (handler->separate)(&tempArbiter,static_cast<cp::Space *>(space->data),data);
	}
	void SpaceAddPostStepCallback(cpSpace *space,void *obj,void *data)
	{
				(*reinterpret_cast<std::function<void (cp::Space *,void *)> *>(data))((cp::Space *)space->data,obj);
	}

	void SpacePointQuery(cpShape *shape,void *data)
	{
				(*reinterpret_cast<std::function<void (cp::Shape *)> *>(data))((cp::Shape *)shape->data);
	}

	void SpaceNearestPointQuery(cpShape *shape,cpFloat distance,cpVect point,void *data)
	{
				(*reinterpret_cast<std::function<void (cp::Shape *,cpFloat ,cp::Vect )> *>(data))((cp::Shape *)shape->data,distance,point);
	}

	void SpaceSegmentQuery(cpShape *shape,cpFloat t,cpVect n,void *data)
	{
				(*reinterpret_cast<std::function<void (cp::Shape *,cpFloat ,cp::Vect )> *>(data))((cp::Shape *)shape->data,t,n);
	}

	void SpaceBBQuery(cpShape *shape,void *data)
	{
				(*reinterpret_cast<std::function<void (cp::Shape *)> *>(data))((cp::Shape *)shape->data);
	}

	void SpaceShapeQuery(cpShape *shape,cpContactPointSet *points,void *data)
	{
				(*reinterpret_cast<std::function<void (cp::Shape *,cpContactPointSet *)> *>(data))((cp::Shape *)shape->data,points);
	}

	void SpaceEachBody(cpBody *body,void *data)
	{
				(*reinterpret_cast<std::function<void (cp::Body *)> *>(data))((cp::Body *)body->data);
	}

	void SpaceEachShape(cpShape *shape,void *data)
	{
				(*reinterpret_cast<std::function<void (cp::Shape *)> *>(data))((cp::Shape *)shape->data);
	}

	void SpaceEachConstraint(cpConstraint *constraint,void *data)
	{
				(*reinterpret_cast<std::function<void (cp::Constraint *)> *>(data))((cp::Constraint *)constraint->data);
	}

}

