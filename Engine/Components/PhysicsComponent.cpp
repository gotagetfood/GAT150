#include "PhysicsComponent.h"
#include "Engine.h"

void towr::PhysicsComponent::Update()
{
	m_velocity += m_asseleration * g_time.deltaTime;
	m_owner->m_transform.position += m_velocity * g_time.deltaTime;
	m_velocity *= m_damping;

	m_asseleration = Vector2::zero;
}
