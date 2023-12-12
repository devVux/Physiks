#pragma once

#include "Body.h"
#include <vector>
#include <iostream>
#include <algorithm>

struct Jarring {
	Body* a;
	Body* b;

	Vec2 normal;
	float depth { 0.0f };

	Jarring() = default;
	Jarring(Body* aa, Body* bb): a(aa), b(bb) { }

};

namespace Collision {

	static auto detect(std::vector<Body*> v) {

		std::sort(v.begin(), v.end(), [](const Body* a, const Body* b) {
			return a->position().x < b->position().x;
		});

		const auto& intersect = [](const Body& a, const Body& b) {
			return
				b.position().x <= a.position().x + a.size().x &&
				b.position().y <= a.position().y + a.size().y;
		};

		std::vector<Jarring> colliding;

		for (size_t i = 0; i < v.size(); i++) {

			for (size_t j = i + 1; j < v.size(); j++) {

				const Body& a = *v[i];
				const Body& b = *v[j];

				if (intersect(a, b)) {
					Jarring jar(v[i], v[j]);
					
					float depth_x = a.position().x + a.size().x - b.position().x;
					float depth_y = a.position().y + a.size().y - b.position().y;

					if (depth_x > depth_y) {
						jar.depth = depth_y;
						jar.normal = Vec2::UnitY();
					} else {
						jar.depth = depth_x;
						jar.normal = Vec2::UnitX();
					}

					colliding.push_back(jar);

				}

			}

		}

		return colliding;

	}

	static void resolve(const std::vector<Jarring> v) {

		for (const Jarring& j : v) {

			if (j.normal == Vec2::UnitX()) {
				j.b->setPosition({ j.b->position().x - j.depth, j.b->position().y });

			} else
				j.b->setPosition({ j.b->position().x, j.b->position().y - j.depth });

		}

	}

}