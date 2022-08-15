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
	towr::g_resources.Initialize();
	
	//Create Window
	towr::g_renderer.CreateWindow("Neumont", 800, 600);
	towr::g_renderer.SetClearColor(towr::Color{ 30, 30, 30, 255 });

	{
		//load game;
			//load assets
			std::shared_ptr<towr::Model> modle_spaceship = towr::g_resources.Get<towr::Model>("mod/space ship.txt");
			std::shared_ptr<towr::Texture> texture_mushroom = towr::g_resources.Get<towr::Texture>("pngs/yellow mushroom.png", &towr::g_renderer);
			std::shared_ptr<towr::Texture> texture_spaceship = towr::g_resources.Get<towr::Texture>("pngs/space ship.png", &towr::g_renderer);
			towr::g_audioSystem.AddAudio("sound", "mp3/sound.mp3");

			//create actors
			towr::Transform transform{ {100,100},90,{3,3} };

			std::unique_ptr<towr::Actor> actor = std::make_unique<towr::Actor>(transform);

			std::unique_ptr<towr::PlayerComponent> Pcomponent = std::make_unique<towr::PlayerComponent>();
			actor->AddComponent(std::move(Pcomponent));

			//std::unique_ptr<towr::SpriteComponent> Scomponent = std::make_unique<towr::SpriteComponent>();
			//Scomponent->m_texture = texture_spaceship;
			//actor->AddComponent(std::move(Scomponent));
			std::unique_ptr<towr::ModelComponent> Mcomponent = std::make_unique<towr::ModelComponent>();
			Mcomponent->m_model = modle_spaceship;
			actor->AddComponent(std::move(Mcomponent));

			std::unique_ptr<towr::AudioComponent> Acomponent = std::make_unique<towr::AudioComponent>();
			Acomponent->m_soundname = "sound";
			actor->AddComponent(std::move(Acomponent));

			std::unique_ptr<towr::PhysicsComponent> PHcomponent = std::make_unique<towr::PhysicsComponent>();
			actor->AddComponent(std::move(PHcomponent));

			//child actor
			towr::Transform transformC{ {40,30},0,{1,1} };
			std::unique_ptr<towr::Actor> child = std::make_unique<towr::Actor>(transformC);

			std::unique_ptr<towr::ModelComponent> McomponentC = std::make_unique<towr::ModelComponent>();
			McomponentC->m_model = modle_spaceship;
			child->AddComponent(std::move(McomponentC));

			actor->AddChild(std::move(child));

			towr::g_scene.Add(std::move(actor));




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
				towr::g_renderer.Draw(texture_mushroom, {370, 250}, angle, {6,6}, {0.5f, 1.0f});
				//game.Draw

			towr::g_renderer.EndFrame();
		}
	}
	towr::g_inputSystem.Shutdown();
	towr::g_audioSystem.Shutdown();
	towr::g_renderer.Shutdown();
}