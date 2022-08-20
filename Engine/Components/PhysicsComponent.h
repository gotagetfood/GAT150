#pragma once
#include "FrameWork/Component.h"
#include "Math/Vector2.h"

namespace towr {
	class PhysicsComponent : public Component {
	public:
		PhysicsComponent() = default;

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Update() override;
		void ApplyForce(const Vector2& force) { m_asseleration += force; };

	public:
		Vector2 m_velocity;
		Vector2 m_asseleration;

		float m_damping = 1.0f;
	};
}