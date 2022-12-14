#include "InputSystem.h"
#include <SDL.h>
#include <iostream>

namespace towr {
	//keybord
	const uint32_t key_space = SDL_SCANCODE_SPACE;
	const uint32_t key_up = SDL_SCANCODE_W;
	const uint32_t key_left = SDL_SCANCODE_A;
	const uint32_t key_down = SDL_SCANCODE_S;
	const uint32_t key_right = SDL_SCANCODE_D;
	const uint32_t key_escape = SDL_SCANCODE_ESCAPE;

	//mouse
	const uint32_t button_left = 0;
	const uint32_t button_middle = 1;
	const uint32_t button_right = 2;

	void towr::InputSystem::Initialize(){
		const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys);

		m_keyboardState.resize(m_numKeys);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		m_prevKeyboardState = m_keyboardState;
	}

	void towr::InputSystem::Shutdown() {
		//
	}

	void towr::InputSystem::Update(){
		SDL_Event event;
		SDL_PollEvent(&event);

		//save previous keyboard state
		m_prevKeyboardState = m_keyboardState;

		//get current keyboard state
		const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		//mouse
		m_prevMouseButtonState = m_mouseButtonState;
		int x, y;
		uint32_t buttons = SDL_GetMouseState(&x, &y);
		m_mousePosition = towr::Vector2{ x , y };
		m_mouseButtonState[0] = buttons & SDL_BUTTON_LMASK; // buttons [0001] & [0RML] 
		m_mouseButtonState[1] = buttons & SDL_BUTTON_MMASK; // buttons [0010] & [0RML] 
		m_mouseButtonState[2] = buttons & SDL_BUTTON_RMASK; // buttons [0100] & [0RML] 

	}
	InputSystem::KeyState InputSystem::GetKeyState(int key)
	{
		KeyState keyState = KeyState::Idle;

		bool keyDown = GetKeyDown(key);
		bool prevKeyDown = GetPreviousKeyDown(key);

		if (keyDown == false && prevKeyDown == false) { keyState = Idle; }
		if (keyDown == true && prevKeyDown == false) { keyState = Pressed; }
		if (keyDown == true && prevKeyDown == true) { keyState = Held; }
		if (keyDown == false && prevKeyDown == true) { keyState = Released; }

		return keyState;
	}
	InputSystem::KeyState InputSystem::GetButtonState(uint32_t button)
	{
		KeyState keyState = KeyState::Idle;

		bool buttonDown = GetButtonDown(button);
		bool prevButtonDown = GetPreviousButtonDown(button);

		if (buttonDown == false && prevButtonDown == false) { keyState = Idle; }
		if (buttonDown == true && prevButtonDown == false) { keyState = Pressed; }
		if (buttonDown == true && prevButtonDown == true) { keyState = Held; }
		if (buttonDown == false && prevButtonDown == true) { keyState = Released; }

		return keyState;
	}
}
