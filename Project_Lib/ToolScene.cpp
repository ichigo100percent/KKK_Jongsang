#include "ToolScene.h"
#include "Object.h"
#include "Tile.h"
#include "TilemapRenderer.h"
#include "Resources.h"
#include "Texture.h"
#include "Camera.h"
#include "Renderer.h"
#include "Input.h"

namespace J
{
	ToolScene::ToolScene()
	{
	}
	ToolScene::~ToolScene()
	{
	}
	bool ToolScene::Init()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		Tile* tile = object::Instantiate<Tile>(eLayerType::Tile);
		TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();


		tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));

		Scene::Init();
		return true;
	}
	bool ToolScene::Update()
	{
		Scene::Update();
		return true;
	}
	bool ToolScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::LButton))
		{
			Vector2 pos = Input::GetMousePosition();
			
			int idxX = pos.x / TilemapRenderer::TileSize.x;
			int idxY = pos.y / TilemapRenderer::TileSize.y;

			Tile* tile = object::Instantiate<Tile>(eLayerType::Tile);
			TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));

			tile->SetPosition(idxX, idxY);
		}
		return true;
	}
	bool ToolScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(_hdc, TilemapRenderer::TileSize.x * i, 0, NULL);
			LineTo(_hdc, TilemapRenderer::TileSize.x * i, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(_hdc, 0, TilemapRenderer::TileSize.y * i, NULL);
			LineTo(_hdc, 1000, TilemapRenderer::TileSize.y * i);
		}

		return true;
	}
	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		//int wmId = LOWORD(wParam);
		//// 메뉴 선택을 구문 분석합니다:
		//switch (wmId)
		//{
		//case IDM_ABOUT:
		//	DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		//	break;
		//case IDM_EXIT:
		//	DestroyWindow(hWnd);
		//	break;
		//default:
		//	return DefWindowProc(hWnd, message, wParam, lParam);
		//}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		J::graphics::Texture* texture
			= J::Resources::Find<J::graphics::Texture>(L"SpringFloor");

		TransparentBlt(hdc
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, texture->GetHdc()
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, RGB(255, 0, 255));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}