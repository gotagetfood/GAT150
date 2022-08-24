#pragma once

namespace towr {
	class Actor;

	class ICollison {
	public:
		virtual void OnCollisionEnter(Actor* other) = 0;
		virtual void OnCollisionExit(Actor* other) = 0;

	};
}