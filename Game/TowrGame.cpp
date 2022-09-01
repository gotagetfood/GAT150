#include "TowrGame.h"
#include "GameComponents/EnemyComponent.h"
#include "Engine.h"

void TowrGame::Initialize(){
	REGISTER_CLASS(EnemyComponent);
	//towr::g_scene = std::make_unique<towr::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "txt/prefabs.txt","txt/tilemap.txt", "txt/level.txt"};

	for (auto sceneName : sceneNames){

		bool success = towr::json::Load(sceneName, document);
		if (!success) {
			LOG("could not load scene %s", sceneName.c_str());
			continue;
		}
		towr::g_scene.Read(document);
	
	}
	towr::g_scene.Initialize();

	for (int i = 0; i < 10; i++) {
		auto actor = towr::Factory::Instance().Create<towr::Actor>("Coin");
		actor->m_transform.position = { towr::randomf(0,600), 100.0f };
		actor->Initialize();

		towr::g_scene.Add(std::move(actor));

		auto actor2 = towr::Factory::Instance().Create<towr::Actor>("bat");
		actor2->m_transform.position = { towr::randomf(0,600), 100.0f };
		actor2->Initialize();

		towr::g_scene.Add(std::move(actor2));
	}

	auto actor2 = towr::Factory::Instance().Create<towr::Actor>("nightmare");
	actor2->m_transform.position = { towr::randomf(0,600), 300.0f };
	actor2->Initialize();

	towr::g_scene.Add(std::move(actor2));

	towr::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&TowrGame::OnAddPoints, this, std::placeholders::_1));
}

void TowrGame::Shutdown(){
	towr::g_scene.RemoveAll();
}

void TowrGame::Update(){
	switch (m_gameState)
	{
	case gameState::titleScreen:
		if (towr::g_inputSystem.GetKeyState(towr::key_space) == towr::InputSystem::KeyState::Pressed) {

			//towr::g_scene.GetActorFromName("Title")->SetActive(false);
	
			m_gameState = gameState::gamestart;

		}
		break;
	case gameState::gamestart:
		ResetPoints();

		m_gameState = gameState::game;
		break;
	case gameState::game:
		break;
	case gameState::gameOver:
		m_stateTimer -= towr::g_time.deltaTime;
		if (m_stateTimer <= 0) {
			m_gameState = gameState::titleScreen;
		}
		break;
	default:
		break;
	}

	towr::g_scene.Update();
}

void TowrGame::Draw(towr::Renderer& renderer){
	towr::g_scene.Draw(renderer);
}

void TowrGame::OnAddPoints(const towr::Event& event){
	AddPoints(std::get<int>(event.data));

	std::cout << event.name << std::endl;
	std::cout << GetScore() << std::endl;
}

void TowrGame::OnPlayerDead(const towr::Event& event){
	m_gameState = gameState::gameOver;
	m_stateTimer = 10;

}
