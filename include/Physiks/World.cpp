#include "World.h"

#include "Collision.h"

World::World(const Vec2& gravity): mGravity(gravity) {

}

void World::update(float delta, uint32_t velocityIteraions, uint32_t positionIteration) {
	
	for (Body* body : mBodies) {
		body->accumulate(mGravity);
		body->update(delta, 1, 1);
	}

	Detection::detect(mBodies);

}