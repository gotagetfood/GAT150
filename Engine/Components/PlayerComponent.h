#pragma once
#include "FrameWork/Component.h"

namespace towr {
	class PlayerComponent : public Component {
	public:
		PlayerComponent() = default;

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Update() override;

	public:
		float speed = 0.0f;

	};
}
