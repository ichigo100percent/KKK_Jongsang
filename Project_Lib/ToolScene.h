#pragma once
#include "Scene.h"

namespace J
{
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		~ToolScene();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;

		void OnEnter() override;
		void OnExit() override;
	};
}
