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
		bool Update();
		bool LateUpdate();
		bool Render();
		bool Release();

		void Destroy();
		bool Run();

		HWND GetHwnd() { return m_Hwnd; }
		HDC  GetHdc() { return m_Hdc; }
		UINT GetWidth() { return m_Width; }
		UINT GetHeight() { return m_Height; }

	private:
		bool clearRenderTarget();
		bool copyRenderTarget();
		bool adjustWindowRect(HWND _hwnd, UINT _width, UINT _height);
		bool CreateBuffer(UINT _width, UINT _height);
		bool InitEtc();


	private:
		HWND m_Hwnd;
		HDC  m_Hdc;

		HDC		m_BackHdc;
		HBITMAP m_Backbitmap;

		UINT	m_Width;
		UINT	m_Height;

		GameObject obj;
	};
}