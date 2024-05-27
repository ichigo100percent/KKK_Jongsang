#pragma once
#include "std.h"

namespace Js
{
	class Window
	{
	public:
		void CreateRegisterClass(HINSTANCE _hInstance);
		BOOL InitInstance(const int& _width, const int& _height);

		HWND GetHWND() { return m_Hwnd; }
		HINSTANCE GetHINSTANCE() { return m_HInstance; }

	protected:
		HWND m_Hwnd;
		HINSTANCE m_HInstance;
	};
}
