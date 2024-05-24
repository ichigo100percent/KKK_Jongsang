#pragma once
#include "std.h"

namespace Js
{
	class Window
	{
	public:
		void CreateRegisterClass(HINSTANCE _hInstance);
		BOOL InitInstance(const int& _width, const int& _height);
		void Run();

		virtual void GameRun() {}

	protected:
		HWND m_Hwnd;
		HINSTANCE m_HInstance;
	};
}
