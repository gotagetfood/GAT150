#pragma once
#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

#include "FrameWork/Scene.h"
#include "FrameWork/Game.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"

#include "Renderer/Renderer.h"
#include "Renderer/Model.h"	
#include "Renderer/Font.h"
#include "Renderer/Text.h"

#include <memory>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

namespace towr {
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern Scene g_scene;
	extern AudioSystem g_audioSystem;
}