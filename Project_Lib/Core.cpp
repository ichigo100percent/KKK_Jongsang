#include "Core.h"
#include "Input.h"
#include "Time.h"

namespace J
{
	Core::Core()
		:m_Hwnd(nullptr)
		,m_Hdc(nullptr)
	{

	}

	Core::~Core()
	{

	}

	bool Core::Init(HWND _hwnd)
	{
		m_Hwnd = _hwnd;
		m_Hdc = GetDC(m_Hwnd);
		Time::Init();
		Input::Init();

		obj.SetPosition(0, 0);
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
		Time::Render(m_Hdc);
		obj.Render(m_Hdc);

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