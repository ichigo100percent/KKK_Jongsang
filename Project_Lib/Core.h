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

		bool clearRenderTarget();
		bool copyRenderTarget();
		bool adjustWindowRect(HWND _hwnd, UINT _width, UINT _height);
		bool CreateBuffer(UINT _width, UINT _height);
		bool InitEtc();

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