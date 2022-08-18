#include "Actor.h"
#include "Engine.h"
#include "Components/RenderComponent.h"

namespace towr {
	void Actor::Update(){
		if (m_parent) m_transform.Update(m_parent->m_transform.matrix);
		else m_transform.Update();

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

	bool Actor::Write(const rapidjson::Value& value) const{
		return true;
	}
	bool Actor::Read(const rapidjson::Value& value){
		READ_DATA(value, tag);
		READ_DATA(value, name);

		m_transform.Read(value["transform"]);

		if (value.HasMember("components") && value["components"].IsArray()) {
			for (auto& componentValue : value["components"].GetArray()) {
				std::string type;
				READ_DATA(componentValue, type);

				auto component = Factory::Instance().Create<Component>(type);
				if (component) {
					component->Read(componentValue);
					AddComponent(std::move(component));
				}
			}	
		}

		return true;
	}
}
