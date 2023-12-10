#pragma once

#include "Body.h"
#include <vector>

struct C {
	std::vector<Body*> colliding;
};

namespace Detection {

	static void detect(const std::vector<Body*> v) {

		const auto& intersect = [](const Body& a, const Body& b) {
			return	
				a.position().x + a.size().x <= b.position().x &&
				a.position().y - a.size().y <= b.position().y ;
		};
		
		for (size_t i = 0; i < v.size() - 1; i++) {
			
			C c;

			for (size_t j = i + 1; j < v.size(); j++) {
				
				if (intersect(*v[i], *v[j]))
					c.colliding.push_back(v[j]);

			}

		}

	}

}

namespace Resolution {

	static void resolve(C c) {

		const auto& v = c.colliding;



	}

}