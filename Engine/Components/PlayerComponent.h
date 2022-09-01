#pragma once
#include "FrameWork/Component.h"
#include "CharacterComponent.h"

namespace towr {
	class PlayerComponent : public CharacterComponent {
	public:
		PlayerComponent() = default;

		void Initialize() override;
		void Update() override;

		CLASS_DECLARATION(PlayerComponent)

		virtual void OnNotify(const Event& event) override;
		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;


	public:
		float jump = 3000;
	

	};
}
