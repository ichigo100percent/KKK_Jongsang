#include "PlayScene.h"
#include "JSGameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManager.h"
#include "TitleScene.h"

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
			bg = new Player();
			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"TR");

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"../../data/CloudOcean.png");

			AddGameObject(bg, eLayerType::BackGround);
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

		if (Input::GetkeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}

		return true;
	}
	bool PlayScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
		std::wstring str = L"Play Scene";
		TextOut(_hdc, 0, 0, str.c_str(), str.length());
		return true;
	}
	bool PlayScene::Release()
	{
		Scene::Release();
		return true;
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		auto tr = bg->GetComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
	}
}