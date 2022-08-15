#include "Actor.h"
#include "Components/RenderComponent.h"
#include "Engine.h"

namespace towr {
	void Actor::Update(){
		if (m_parent) m_transform.Update(m_parent->m_transform.matrix);
		m_transform.Update();

		for (auto& component : m_components) {
			component->Update();
		}
		for (auto& child : m_children) {
			child->Update();
		}


	}

	void towr::Actor::Draw(Renderer& renderer){
		for (auto& component : m_components) {
			auto renderComponent = dynamic_cast<RenderComponent*>(component.get());
			if (renderComponent) {
				renderComponent->Draw(renderer);
			}
			//component->Update();
		}
		for (auto& child : m_children) {
			child->Draw(renderer);
		}

	}

	void Actor::AddChild(std::unique_ptr<Actor> child){

		child->m_parent = this;
		
		//child towr::g_scene = towr::g_scene
		m_children.push_back(std::move(child));
	}

	void Actor::AddComponent(std::unique_ptr<Component> component){
		component->m_owner = this;
		m_components.push_back(std::move(component));
	}
}
