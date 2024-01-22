#pragma once
#include "Std.h"
#include "JSGameObject.h"

namespace J
{
	class Core
	{
	public:
		Core();
		virtual ~Core();

	public:
		bool Init(HWND _hwnd, UINT _width, UINT _height);
		bool Frame();
		bool Render();
		bool Release();


		bool Run();

	private:
		HWND m_Hwnd;
		HDC  m_Hdc;

		HDC		m_BackHdc;
		HBITMAP m_Backbitmap;

		UINT	m_Width;
		UINT	m_Height;

		GameObject obj;
		//float m_fSpeed;
	};
}