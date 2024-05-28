#pragma once
#include "Js_Device.h"

namespace Js
{
	class Core : public Device
	{
	public:
		Core();

		virtual bool Init();
		virtual bool Update();
		virtual bool Render();
		void Run();

		bool EngineInit();
		bool EngineUpdate();
		bool EngineRender();

	private:
		float m_Time;
	};
}
