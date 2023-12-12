#include "Body.h"

#include <iostream>

void Body::update(float delta, uint32_t vi, uint32_t pi) {

	mVelocity += mAccumulator;
	mVelocity *= mLinearDamp;
	mPosition += mVelocity * delta;

	mAccumulator = Vec2::Zero();

}
