#pragma once

#include "Calc.h"
#include "Body.h"

#include <vector>

class World {

	public:

		World(const Vec2& gravity = Vec2(0.0f, 0.0f));

		void update(float delta, uint32_t velocityIterations, uint32_t positionIteration);

		Body* createBody() {
			Body* b = new Body;
			mBodies.push_back(b);
			return b;
		}

		World& setGravity(const Vec2& gravity) { mGravity = gravity; return *this; }

	private:

		std::vector<Body*> mBodies;

		Vec2 mGravity;

};