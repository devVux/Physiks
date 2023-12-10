#include "Body.h"

#include <iostream>

void Body::update(float delta, uint32_t vi, uint32_t pi) {

	mVelocity += mAccumulator;
	mPosition += mVelocity * mLinearDamp * delta;

	std::cout << mPosition << '\n';

	mAccumulator = Vec2::Zero();

}
