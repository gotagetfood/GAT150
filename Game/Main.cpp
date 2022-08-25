#include "Engine.h"
#include <iostream>

using namespace std;



int main() {
	


	towr::InitializeMemory();
	towr::SetFilePath("../Assets");

	//create systems
	towr::g_renderer.Initialize();
	towr::g_audioSystem.Initialize();
	towr::g_inputSystem.Initialize();
	towr::g_resources.Initialize();
	towr::g_physicsSystem.Initialize();

	towr::Engine::Instance().Register();

	
	//Create Window
	towr::g_renderer.CreateWindow("Neumont", 800, 600);
	//towr::g_renderer.SetClearColor(towr::Color{ 30, 30, 30, 255 });

	//create scene / actors

	rapidjson::Document document;
	bool success = towr::json::Load("level.txt", document);

	towr::g_scene.Read(document);
	towr::g_scene.Initialize();
	{


		//float angle = 0.0f;

		//updating systems
		bool quit = false;
		while (!quit) {

			//engine updates
				//game.Update();
				towr::g_time.Tick();
				towr::g_inputSystem.Update();
				towr::g_scene.Update();
				towr::g_physicsSystem.Update();

			//angle += 90.0f * towr::g_time.deltaTime;


			//render and draw
			towr::g_renderer.BeginFrame();

				//game.Draw(towr::g_renderer);
				towr::g_scene.Draw(towr::g_renderer);
				//game.Draw

			towr::g_renderer.EndFrame();

			if (towr::g_inputSystem.GetKeyDown(towr::key_escape)) quit = true;
		}
	}
	towr::g_scene.RemoveAll();


	towr::g_physicsSystem.Shutdown();
	towr::g_resources.Shutdown();
	towr::g_inputSystem.Shutdown();
	towr::g_audioSystem.Shutdown();
	towr::g_renderer.Shutdown();
}