/* 
 * Licensed under the MIT License (See the file LICENSE in the root directory).
 *
 * Chipmunk binding for C++ automatically generated on 12/12/12 16:13:07.
 */
#pragma once

#include <utility>
#include "chipmunk.h"
#include "chipmunk_declarations.hpp"
#include <map>
#include <functional>

namespace cp {
	struct CollisionHandler {
		std::function<cpBool (cp::Arbiter *arb, cp::Space *space, void *data)> begin;
		std::function<cpBool (cp::Arbiter *arb, cp::Space *space, void *data)> preSolve;
		std::function<void (cp::Arbiter *arb, cp::Space *space, void *data)> postSolve;
		std::function<void (cp::Arbiter *arb, cp::Space *space, void *data)> separate;
		cpDataPointer data;
	};
	typedef std::function<cpBool (cp::Arbiter *,cp::Space *,void *)> CollisionBeginFunc ;
	typedef std::function<cpBool (cp::Arbiter *,cp::Space *,void *)> CollisionPreSolveFunc ;
	typedef std::function<void (cp::Arbiter *,cp::Space *,void *)> CollisionPostSolveFunc ;
	typedef std::function<void (cp::Arbiter *,cp::Space *,void *)> CollisionSeparateFunc ;
/// Post Step callback function type.
	typedef std::function<void (cp::Space *,void *)> PostStepFunc ;
/// Point query callback function type.
	typedef std::function<void (cp::Shape *)> SpacePointQueryFunc ;
/// Nearest point query callback function type.
	typedef std::function<void (cp::Shape *,cpFloat ,cp::Vect )> SpaceNearestPointQueryFunc ;
/// Segment query callback function type.
	typedef std::function<void (cp::Shape *,cpFloat ,cp::Vect )> SpaceSegmentQueryFunc ;
/// Rectangle Query callback function type.
	typedef std::function<void (cp::Shape *)> SpaceBBQueryFunc ;
/// Shape query callback function type.
	typedef std::function<void (cp::Shape *,cpContactPointSet *)> SpaceShapeQueryFunc ;
/// Space/body iterator callback function type.
	typedef std::function<void (cp::Body *)> SpaceBodyIteratorFunc ;
/// Space/body iterator callback function type.
	typedef std::function<void (cp::Shape *)> SpaceShapeIteratorFunc ;
/// Space/constraint iterator callback function type.
	typedef std::function<void (cp::Constraint *)> SpaceConstraintIteratorFunc ;

class Space {
protected:
	cpSpace* space;
	cpDataPointer data;
	cp::Body* body;
	std::map<std::pair<cpCollisionType, cpCollisionType>, CollisionHandler>  collisionHandlers;
public:
	inline cpSpace* get(){
		return space;
}
/// Allocate and initialize a cpSpace.
	Space(void);
/// Destroy and free a cpSpace.
	~Space();
/// Set a default collision handler for this space.
/// The default collision handler is invoked for each colliding pair of shapes
/// that isn't explicitly handled by a specific collision handler.
/// You can pass NULL for any function you don't want to implement.
	void setDefaultCollisionHandler(cpCollisionBeginFunc begin,cpCollisionPreSolveFunc preSolve,cpCollisionPostSolveFunc postSolve,cpCollisionSeparateFunc separate,void *data);
	void addCollisionHandler(cpCollisionType a,cpCollisionType b,const CollisionBeginFunc & begin = CollisionBeginFunc (),const CollisionPreSolveFunc & preSolve = CollisionPreSolveFunc (),const CollisionPostSolveFunc & postSolve = CollisionPostSolveFunc (),const CollisionSeparateFunc & separate = CollisionSeparateFunc (),void *data = 0);
/// Set a collision handler to be used whenever the two shapes with the given collision types collide.
/// You can pass NULL for any function you don't want to implement.
	void addCollisionHandler(cpCollisionType a,cpCollisionType b,cpCollisionBeginFunc begin,cpCollisionPreSolveFunc preSolve,cpCollisionPostSolveFunc postSolve,cpCollisionSeparateFunc separate,void *data);
/// Unset a collision handler.
	void removeCollisionHandler(cpCollisionType a,cpCollisionType b);
/// Add a collision shape to the simulation.
/// If the shape is attached to a static body, it will be added as a static shape.
	cp::Shape* addShape(cp::Shape *shape);
/// Explicity add a shape as a static shape to the simulation.
	cp::Shape* addStaticShape(cp::Shape *shape);
/// Add a rigid body to the simulation.
	cp::Body* addBody(cp::Body *body);
/// Add a constraint to the simulation.
	cp::Constraint* addConstraint(cp::Constraint *constraint);
/// Remove a collision shape from the simulation.
	void removeShape(cp::Shape *shape);
/// Remove a collision shape added using cpSpaceAddStaticShape() from the simulation.
	void removeStaticShape(cp::Shape *shape);
/// Remove a rigid body from the simulation.
	void removeBody(cp::Body *body);
/// Remove a constraint from the simulation.
	void removeConstraint(cp::Constraint *constraint);
/// Test if a collision shape has been added to the space.
	cpBool containsShape(cp::Shape *shape);
/// Test if a rigid body has been added to the space.
	cpBool containsBody(cp::Body *body);
/// Test if a constraint has been added to the space.
	cpBool containsConstraint(cp::Constraint *constraint);
	cpBool addPostStepCallback(cpPostStepFunc func,void *key,void *data);
/// Schedule a post-step callback to be called when cpSpaceStep() finishes.
/// You can only register one callback per unique value for @c key.
/// Returns true only if @c key has never been scheduled before.
/// It's possible to pass @c NULL for @c func if you only want to mark @c key as being used.
	cpBool addPostStepCallback(PostStepFunc func,void *key);
	void pointQuery(const cp::Vect& point,cpLayers layers,cpGroup group,cpSpacePointQueryFunc func,void *data);
/// Query the space at a point and call @c func for each shape found.
	void pointQuery(cpVect point,cpLayers layers,cpGroup group,SpacePointQueryFunc func);
/// Query the space at a point and return the first shape found. Returns NULL if no shapes were found.
	cp::Shape *pointQueryFirst(const cp::Vect& point,cpLayers layers,cpGroup group);
	void nearestPointQuery(const cp::Vect& point,cpFloat maxDistance,cpLayers layers,cpGroup group,cpSpaceNearestPointQueryFunc func,void *data);
/// Query the space at a point and call @c func for each shape found.
	void nearestPointQuery(cpVect point,cpFloat maxDistance,cpLayers layers,cpGroup group,SpaceNearestPointQueryFunc func);
/// Query the space at a point and return the nearest shape found. Returns NULL if no shapes were found.
	cp::Shape *nearestPointQueryNearest(const cp::Vect& point,cpFloat maxDistance,cpLayers layers,cpGroup group,cpNearestPointQueryInfo *out);
	void segmentQuery(const cp::Vect& start,const cp::Vect& end,cpLayers layers,cpGroup group,cpSpaceSegmentQueryFunc func,void *data);
/// Perform a directed line segment query (like a raycast) against the space calling @c func for each shape intersected.
	void segmentQuery(cpVect start,cpVect end,cpLayers layers,cpGroup group,SpaceSegmentQueryFunc func);
/// Perform a directed line segment query (like a raycast) against the space and return the first shape hit. Returns NULL if no shapes were hit.
	cp::Shape *segmentQueryFirst(const cp::Vect& start,const cp::Vect& end,cpLayers layers,cpGroup group,cpSegmentQueryInfo *out);
	void BBQuery(const cp::BB& bb,cpLayers layers,cpGroup group,cpSpaceBBQueryFunc func,void *data);
/// Perform a fast rectangle query on the space calling @c func for each shape found.
/// Only the shape's bounding boxes are checked for overlap, not their full shape.
	void BBQuery(cpBB bb,cpLayers layers,cpGroup group,SpaceBBQueryFunc func);
	cpBool shapeQuery(cp::Shape *shape,cpSpaceShapeQueryFunc func,void *data);
/// Query a space for any shapes overlapping the given shape and call @c func for each shape found.
	cpBool shapeQuery(cpShape *shape,SpaceShapeQueryFunc func);
/// Call cpBodyActivate() for any shape that is overlaps the given shape.
	void activateShapesTouchingShape(cp::Shape *shape);
	void eachBody(cpSpaceBodyIteratorFunc func,void *data);
/// Call @c func for each body in the space.
	void eachBody(SpaceBodyIteratorFunc func);
	void eachShape(cpSpaceShapeIteratorFunc func,void *data);
/// Call @c func for each shape in the space.
	void eachShape(SpaceShapeIteratorFunc func);
	void eachConstraint(cpSpaceConstraintIteratorFunc func,void *data);
/// Call @c func for each shape in the space.
	void eachConstraint(SpaceConstraintIteratorFunc func);
/// Update the collision detection info for the static shapes in the space.
	void reindexStatic();
/// Update the collision detection data for a specific shape in the space.
	void reindexShape(cp::Shape *shape);
/// Update the collision detection data for all shapes attached to a body.
	void reindexShapesForBody(cp::Body *body);
/// Switch the space to use a spatial has as it's spatial index.
	void useSpatialHash(cpFloat dim,int count);
/// Step the space forward in time by @c dt.
	void step(cpFloat dt);
	int getIterations(void);
	void setIterations(int value);
	cp::Vect getGravity(void);
	void setGravity(const cp::Vect&  value);
	cpFloat getDamping(void);
	void setDamping(cpFloat value);
	cpFloat getIdleSpeedThreshold(void);
	void setIdleSpeedThreshold(cpFloat value);
	cpFloat getSleepTimeThreshold(void);
	void setSleepTimeThreshold(cpFloat value);
	cpFloat getCollisionSlop(void);
	void setCollisionSlop(cpFloat value);
	cpFloat getCollisionBias(void);
	void setCollisionBias(cpFloat value);
	cpTimestamp getCollisionPersistence(void);
	void setCollisionPersistence(cpTimestamp value);
	cpBool getEnableContactGraph(void);
	void setEnableContactGraph(cpBool value);
	cpDataPointer getUserData(void);
	void setUserData(cpDataPointer value);
	cp::Body* getStaticBody(void);
	cpFloat getCurrentTimeStep(void);
	Space(cpSpace* v);
	Space(Space&&o);
private:
//Hiding copy constructor and assignment
Space(const Space&);
Space& operator=(const Space&);

};
};//namespace cp
