#include "Engine.h"
#include <iostream>

using namespace std;



int main() {
	


	towr::InitializeMemory();
	towr::SetFilePath("../Assets");

	rapidjson::Document document;
	bool success = towr::json::Load("json.txt", document);
	assert(success);


	string s1;
	towr::json::Get(document, "string", s1);
	std::cout << s1 << std::endl;

	bool b1;
	towr::json::Get(document, "boolean", b1);
	std::cout << b1 << std::endl;

	int i1;
	towr::json::Get(document, "integer1", i1);
	std::cout << i1 << std::endl;

	int i2;
	towr::json::Get(document, "integer2", i2);
	std::cout << i2 << std::endl;

	float f1;
	towr::json::Get(document, "float", f1);
	std::cout << f1 << std::endl;

	towr::Vector2 v1;
	towr::json::Get(document, "vector2", v1);
	std::cout << v1 << std::endl;

	towr::Color c1;
	towr::json::Get(document, "color", c1);
	std::cout << c1 << std::endl;


	//create systems
	towr::g_renderer.Initialize();
	towr::g_audioSystem.Initialize();
	towr::g_inputSystem.Initialize();
	towr::g_resources.Initialize();

	towr::Engine::Instance().Register();

	
	//Create Window
	towr::g_renderer.CreateWindow("Neumont", 800, 600);
	towr::g_renderer.SetClearColor(towr::Color{ 30, 30, 30, 255 });

	{


		float angle = 0.0f;

		//updating systems
		bool quit = false;
		while (!quit) {
			if (towr::g_inputSystem.GetKeyDown(towr::key_escape)) quit = true;

			//engine updates
				//game.Update();
				towr::g_time.Tick();
				towr::g_inputSystem.Update();
				towr::g_scene.Update();

			angle += 90.0f * towr::g_time.deltaTime;


			//render and draw
			towr::g_renderer.BeginFrame();

				//game.Draw(towr::g_renderer);
				towr::g_scene.Draw(towr::g_renderer);
				//game.Draw

			towr::g_renderer.EndFrame();
		}
	}
	towr::g_inputSystem.Shutdown();
	towr::g_audioSystem.Shutdown();
	towr::g_renderer.Shutdown();
}