#pragma once
#include "FrameWork/Game.h"

class TowrGame : public towr::Game {
public:
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(towr::Renderer& renderer) override;

};