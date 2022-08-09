#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

void towr::PlayerComponent::Update(){
	
	float thrust = 0;
	if (towr::g_inputSystem.GetKeyState(towr::key_up) == InputSystem::KeyState::Held) {
		thrust = 1000;
		std::cout << "down" << std::endl;
	}

	//move
	Vector2 direction = Vector2::zero;
	if (towr::g_inputSystem.GetKeyState(towr::key_left) == InputSystem::KeyState::Held) {
		m_owner->m_transform.rotation += -180 * g_time.deltaTime;
		//irection = Vector2::left;
	}
	if (towr::g_inputSystem.GetKeyState(towr::key_right) == InputSystem::KeyState::Held) {
		m_owner->m_transform.rotation += 180 * g_time.deltaTime;
		direction = Vector2::right;
	}
	/*if (towr::g_inputSystem.GetKeyDown(towr::key_up) == InputSystem::KeyState::Held) {
		direction = Vector2::up;
	}*/
	if (towr::g_inputSystem.GetKeyState(towr::key_down) == InputSystem::KeyState::Held) {
		direction = Vector2::down;
	}
	auto component = m_owner->GetComponent<PhysicsComponent>();
	if (component) {
		//thrust force
		Vector2 force = Vector2::Rotate( { 1, 0 },math::DegToRad(m_owner->m_transform.rotation)) * thrust;
		component->ApplyForce(force);

		// gravitational force
		force = (Vector2{ 400, 300 } - m_owner->m_transform.position).Noralized() * 100.0f;
		component->ApplyForce(force);
	}
	m_owner->m_transform.position += direction * 30 * g_time.deltaTime;

	//sound thing
	if (g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Pressed) {
		auto component = m_owner->GetComponent<AudioComponent>();
		if (component) {
			component->Play();
		}
	}
	
}