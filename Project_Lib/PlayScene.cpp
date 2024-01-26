#include "PlayScene.h"
#include "JSGameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"

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
		//GameObject* obj = new GameObject();
		//obj->SetPosition(50, 500);
		//AddGameObject(obj);

		//{
		//	Player* pl = new Player();
		//	Transform* tr = pl->AddComponent<Transform>();
		//	tr->SetPos(800, 450);
		//	tr->SetName(L"TR");

		//	SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
		//	sr->SetName(L"SR");

		//	AddGameObject(pl);
		//}

		{
			Player* bg = new Player();
			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"TR");

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"../../data/CloudOcean.png");

			AddGameObject(bg);
		}

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