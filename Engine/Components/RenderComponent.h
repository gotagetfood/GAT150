#pragma once
#include "FrameWork/Component.h"

namespace towr {
	class Renderer;

	class RenderComponent : public Component {
	public:
		virtual void Draw(Renderer& renderer) = 0;

	};
}