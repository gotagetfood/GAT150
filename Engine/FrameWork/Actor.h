#pragma once
#include "GameObject.h"
#include "Component.h"
#include <vector>

namespace towr {
	class Scene;
	class Renderer;

	class Actor : public GameObject {
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_transform{ transform } {}
		//Actor(const Model& model,const Transform& transform) : 
			//GameObject{ transform },
			//m_model{ model } {}

		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return 0; }//{ return m_model.GetRadius() * std::max(m_transform.scale.x, m_transform.scale.y); }
		std::string& GetTag() { return m_tag; }

		void AddComponent(std::unique_ptr<Component> component);
		template<typename T>
		T* GetComponent();

		friend class Scene;

		Transform m_transform;
	protected:
		std::string m_tag;
		bool m_destory = false;
		//physics
		Vector2 m_velocity;
		float m_damping = 1.0f;

		std::vector<std::unique_ptr<Component>> m_components;
		//Model m_model;
	};

	template<typename T>
	inline T* Actor::GetComponent()
	{
		for (auto& component : m_components) {
			T* result = dynamic_cast<T*>(component.get());
			if (result) return result;
		}
		return nullptr;
	}
}