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
#include "Animator.h"
#include "Monster.h"
#include "MonsterScript.h"
#include "BoxCollider2D.h"
#include "CircleCollider2D.h"
#include "CollisionManager.h"
#include "Tile.h"
#include "TilemapRenderer.h"

#include "JsPlayScene.h"


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
		
		FILE* pFile = nullptr;
		_wfopen_s(&pFile, L"../../data/test", L"rb");

		while (true)
		{
			int idxX = 0;
			int idxY = 0;

			int posX = 0;
			int posY = 0;


			if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			Tile* tile = object::Instantiate<Tile>(eLayerType::Tile, Vector2(posX, posY));
			TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
			tmr->SetIndex(Vector2(idxX, idxY));

			//mTiles.push_back(tile);
		}

		fclose(pFile);

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Npc, true);

		//main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		//배경생성
		/*
		{
			GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
			SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();

			graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
			bgSr->SetTexture(bgTexture);
			bg->GetComponent<Transform>()->SetScale(Vector2(1.f, 1.f));
			bg->GetComponent<Transform>()->SetPosition(Vector2(0.0f, 0.0f));//(-758.0f, -540.0f));
		}
		*/
		//기본적인 Object 애니메이션 구현
		/*
		{
			m_Player = object::Instantiate<Player>(enums::eLayerType::Player);
			m_Player->AddComponent<PlayerScript>();
			BoxCollider2D* collider = m_Player->AddComponent<BoxCollider2D>();
			collider->SetOffset(Vector2(0.0f, 0.0f));

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

			m_Player->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 250.0f));
			m_Player->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
			m_Player->GetComponent<Transform>()->SetRotation(60.0f);
			cameraComp->SetTarget(m_Player);
		}
		*/

		//애니메이션 종료 후 이어지는 이벤트 시스템구현
		
		{
			m_Player = object::Instantiate<Player>(enums::eLayerType::Player);
			//충돌버그 있습
			//object::DontDestroyOnLoad(m_Player);
			PlayerScript* plScript =  m_Player->AddComponent<PlayerScript>();
			BoxCollider2D* collider = m_Player->AddComponent<BoxCollider2D>();
			//CircleCollider2D* collider = m_Player->AddComponent<CircleCollider2D>();
			collider->SetOffset(Vector2(-50.0f, -50.0f));

			graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
			Animator* playerAnimator = m_Player->AddComponent<Animator>();
			playerAnimator->CreateAnimation(L"Idle", playerTex
				, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
			playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex
				, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.05f);
			playerAnimator->PlayAnimaiton(L"Idle", false);

			m_Player->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
			playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);
			m_Player->GetComponent<Transform>()->SetScale(Vector2(1.f, 1.f));
			cameraComp->SetTarget(m_Player);
		}
		
		

		//몬스터 기본움직임 AI구현
		
		{
			Monster* cat = object::Instantiate<Monster>(enums::eLayerType::Npc);
			cat->AddComponent<MonsterScript>();
			cat->SetActive(true);

			graphics::Texture* CatTex = Resources::Find<graphics::Texture>(L"Cat");
			Animator* catAnimator = cat->AddComponent<Animator>();
			BoxCollider2D* collider = cat->AddComponent<BoxCollider2D>();
			//CircleCollider2D* collider = cat->AddComponent<CircleCollider2D>();
			collider->SetOffset(Vector2(-50.0f, -50.0f));
			

			catAnimator->CreateAnimation(L"DownWalk", CatTex, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"RightWalk", CatTex, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"UpWalk", CatTex, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LeftWalk", CatTex, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"SitDown", CatTex, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.07f);
			catAnimator->CreateAnimation(L"Grooming", CatTex, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.07f);
			catAnimator->CreateAnimation(L"LayDown", CatTex, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.07f);

			catAnimator->PlayAnimaiton(L"SitDown", false);
			catAnimator->CreateAnimationByFolder(L"MushroomIdle", L"../../data/Mushroom", Vector2::Zero, 0.12f);
			catAnimator->PlayAnimaiton(L"MushroomIdle", true);

			cat->GetComponent<Transform>()->SetPosition(Vector2(500.0f, 300.0f));
			cat->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));
		}
		

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

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
			//SceneManager::LoadScene(L"JSPlayScene");
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
	
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//auto tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}