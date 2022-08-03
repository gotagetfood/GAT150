#include "Engine.h"
#include <iostream>

using namespace std;

int main() {


	towr::InitializeMemory();
	towr::SetFilePath("../Assets");

	//create systems
	towr::g_renderer.Initialize();

	//audio
	towr::g_audioSystem.Initialize();

	//input System
	towr::g_inputSystem.Initialize();
	
	//Create Window
	towr::g_renderer.CreateWindow("Neumont", 800, 600);
	towr::g_renderer.SetClearColor(towr::Color{ 30, 30, 30, 255 });

	{
		//SpaceShooter game;
		//game.Initialize();
		std::shared_ptr<towr::Texture> texture = std::make_shared<towr::Texture>();
		texture->Create(towr::g_renderer, "pngs/yellow mushroom.png");
		//game.Initialize



		//updating systems
		bool quit = false;
		while (!quit) {
			if (towr::g_inputSystem.GetKeyDown(towr::key_escape)) quit = true;

				//game.Update();
			towr::g_inputSystem.Update();

			//render and draw
			towr::g_renderer.BeginFrame();

				//game.Draw(towr::g_renderer);
			towr::g_renderer.Draw(texture, { 400, 300 }, 0);
				//game.Draw

			towr::g_renderer.EndFrame();
		}
	}
	towr::g_inputSystem.Shutdown();
	towr::g_audioSystem.Shutdown();
	towr::g_renderer.Shutdown();
}