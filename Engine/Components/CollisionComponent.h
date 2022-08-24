#pragma once
#include "FrameWork/Component.h"
#include "Physics/ICollision.h"
#include "Physics/PhysicsSystem.h"

namespace towr {
	class Actor;

	class CollisionComponent : public Component, public ICollison {
	public:
		virtual void Initialize() override;
		virtual void Update() override;

		void OnCollisionEnter(Actor* other) override;
		void OnCollisionExit(Actor* other) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	private:
		PhysicsSystem::CollisionData data;


	};
}