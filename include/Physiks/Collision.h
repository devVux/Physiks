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

	static const Vec2& normal = Vec2::UnitY();

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

		Body& a = *v[0].a;
		Body& b = *v[0].b;

		Vec2 relativeVelocity = a.velocity() - b.velocity();

		// Calculate relative velocity in terms of the normal direction 
		float velAlongNormal = dot(relativeVelocity, normal);

		if (velAlongNormal > 0)
			return;

		float e = 0.1f; //std::min(a.restituition(), ...);
		
		// Calculate impulse scalar 
		float j = -(1 + e) * velAlongNormal;
		j /= 1 / a.mass() + 1 / b.mass();

		Vec2 impulse = j * normal;
		a.setVelocity(a.velocity() - 1 / a.mass() * impulse);
		b.setVelocity(b.velocity() - 1 / b.mass() * impulse);

		//const float percent = 0.2f; // usually 20% to 80% 
		//const float slop = 0.01f; // usually 0.01 to 0.1 
		//Vec2 correction = max(penetration - k_slop, 0.0f) / (A.inv_mass + B.inv_mass))* percent* n;
		//A.position -= A.inv_mass * correction
		//B.position += B.inv_mass * correction

	}
	


}