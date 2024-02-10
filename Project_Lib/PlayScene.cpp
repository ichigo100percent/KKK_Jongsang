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
			GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(808.0f,439.5f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			renderer::mainCamera = cameraComp;

			m_Player = object::Instantiate<Player>(enums::eLayerType::Player, Vector2(400.0f,250.0f));
			SpriteRenderer* sr = m_Player->AddComponent<SpriteRenderer>();
			sr->SetSize(Vector2(1.0f, 1.0f));
			//m_Player->AddComponent<PlayerScript>();
			m_Player->AddScript<PlayerScript>();
			m_Player->AddScript<JsScript>();

			graphics::Texture* playerTexture = Resources::Find<graphics::Texture>(L"Player");
			sr->SetTexture(playerTexture);

			GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
			SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
			//bgSr->SetSize(Vector2(3.0f, 3.0f));

			graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
			bgSr->SetTexture(bgTexture);

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