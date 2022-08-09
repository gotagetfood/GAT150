#pragma once
#include "FrameWork/Component.h"

namespace towr {
	class PlayerComponent : public Component {
	public:
		PlayerComponent() = default;

		void Update() override;
	};
}
