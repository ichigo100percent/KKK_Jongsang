#pragma once
#include "Std.h"

namespace J
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		LButton, MButton, RButton,
		End,
	};

	class Input
	{
	public:
		struct key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static bool Init();
		static bool Frame();

		static bool GetkeyDown(eKeyCode _code) { return keys[(UINT)_code].state == eKeyState::Down; }
		static bool GetkeyUp(eKeyCode _code) { return keys[(UINT)_code].state == eKeyState::Up; }
		static bool Getkey(eKeyCode _code) { return keys[(UINT)_code].state == eKeyState::Pressed; }
		
	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(Input::key& _key);
		static bool isKeyDown(eKeyCode _code);
		static void updateKeyDown(Input::key& _key);
		static void updateKeyUp(Input::key& _key);
		//static void clearKeys();

	private:
		static vector<key> keys;
	};
}


