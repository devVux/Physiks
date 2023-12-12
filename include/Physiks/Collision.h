#pragma once

#include "Body.h"
#include <vector>
#include <iostream>
#include <algorithm>

struct Jarring {
	Body* a;
	Body* b;

	Jarring(Body* aa, Body* bb): a(aa), b(bb) { }

};

namespace Detection {

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

				if (intersect(*v[i], *v[j]))
					colliding.emplace_back(v[i], v[j]);

			}

		}

		return colliding;

	}

}

namespace Resolution {

	static void resolve(const std::vector<Jarring> v) {




	}

}