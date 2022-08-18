#include "SpriteComponent.h"
#include "Renderer/Renderer.h"
#include "FrameWork/Actor.h"

void towr::SpriteComponent::Update(){

}

void towr::SpriteComponent::Draw(Renderer& renderer){
	renderer.Draw(m_texture, m_owner->m_transform);
}

bool towr::SpriteComponent::Write(const rapidjson::Value& value) const
{
	return false;
}

bool towr::SpriteComponent::Read(const rapidjson::Value& value)
{
	return false;
}
