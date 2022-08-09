#pragma once
#include <cstdint>
#include <iostream>
#include <string>

namespace towr {

	//typedef unsigned char u8_t;
	//using u8_t = unsigned char;

	struct Color {
		uint8_t r, g, b, a;

		static const Color white;
		static const Color black;
		static const Color red;
		static const Color green;
		static const Color blue;


		friend std::istream& operator>> (std::istream& stream, Color& color) {
			std::string line;
			std::getline(stream,line);//get a line from stream
			//line:{#r,#g,#b}

			std::string str;

			//red
			str = line.substr((line.find("{") + 1, line.find(",") - line.find("{")-1));
			color.r = (uint8_t)(std::stof(str) * 255);

			// setting line to another sub section of the string to read green and blue 
			line = line.substr(line.find(",") + 1);
			// line: #g, #b } 

			// green 
			str = line.substr((0, line.find(",") - 1));
			color.g = (uint8_t)(std::stof(str) * 255);

			// blue 
			str = line.substr((line.find(",") + 1, line.find("}") - line.find(",")));
			color.b = (uint8_t)(std::stof(str) * 255);

			// default alpha to 255 
			color.a = 255;

			return stream;
		}
	};
}