#pragma once
#include "Scene.h"

namespace J
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		bool Init()override;
		bool Update()override;
		bool LateUpdate()override;
		bool Render(HDC _hdc)override;
		bool Release()override;

	private:
	};
}
