#pragma once
#include "Serialization/json.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"
#include "Core/Logger.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Physics/PhysicsSystem.h"
#include "Resource/ResourceManager.h"

#include "FrameWork/Scene.h"
#include "FrameWork/Game.h"
#include "FrameWork/Factory.h"
#include "FrameWork/Singleton.h"
#include "FrameWork/EventManager.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/RBPhysicsComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/ModelComponent.h"
#include "Components/SpriteAnimComponent.h"
#include "Components/TextComponent.h"
#include "Components/TilemapComponent.h"

#include "Renderer/Renderer.h"
#include "Renderer/Model.h"	
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Renderer/Model.h"

#include <memory>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <variant>

namespace towr {
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern Scene g_scene;
	extern AudioSystem g_audioSystem;
	extern ResourceManager g_resources;
	extern PhysicsSystem g_physicsSystem;
	extern EventManager g_eventManager;

	class Engine : public Singleton<Engine> {
	public:
		void Register();

	};
}