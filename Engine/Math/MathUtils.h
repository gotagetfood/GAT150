#pragma once

namespace math {
	const float PI = 3.14159265359f; // 180
	const float TWOPI = 6.28318530718f; //360
	const float HALFPI = 1.57079632679f; //90

	inline float DegToRad(float degrees) {
		return degrees * (PI / 180);
	}

	inline float RadToDeg(float radians) {
		return radians * (180 / PI);
	}

	int sqr(int x); 
	int half(int v);
}

