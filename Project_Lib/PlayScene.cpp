#include "PlayScene.h"
#include "JSGameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "Object.h"

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

		//{
		//	bg = new Player();
		//	Transform* tr = bg->AddComponent<Transform>();
		//	tr->SetPosition(Vector2(0, 0));
		//	tr->SetName(L"TR");

		//	SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		//	sr->SetName(L"SR");
		//	sr->ImageLoad(L"../../data/CloudOcean.png");

		//	AddGameObject(bg, enums::eLayerType::BackGround);
		//}

		{
			bg = object::Instantiate<Player>
				(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
			bg->SetName(L"BG");
			auto sr = bg->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"../../data/CloudOcean.png");

			//게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init 함수 호출
			Scene::Init();
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
		//auto tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}