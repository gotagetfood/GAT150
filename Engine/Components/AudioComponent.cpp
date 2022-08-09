#include "AudioComponent.h"
#include "Engine.h"

void towr::AudioComponent::Update(){

}

void towr::AudioComponent::Play(){
	towr::g_audioSystem.PlayAudio(m_soundname);
}

void towr::AudioComponent::Stop(){

}
