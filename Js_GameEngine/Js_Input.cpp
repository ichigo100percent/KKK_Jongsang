#include "Js_Input.h"
#include "Js_Core.h"



namespace Js
{
	DWORD Input::KeyCode[256] = {};
	POINT Input::m_MousePos = {};

	Input::Input()
	{

	}

	void    Input::DebugPrint(int iKey)
	{
#ifdef _DEBUG
		static int iPushCounter = 0;
		TCHAR msgKey[MAX_PATH] = { 0, };
		_stprintf_s(msgKey, L"KEY=%d(%d)\n", iKey, iPushCounter++);
		OutputDebugString(msgKey);
#endif
	}
	void    Input::DebugMousePos()
	{
#ifdef _DEBUG
		TCHAR msgKey[MAX_PATH] = { 0, };
		_stprintf_s(msgKey, L"Mouse X=%d, Y=%d\n",
			m_MousePos.x, m_MousePos.y);
		OutputDebugString(msgKey);
#endif
	}
	
	void    Input::Init()
	{
		ZeroMemory(&KeyCode, sizeof(DWORD) * 256);
	}

	void    Input::Update(HWND hWnd)
	{
		// 화면좌표계를 반환한다.
		GetCursorPos(&m_MousePos);
		// 클라이언트 좌표계로 변환한다.
		ScreenToClient(hWnd, &m_MousePos);

		for (int iKey = 0; iKey < 255; iKey++)
		{
			//			GetKeyState(iKey);
						// iKey에 해당하는 키의 상태를 반환받고
			SHORT sKey = GetAsyncKeyState(iKey);
			// 8     0     0    0
			// 1000  0000  0000 0000
			//         & 
			// 1000  0000  0000 0000
			if (sKey & 0x8000) // 눌렀다.
			{
				// 이전프레임에서 
				if (KeyCode[iKey] == KEY_FREE ||
					KeyCode[iKey] == KEY_UP)
				{
					KeyCode[iKey] = KEY_PUSH;
				}
				else
				{
					KeyCode[iKey] = KEY_HOLD;
				}
			}
			else // 현재 프레임에서는 눌러지지 않았다.
			{
				// 이전프레임에서 
				if (KeyCode[iKey] == KEY_PUSH ||
					KeyCode[iKey] == KEY_HOLD)
				{	
					KeyCode[iKey] = KEY_UP;
				}
				else
				{
					KeyCode[iKey] = KEY_FREE;
				}
			}
		}

	}
	void    Input::KeyTest()
	{
		/*
		 * VK_0 - VK_9 are the same as ASCII '0' - '9' (0x30 - 0x39)
		 * 0x3A - 0x40 : unassigned
		 * VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
		 */
		if (KeyCode['A'] == KEY_PUSH)
		{
			DebugPrint('A');
		}
		if (KeyCode['A'] == KEY_HOLD)
		{
			DebugPrint('A');
		}
		if (KeyCode['A'] == KEY_UP)
		{
			DebugPrint('A');
		}

		//if (g_dwKeyState[VK_LBUTTON] == KEY_PUSH)
		//{
		//	DebugPrint(VK_LBUTTON);
		//}
		//if (g_dwKeyState[VK_RBUTTON] == KEY_PUSH)
		//{
		//	DebugPrint(VK_RBUTTON);
		//}
		//if (g_dwKeyState[VK_MBUTTON] == KEY_PUSH)
		//{
		//	DebugPrint(VK_MBUTTON);
		//}
		//if (g_dwKeyState['W'] == KEY_PUSH)
		//{
		//	DebugPrint('W');
		//}
		//if (g_dwKeyState['S'] == KEY_PUSH)
		//{
		//	DebugPrint('S');
		//}
		//if (g_dwKeyState['A'] == KEY_PUSH)
		//{
		//	DebugPrint('A');
		//}
		//if (g_dwKeyState['D'] == KEY_PUSH)
		//{
		//	DebugPrint('D');
		//}	
	}
	DWORD   Input::KeyCheck(DWORD dwKey)
	{
		return KeyCode[dwKey];
	}
}

/*
extern Js::Core core;

namespace Js
{

	std::vector<Input::Key> Input::Keys = {};
	POINT Input::Input::mMousePosition = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
	};

	void Input::Init()
	{
		createKeys();
	}

	void Input::Update()
	{
		getMousePositionByWindow();
		updateKeys();
	}
	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void Input::updateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void
			{
				updateKey(key);
			});
	}

	void Input::updateKey(Input::Key& key)
	{
		if (GetFocus())
		{
			if (isKeyDown(key.keyCode))
				updateKeyDown(key);
			else
				updateKeyUp(key);

			//getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}

	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;
		else
			key.state = eKeyState::Down;

		key.bPressed = true;
	}
	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;

		key.bPressed = false;
	}
	void Input::getMousePositionByWindow()
	{
		//POINT mousePos = { };
		GetCursorPos(&mMousePosition);
		ScreenToClient(core.GetHWND(), &mMousePosition);

		//mMousePosition.x = mousePos.x;
		//mMousePosition.y = mousePos.y;

		//UINT width = core.GetWidth();
		//UINT height = core.GetHeight();

		//mMousePosition.x = -1.0f;
		//mMousePosition.y = -1.0f;

	}
	void Input::clearKeys()
	{
		for (Key& key : Keys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
				key.state = eKeyState::Up;
			else if (key.state == eKeyState::Up)
				key.state = eKeyState::None;

			key.bPressed = false;
		}
	}
}
*/