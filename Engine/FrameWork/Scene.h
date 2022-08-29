#pragma once
#include "Actor.h"
#include <list>
#include <memory>

namespace towr {
	//class Actor;
	class Renderer;
	class Game;

	class Scene :public GameObject, public ISerializable{
	public:
		Scene() = default;
		Scene(Game* game) : m_game(game) {}
		Scene(const Scene& other) {}
		~Scene() = default;

		CLASS_DECLARATION(Scene)

		void Update();
		void Draw(Renderer& renderer);

		void Initialize() override;

		// Inherited via ISerializable
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Add(std::unique_ptr<Actor> actor);
		void RemoveAll();

		template<typename T>
		T* GetActor();

		Game* GetGame() { return m_game; }
		void SetGame(Game* game) { m_game = game; }

	private:
		Game* m_game;
		std::list<std::unique_ptr<Actor>> m_actors;

	};


	template<typename T>
	inline T* Scene::GetActor()
	{
		//int i = 45
		//float f = static_cast<float>(i);
		for (auto& actor : m_actors){
			T* result = dynamic_cast<T*>(actor.get());
			if (result) return result;
		}
		return nullptr;
	}
}