#pragma once
#include "Math/Transform.h"
#include "Serialization/ISerializable.h"

#define CLASS_DECLARATION(class) \
std::unique_ptr<GameObject> Clone() override { return std::make_unique<class>(*this); }
#define REGISTER_CLASS(class) towr::Factory::Instance().Register<class>(#class)

namespace towr {
	class GameObject {
	public:
		GameObject() = default;
		
		virtual std::unique_ptr<GameObject> Clone() = 0;
		virtual void Update() = 0;
		virtual void Initialize() = 0;


		Transform m_transform;
	protected:

	};
}