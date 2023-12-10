#pragma once

#include "Calc.h"

class Body {
	
	friend class World;

	private:

		Body() = default;
		Body(const Body&) = delete;
		Body& operator=(const Body&) = delete;



	public:

		void update(float delta, uint32_t vi, uint32_t pi);

		Body& accumulate(const Vec2& v) { mAccumulator += v; return *this; }

		Body& setMass(const float& mass) { mMass = mass; return *this; }
		Body& setSize(const Vec2& size) { mSize = size; return *this; }
		Body& setPosition(const Vec2& position) { mPosition = position; return *this; }
		Body& setVelocity(const Vec2& velocity) { mVelocity = velocity; return *this; }
		Body& setLinearDamp(const float& linearDamp) { mLinearDamp = linearDamp; return *this; }

		const Vec2& size() const { return mSize; }
		const Vec2& position() const { return mPosition; }
		const Vec2& velocity() const { return mVelocity; }
		float mass() const { return mMass; }
		float linearDamp() const { return mLinearDamp; }

	private:

		Vec2 mSize { 1.0f, 1.0f };
		Vec2 mPosition { 0.0f, 0.0f };
		Vec2 mVelocity { 0.0f, 0.0f };
		float mLinearDamp { 1.0f };
		float mMass { 1.0f };

		Vec2 mAccumulator { 0.0f, 0.0f };

};