#pragma once
#include <string>

namespace towr {
	class Resource {
	public:
		virtual bool Create(std::string name, ...) = 0;

	};
}