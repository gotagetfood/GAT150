#pragma once
#include "Math/Transform.h"
#include "Serialization/ISerializable.h"
#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class)

namespace towr {
	class GameObject {
	public:
		GameObject() = default;
		

		virtual void Update() = 0;
		virtual void Initialize() = 0;


		Transform m_transform;
	protected:

	};
}