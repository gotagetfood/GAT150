#pragma once
#include "FrameWork/Component.h"
#include "Physics/ICollision.h"
#include "Physics/PhysicsSystem.h"
#include <functional>

namespace towr {
	class Actor;

	class CollisionComponent : public Component, public ICollison {
	public:
		using functionPtr = std::function<void(Actor*)>;

	public:
		virtual void Initialize() override;
		virtual void Update() override;

		void OnCollisionEnter(Actor* other) override;
		void OnCollisionExit(Actor* other) override;

		void SetCollisionEnter(functionPtr function) { m_enterFunction = function; };
		void SetCollisionExit(functionPtr function) { m_exitFunction = function; };

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	private:
		PhysicsSystem::CollisionData data;
		functionPtr m_enterFunction;
		functionPtr m_exitFunction;

	};
}