#include "TowrGame.h"
#include "Engine.h"

void TowrGame::Initialize(){
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
	}
}

void TowrGame::Shutdown(){
	towr::g_scene.RemoveAll();
}

void TowrGame::Update(){
	towr::g_scene.Update();
}

void TowrGame::Draw(towr::Renderer& renderer){
	towr::g_scene.Draw(renderer);
}
