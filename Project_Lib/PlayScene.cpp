#include "PlayScene.h"
#include "JSGameObject.h"

namespace J
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	bool PlayScene::Init()
	{
		GameObject* obj = new GameObject();
		obj->SetPosition(50, 500);
		AddGameObject(obj);

		return true;
	}
	bool PlayScene::Update()
	{
		Scene::Update();
		return true;
	}
	bool PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		return true;
	}
	bool PlayScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
		return true;
	}
	bool PlayScene::Release()
	{
		return true;
	}
}