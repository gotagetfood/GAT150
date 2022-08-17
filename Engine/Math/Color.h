#pragma once
#include <cstdint>
#include <iostream>
#include <string>

namespace towr {

	//typedef unsigned char u8_t;
	//using u8_t = unsigned char;

	struct Color {
		uint8_t r, g, b, a;

		uint8_t operator [] (size_t index) const { return (&r)[index]; }
		uint8_t& operator [] (size_t index) { return (&r)[index]; }

		static const Color white;
		static const Color black;
		static const Color red;
		static const Color green;
		static const Color blue;


		friend std::istream& operator >> (std::istream& stream, Color& color);
		friend std::ostream& operator << (std::ostream& stream, const Color& color);

	};
}