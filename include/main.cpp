#include <iostream>
#include <thread>
#include "Physiks/World.h"
#include "Physiks/Body.h"

using namespace std::chrono_literals;

int main() {

	World w({ 0.0f, 0.0f });
	const float delta = 1.0f / 60.0f;

	auto& b1 = *w.createBody();
	b1.setMass(10.0f)
		.setPosition({ 1.0f, 1.0f })
		.setVelocity({ 1.0f, 0.0f });

	auto& b2 = *w.createBody();
	b2.setMass(20.0f)
		.setPosition({  10.0f, 1.0f })
		.setVelocity({ -1.0f, 0.0f });

	while (true) {
		
		w.update(delta, 1, 1);
		
		std::this_thread::sleep_for(300ms);

	}
	
	return 0;

}