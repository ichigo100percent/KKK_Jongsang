#pragma once
#include "Scene.h"

namespace J
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;

	private:

	};
}
