#include "EnemyComponent.h"
#include "Engine.h"
#include <iostream>

void EnemyComponent::Initialize()
{
    CharacterComponent::Initialize();
}

void EnemyComponent::Update()
{
    auto actor = towr::g_scene.GetActorFromName("player");
    if (actor)
    {
        towr::Vector2 direction = actor->m_transform.position - m_owner->m_transform.position;
        towr::Vector2 force = direction.Noralized() * speed;

        auto component = m_owner->GetComponent<towr::PhysicsComponent>();
        if (component) component->ApplyForce(force);
    }
}

void EnemyComponent::OnCollisionEnter(towr::Actor* other)
{
    if (other->GetTag() == "player")
    {
        towr::Event event;
        event.name = "EVENT_DAMAGE";
        event.data = damage;
        event.receiver = other;

        towr::g_eventManager.Notify(event);
    }
}

void EnemyComponent::OnCollisionExit(towr::Actor* other)
{
}

void EnemyComponent::OnNotify(const towr::Event& event)
{
    if (event.name == "EVENT_DAMAGE")
    {
        health -= std::get<float>(event.data);
        if (health <= 0)
        {
            m_owner->SetDestroy();
        }
    }

}

bool EnemyComponent::Write(const rapidjson::Value& value) const
{
    return true;
}

bool EnemyComponent::Read(const rapidjson::Value& value)
{
    CharacterComponent::Read(value);

    return true;
}