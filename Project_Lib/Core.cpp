#include "Core.h"

namespace J
{
	Core::Core()
		:m_Hwnd(nullptr)
		,m_Hdc(nullptr)
		,m_fSpeed(0.0f)
	{

	}

	Core::~Core()
	{

	}

	bool Core::Init(HWND _hwnd)
	{
		m_Hwnd = _hwnd;
		m_Hdc = GetDC(m_Hwnd);
		return true;
	}

	bool Core::Frame()
	{
		m_fSpeed += 0.005f;
		return true;
	}

	bool Core::Render()
	{
		HBRUSH blue = CreateSolidBrush(RGB(0, 0, 255));
		SelectObject(m_Hdc, blue);
		HPEN red = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
		SelectObject(m_Hdc, red);

		Rectangle(m_Hdc, 100 + m_fSpeed, 100, 50, 50);

		DeleteObject(blue);
		DeleteObject(red);

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