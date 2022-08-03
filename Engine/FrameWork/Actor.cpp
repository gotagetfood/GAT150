#include "Actor.h"

namespace towr {
	void towr::Actor::Draw(Renderer& renderer){
		m_model.Draw(renderer, m_transform.position, m_transform.rotation, m_transform.scale);
	}
}
