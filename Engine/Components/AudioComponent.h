#pragma once 
#include "Framework/Component.h" 
#include "Audio/AudioChannel.h"
// !! include the Audio Channel 

namespace towr
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;
		~AudioComponent(); // !! this is added (stop play when destroyed) 

		void Initialize() override; // !! this is added (create definition) 
		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Play();
		void Stop();

	public:
		AudioChannel m_channel;

		// !! your names do not have to be the same 
		std::string sound_name;
		float volume = 1;
		float pitch = 1;
		bool play_on_start = false;
		bool loop = false;
	};
}