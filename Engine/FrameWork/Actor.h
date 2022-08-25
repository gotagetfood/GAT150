#pragma once
#include "GameObject.h"
#include "Component.h"
#include <vector>

namespace towr {
	class Scene;
	class Renderer;

	class Actor : public GameObject, public ISerializable {
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_transform{ transform } {}
		//Actor(const Model& model,const Transform& transform) : 
			//GameObject{ transform },
			//m_model{ model } {}

		virtual void Update() override;
		virtual void Draw(Renderer& renderer);
		virtual void Initialize() override;

		// Inherited via ISerializable
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void AddChild(std::unique_ptr<Actor> child);

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return 0; }//{ return m_model.GetRadius() * std::max(m_transform.scale.x, m_transform.scale.y); }

		const std::string& GetTag() { return tag; }
		void SetTag(const std::string& tag) { this->tag = tag; }
		const std::string& GetName() { return name; }
		void SetName(const std::string& name) { this->name = name; }

		void AddComponent(std::unique_ptr<Component> component);
		template<typename T>
		T* GetComponent();

		void SetDestory() { m_destory = true; }

		friend class Scene;
		friend class Component;

		Transform m_transform;
	protected:
		std::string name;
		std::string tag;

		bool m_destory = false;
		//physics
		Vector2 m_velocity;
		float m_damping = 1.0f;
		
		Actor* m_parent = nullptr;
		std::vector<std::unique_ptr<Component>> m_components;
		std::vector<std::unique_ptr<Actor>> m_children;


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