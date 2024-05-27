#pragma once
#include "std.h"
#include <tchar.h>

namespace Js
{
	enum KeyState
	{
		KEY_FREE = 0,	// ����
		KEY_UP,			// �ٷ� �����ٰ� ���»���
		KEY_PUSH,		// ���»��¿��� ������ ��
		KEY_HOLD,		// ����� ���� ��(������ ������ ���ݵ� ������.)
	};

	class Input
	{
	public:
		Input();

		static void    DebugPrint(int iKey);
		static void    DebugMousePos();
		static void	   Init();
		static void    Update(HWND hWnd);
		static DWORD   KeyCheck(DWORD dwKey);
		static void    KeyTest();

	private:
		static DWORD   KeyCode[256];
		static POINT   m_MousePos;
	};
}

/*
namespace Js
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
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Init();
		static void Update();

		__forceinline static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
		__forceinline static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
		__forceinline static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }
		__forceinline static POINT GetMousePosition() { return mMousePosition; }
		//__forceinline static math::Vector2 GetMouseToWorldPosition() { return mMousePosition; }

	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(Input::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(Input::Key& key);
		static void updateKeyUp(Input::Key& key);
		static void getMousePositionByWindow();
		static void clearKeys();


	private:
		static std::vector<Key> Keys;
		static POINT mMousePosition;
	};
}
*/