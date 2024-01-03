#pragma once
#include "Std.h"
#include "GameObject.h"

namespace J
{
	class Core
	{
	public:
		Core();
		virtual ~Core();

	public:
		bool Init(HWND _hwnd);
		bool Frame();
		bool Render();
		bool Release();


		bool Run();

	private:
		HWND m_Hwnd;
		HDC  m_Hdc;
		float m_fSpeed;
	};
}