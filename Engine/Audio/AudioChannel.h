#pragma once

namespace FMOD
{
	// !! forward declare FMOD Channel 
	class Channel;
}

namespace towr
{
	class AudioChannel
	{
	public:
		AudioChannel() = default;
		AudioChannel(FMOD::Channel* channel) { m_channel = channel; }

		bool IsPlaying();
		void Stop();

		void SetPitch(float pitch);
		float GetPitch();

		void SetVolume(float pitch);
		float GetVolume();
		// !! create SetPitch/GetPitch (takes float, returns float) 
		// !! create SetVolume/GetVolume (takes float, returns float) 

	private:
		FMOD::Channel* m_channel = nullptr;
	};
}