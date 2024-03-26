#include "ToolScene.h"
#include "Object.h"
#include "Tile.h"
#include "TilemapRenderer.h"
#include "Resources.h"
#include "Texture.h"
#include "Camera.h"
#include "Renderer.h"

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
		return true;
	}
	bool ToolScene::Render(HDC _hdc)
	{

		//for (size_t i = 0; i < 50; i++)
		//{
		//	MoveToEx(_hdc, (16 * 3) * i, 0, NULL);
		//	LineTo(_hdc, (16 * 3) * i, 1000);
		//}

		//for (size_t i = 0; i < 50; i++)
		//{
		//	MoveToEx(_hdc, 0, (16 * 3) * i, NULL);
		//	LineTo(_hdc, 1000, (16 * 3) * i);
		//}

		Scene::Render(_hdc);
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