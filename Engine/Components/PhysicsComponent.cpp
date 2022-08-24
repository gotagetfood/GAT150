#include "PhysicsComponent.h"
#include "Engine.h"

void towr::PhysicsComponent::Update()
{
	m_velocity += m_asseleration * g_time.deltaTime;
	m_owner->m_transform.position += m_velocity * g_time.deltaTime;
	m_velocity *= m_damping;

	m_asseleration = Vector2::zero;
}

bool towr::PhysicsComponent::Write(const rapidjson::Value& value) const{
	return true;
}

bool towr::PhysicsComponent::Read(const rapidjson::Value& value){
	READ_DATA(value, m_damping);
	READ_DATA(value, m_velocity);
	READ_DATA(value, m_asseleration);

	return true;
}


