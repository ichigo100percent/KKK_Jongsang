#include "PlayScene.h"
#include "JSGameObject.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"
#include "PlayerScript.h"
#include "Camera.h"
#include "Renderer.h"
#include "JsScript.h"
#include "Animator.h"
#include "Monster.h"
#include "MonsterScript.h"

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

		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None/*, Vector2(758.0f, 540.0f) */);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		{
			GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
			SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();

			graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
			bgSr->SetTexture(bgTexture);
			bg->GetComponent<Transform>()->SetScale(Vector2(1.f, 1.f));
			bg->GetComponent<Transform>()->SetPosition(Vector2(-758.0f, -540.0f));
		}

		/*
		{
			m_Player = object::Instantiate<Player>(enums::eLayerType::Player);

			m_Player->AddComponent<PlayerScript>();
			//m_Player->AddScript<PlayerScript>();	
			//m_Player->AddScript<JsScript>();

			graphics::Texture* CatTexture = Resources::Find<graphics::Texture>(L"Cat");
			Animator* animator = m_Player->AddComponent<Animator>();
			animator->CreateAnimation(L"DownWalk", CatTexture, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimation(L"RightWalk", CatTexture, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimation(L"UpWalk", CatTexture, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimation(L"LeftWalk", CatTexture, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimation(L"SitDown", CatTexture, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.07f);

			animator->PlayAnimaiton(L"SitDown", false);

			m_Player->GetComponent<Transform>()->SetPosition(Vector2(250.0f, 250.0f));
			m_Player->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
			m_Player->GetComponent<Transform>()->SetRotation(60.0f);

		}
		*/

		{
			m_Player = object::Instantiate<Player>(enums::eLayerType::Player);
			PlayerScript* plScript =  m_Player->AddComponent<PlayerScript>();

			graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
			Animator* playerAnimator = m_Player->AddComponent<Animator>();
			playerAnimator->CreateAnimation(L"Idle", playerTex
				, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
			playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex
				, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);
			playerAnimator->PlayAnimaiton(L"Idle", false);

			m_Player->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
			playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);
		}

		//{
		//	Monster* cat = object::Instantiate<Monster>(enums::eLayerType::Npc);
		//	cat->AddComponent<MonsterScript>();

		//	graphics::Texture* CatTex = Resources::Find<graphics::Texture>(L"Cat");
		//	Animator* catAnimator = cat->AddComponent<Animator>();
		//	catAnimator->CreateAnimation(L"DownWalk", CatTex, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//	catAnimator->CreateAnimation(L"RightWalk", CatTex, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//	catAnimator->CreateAnimation(L"UpWalk", CatTex, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//	catAnimator->CreateAnimation(L"LeftWalk", CatTex, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//	catAnimator->CreateAnimation(L"SitDown", CatTex, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.07f);
		//	catAnimator->CreateAnimation(L"Grooming", CatTex, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.07f);
		//	catAnimator->CreateAnimation(L"LayDown", CatTex, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.07f);

		//	catAnimator->PlayAnimaiton(L"SitDown", false);
		//	cat->GetComponent<Transform>()->SetPosition(Vector2(0.0f, 0.0f));
		//	cat->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));
		//	cameraComp->SetTarget(cat);
		//}

		//게임 오브젝트 생성 후 레이어와 게임오브젝트들의 init()함수를 호출
		Scene::Init();
		
		
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