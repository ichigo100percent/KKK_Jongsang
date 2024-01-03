#pragma once
#include "Std.h"

//enum class keyState
//{
//	Down = 0,
//	Pressed,
//	Up,
//	None,
//};

enum { KEY_FREE = 0, KEY_PUSH, KEY_HOLD, KEY_UP };


class Input
{
public:
	DWORD		m_dwKeyState[256];

	static Input& Get()
	{
		static Input mgr;

		return mgr;
	}

public:
	bool	 Init();
	bool	 Frame();
	bool	 Render();
	bool	 Release();

public:
	void	 createKeys();
	void	 updateKeys();
};

