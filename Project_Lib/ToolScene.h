#pragma once
#include "Scene.h"
#include "Tile.h"

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

		void Save();
		void Load();

	private:
		std::vector<Tile*> m_Tiles;
	};
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);