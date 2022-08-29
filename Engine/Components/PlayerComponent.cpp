#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

void towr::PlayerComponent::Initialize() {
	auto component = m_owner->GetComponent<CollisionComponent>();
	if (component){
		component->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
		component->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
	}
}

void towr::PlayerComponent::Update(){
	
	float thrust = 0;
	if (towr::g_inputSystem.GetKeyState(towr::key_up) == InputSystem::KeyState::Held) {
		thrust = speed;
	}

	//move
	Vector2 direction = Vector2::zero;
	if (towr::g_inputSystem.GetKeyState(towr::key_left) == InputSystem::KeyState::Held) {
		direction = Vector2::left;
		//gm_owner->m_transform.rotation += -180 * g_time.deltaTime;
	}
	if (towr::g_inputSystem.GetKeyState(towr::key_right) == InputSystem::KeyState::Held) {
		direction = Vector2::right;
		//m_owner->m_transform.rotation += 180 * g_time.deltaTime;
	}
	if (towr::g_inputSystem.GetKeyState(towr::key_down) == InputSystem::KeyState::Held) {
		//direction = Vector2::down;
	}

	auto component = m_owner->GetComponent<PhysicsComponent>();
	if (component) {
		component->ApplyForce(direction * speed);
	}

	//jump
	if (g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Pressed) {
		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component) {
			component->ApplyForce(Vector2::up * 300);
		}
	}
	
}

void towr::PlayerComponent::OnCollisionEnter(Actor* other)
{
	if (other->GetName() == "Coin") {
		Event event;
		event.name = "EVENT_ADD_POINTS";
		event.data = 100;

		g_eventManager.Notify(event);
		other->SetDestory();
	}
	std::cout << "enter\n";
}

void towr::PlayerComponent::OnCollisionExit(Actor* other)
{
	std::cout << "exit\n";
}

bool towr::PlayerComponent::Write(const rapidjson::Value& value) const{
	return true;
}

bool towr::PlayerComponent::Read(const rapidjson::Value& value){
	READ_DATA(value, speed);
	return true;
}
