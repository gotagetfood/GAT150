#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

void towr::PlayerComponent::Initialize() {
	CharacterComponent::Initialize();

	g_eventManager.Subscribe("EVENT_HEALTH", std::bind(&CharacterComponent::OnNotify, this, std::placeholders::_1), m_owner);

}

void towr::PlayerComponent::Update(){

	// set camera 
	auto camera = towr::g_scene.GetActorFromName("Camera");
	if (camera)
	{
		camera->m_transform.position = math::Lerp(camera -> m_transform.position, m_owner->m_transform.position, 2 * g_time.deltaTime);
	}
	
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

	Vector2 velocity;
	auto component = m_owner->GetComponent<PhysicsComponent>();
	if (component) {
		component->ApplyForce(direction * speed);
		velocity = component->m_velocity;
	}

	//jump
	if (g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Pressed) {
		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component) {
			component->ApplyForce(Vector2::up * 300);
		}
	}

	auto renderComponent = m_owner->GetComponent<RenderComponent>();
	if (renderComponent) {
		if (velocity.x != 0) renderComponent->SetFlipHorizontal(velocity.x < 0);
	}
	
}

void towr::PlayerComponent::OnCollisionEnter(Actor* other)
{
	if (other->GetName() == "Coin") {
		Event event;
		event.name = "EVENT_ADD_POINTS";
		event.data = 100;

		g_eventManager.Notify(event);
		other->SetDestroy();
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
	CharacterComponent::Read(value);
	READ_DATA(value, jump);
	return true;
}

void towr::PlayerComponent::OnNotify(const Event& event){
	if (event.name == "EVENT_DAMAGE") {
		health -= std::get<float>(event.data);
		if (health <= 0) {
			//player dead
		}
	}
	if (event.name == "EVENT_HEALTH") {
		health += std::get<float>(event.data);
	}
}
