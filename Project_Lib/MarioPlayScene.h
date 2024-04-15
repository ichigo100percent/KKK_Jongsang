#pragma once
#include "Scene.h"
namespace J
{
	class MarioPlayScene : public Scene
	{
	public:
		MarioPlayScene();
		~MarioPlayScene();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;

		void OnEnter() override;
		void OnExit() override;
	private:
	};
}
