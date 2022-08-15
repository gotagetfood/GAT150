#pragma once
#include "Components/RenderComponent.h"

namespace towr {
	class Model;

	class ModelComponent : public RenderComponent {
	public:
		// Inherited via RenderComponent
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

	public:
		std::shared_ptr<Model> m_model;
	};
}