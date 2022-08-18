#include "AudioComponent.h"
#include "Engine.h"

void towr::AudioComponent::Update(){

}

void towr::AudioComponent::Play(){
	towr::g_audioSystem.PlayAudio(m_soundname);
}

void towr::AudioComponent::Stop(){

}

bool towr::AudioComponent::Write(const rapidjson::Value& value) const
{
	return false;
}

bool towr::AudioComponent::Read(const rapidjson::Value& value)
{
	return false;
}
