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
		{
			//bg = object::Instantiate<Player>(enums::eLayerType::BackGround);
			//SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			//graphics::Texture* bg = Resources::Find<graphics::Texture>(L"BG");
			//sr->SetTexture(bg);

			//Scene::Init();
		}

		{
			GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(758.0f,540.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			renderer::mainCamera = cameraComp;

			m_Player = object::Instantiate<Player>(enums::eLayerType::Player);

			//SpriteRenderer* sr = m_Player->AddComponent<SpriteRenderer>();
			//sr->SetSize(Vector2(5.0f, 5.0f));
			//graphics::Texture* playerTexture = Resources::Find<graphics::Texture>(L"Cat2");
			//sr->SetTexture(playerTexture);

			m_Player->AddComponent<PlayerScript>();
			m_Player->AddScript<PlayerScript>();
			m_Player->AddScript<JsScript>();


			//graphics::Texture* CatTexture = Resources::Find<graphics::Texture>(L"Cat");
			//Animator* animator = m_Player->AddComponent<Animator>();
			//animator->CreateAnimaiton(L"CatFrontMove", CatTexture, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);
			//animator->PlayAnimaiton(L"CatFrontMove", true);
			graphics::Texture* CatTexture = Resources::Find<graphics::Texture>(L"Cat");
			Animator* animator = m_Player->AddComponent<Animator>();
			animator->CreateAnimaiton(L"DownWalk", CatTexture, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimaiton(L"RightWalk", CatTexture, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimaiton(L"UpWalk", CatTexture, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimaiton(L"LeftWalk", CatTexture, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			animator->CreateAnimaiton(L"SitDown", CatTexture, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

			animator->PlayAnimaiton(L"SitDown", false);

			m_Player->GetComponent<Transform>()->SetPosition(Vector2(250.0f, 250.0f));
			m_Player->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
			m_Player->GetComponent<Transform>()->SetRotation(60.0f);

			GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
			SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();

			graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
			bgSr->SetTexture(bgTexture);
			bg->GetComponent<Transform>()->SetScale(Vector2(0.5f, 0.5f));

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