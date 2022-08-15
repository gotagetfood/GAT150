#include "ModelComponent.h"
#include "Renderer/Model.h"
#include "FrameWork/Actor.h"

namespace towr{
	void ModelComponent::Update(){
		//
	}
	void ModelComponent::Draw(Renderer& renderer){
		m_model->Draw(renderer, m_owner->m_transform);
	}
}