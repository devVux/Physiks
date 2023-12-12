#include <gtest/gtest.h>

#include "Physiks/World.h"
#include "Physiks/Body.h"
#include "Physiks/Collision.h"

TEST(Collision, Test_1) {

	World w;
	Body& a = *w.createBody();
	a.setPosition({ 0.0f, 0.0f });
	
	Body& b = *w.createBody();
	b.setPosition({ 1.0f, 0.0f });

	auto v = Detection::detect({ &a, &b });

	ASSERT_EQ(v.size(), 1);

}

TEST(Collision, Test_2) {

	World w;
	Body& a = *w.createBody();
	a.setPosition({ 0.0f, 0.0f });
	
	Body& b = *w.createBody();
	b.setPosition({ 2.0f, 2.0f });

	auto v = Detection::detect({ &a, &b });

	ASSERT_EQ(v.size(), 0);

}

TEST(Collision, Test_3) {

	World w;
	Body& a = *w.createBody();
	a.setPosition({ 0.0f, 0.0f });
	
	Body& b = *w.createBody();
	b.setPosition({ 0.5f, 0.0f });

	auto v = Detection::detect({ &a, &b });

	ASSERT_EQ(v.size(), 1);

}
