#pragma once
#include "FrameWork/Component.h"
#include "Physics/ICollision.h"

namespace towr {
	class PlayerComponent : public Component, public ICollison {
	public:
		PlayerComponent() = default;

		void Initialize() override;
		void Update() override;

		CLASS_DECLARATION(PlayerComponent)

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;


	public:
		float speed = 1.0f;


		

	};
}
