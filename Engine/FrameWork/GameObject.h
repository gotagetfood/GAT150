#pragma once
#include "../Math/Transform.h"

namespace towr {
	class GameObject {
	public:
		GameObject() = default;
		

		virtual void Update() = 0;


		Transform m_transform;
	protected:

	};
}