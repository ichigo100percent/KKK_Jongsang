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
		// ȭ����ǥ�踦 ��ȯ�Ѵ�.
		GetCursorPos(&m_MousePos);
		// Ŭ���̾�Ʈ ��ǥ��� ��ȯ�Ѵ�.
		ScreenToClient(hWnd, &m_MousePos);

		for (int iKey = 0; iKey < 255; iKey++)
		{
			//			GetKeyState(iKey);
						// iKey�� �ش��ϴ� Ű�� ���¸� ��ȯ�ް�
			SHORT sKey = GetAsyncKeyState(iKey);
			// 8     0     0    0
			// 1000  0000  0000 0000
			//         & 
			// 1000  0000  0000 0000
			if (sKey & 0x8000) // ������.
			{
				// ���������ӿ��� 
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
			else // ���� �����ӿ����� �������� �ʾҴ�.
			{
				// ���������ӿ��� 
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
