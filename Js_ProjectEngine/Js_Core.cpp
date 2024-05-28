#include "Js_Core.h"
#include "Js_Input.h"
#include "Js_Time.h"

namespace Js
{
	Core::Core()
	{

	}

	bool Core::Init() { return true; }
	bool Core::Update() { return true; }
	bool Core::Render() { return true; }

	bool Core::EngineInit()
	{
		Time::Init();
		Input::Init();
		Device::CreateDevice();
		return true;
	}
	bool Core::EngineUpdate()
	{
		Time::Update();
		Input::Update(m_Hwnd);

		return true;
	}
	bool Core::EngineRender()
	{
		Device::PreRender();

		//Input::DebugMousePos();
		Input::KeyTest();
		;

		//m_Time += Time::DeltaTime();
		//OutputDebugStringA((std::to_string(m_Time) + '\n').c_str());


		Device::PostRender();
		return true;
	}

	void Core::Run()
	{
		EngineInit();
		MSG msg = { };

		while (WM_QUIT != msg.message)
		{
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				// 메세지가 없을 경우 여기서 처리
				// 게임 로직이 들어가야 한다.
				if (!EngineUpdate() || !EngineRender())
					break;
			}
		}
	}
}