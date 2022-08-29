#pragma once
#include "RenderComponent.h"
#include "Math/Rect.h"

namespace towr {
	class Texture;

	class SpriteComponent : public RenderComponent {
	public:
		// Inherited via RenderComponent
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		CLASS_DECLARATION(SpriteComponent)

		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;
		
	public:
		Rect source;
		std::shared_ptr<Texture> m_texture;

	};
}