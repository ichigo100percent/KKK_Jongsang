#include "Core.h"
#include "Input.h"
#include "Time.h"

namespace J
{
	Core::Core()
		:m_Hwnd(nullptr)
		,m_Hdc(nullptr)
		,m_Width(0)
		,m_Height(0)
		,m_BackHdc(nullptr)
		,m_Backbitmap(nullptr)
	{

	}

	Core::~Core()
	{

	}

	bool Core::Init(HWND _hwnd, UINT _width, UINT _height)
	{
		m_Hwnd = _hwnd;
		m_Hdc = GetDC(m_Hwnd);

		RECT rect = { 0, 0, _width, _height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		m_Width = rect.right - rect.left;
		m_Height = rect.bottom - rect.top;

		SetWindowPos(m_Hwnd, nullptr, 0, 0, m_Width, m_Height, 0);
		ShowWindow(m_Hwnd, true);

		//윈도우 해상도에 맞는 백버퍼(도화지)생성
		m_Backbitmap = CreateCompatibleBitmap(m_Hdc, _width, _height);

		//백버퍼를 가르킬 DC생성
		m_BackHdc = CreateCompatibleDC(m_Hdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(m_BackHdc, m_Backbitmap);
		DeleteObject(oldBitmap);

		Time::Init();
		Input::Init();

		obj.SetPosition(50, 500);
		return true;
	}

	bool Core::Frame()
	{
		Time::Frame();
		Input::Frame();
		obj.Frame();

		return true;
	}

	bool Core::Render()
	{
		Rectangle(m_BackHdc, 0, 0, 1600, 900);

		Time::Render(m_BackHdc);
		obj.Render(m_BackHdc);

		// BackBuffer에 있는걸 원본 Buffer에 복사(그려준다)
		BitBlt(m_Hdc, 0, 0, m_Width, m_Height
			, m_BackHdc, 0, 0, SRCCOPY);

		return true;
	}

	bool Core::Release()
	{
		return true;
	}

	bool Core::Run()
	{
		Frame();
		Render();

		return true;
	}
}