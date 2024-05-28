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