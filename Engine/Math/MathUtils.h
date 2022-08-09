#pragma once

namespace math {
	constexpr float PI = 3.14159265359f; // 180
	constexpr float TWOPI = 6.28318530718f; //360
	constexpr float HALFPI = 1.57079632679f; //90

	constexpr float DegToRad(float degrees) {
		return degrees * (PI / 180);
	}

	constexpr float RadToDeg(float radians) {
		return radians * (180 / PI);
	}

	int sqr(int x); 
	int half(int v);
}

