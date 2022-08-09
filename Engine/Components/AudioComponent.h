#pragma once
#include "FrameWork/Component.h"

namespace towr {
	class AudioComponent : public Component {
	public:
		AudioComponent() = default;

		void Update() override;

		void Play();
		void Stop();

	public:
		std::string m_soundname;
		float m_volume = 1;
		float m_pitch = 1;
		bool m_playOnAwake = false;
		bool m_loop = false;
	};
}