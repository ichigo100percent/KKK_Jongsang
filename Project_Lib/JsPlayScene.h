#pragma once
#include "Scene.h"

namespace J
{
	class JSPlayScene : public Scene
	{
	public:
		JSPlayScene();
		~JSPlayScene();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* m_Player;
	};
}
