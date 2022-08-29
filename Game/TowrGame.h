#pragma once
#include "FrameWork/Game.h"
#include "FrameWork/Event.h"

class TowrGame : public towr::Game {
public:
	enum gameState {
		titleScreen,
		gamestart,
		game,
		gameOver
	};

public:
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(towr::Renderer& renderer) override;

	void OnAddPoints(const towr::Event& event);
	void OnPlayerDead(const towr::Event& event);

private:
	gameState m_gameState = gameState::titleScreen;
	float m_stateTimer = 0;
};