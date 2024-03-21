#pragma once
#include "Scene.h"

namespace J
{
	class DontDestroyOnLoad : public Scene
	{
	public:
		DontDestroyOnLoad();
		~ DontDestroyOnLoad();

		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);

		virtual void OnEnter();
		virtual void OnExit();

	private:

	};
}

