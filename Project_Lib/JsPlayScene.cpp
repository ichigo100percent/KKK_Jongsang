#include "JsPlayScene.h"
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
#include "Camera.h"
#include "Renderer.h"
#include "Animator.h"
#include "Monster.h"
#include "JSPlayerScript.h"

namespace J
{
	JSPlayScene::JSPlayScene()
	{
	}
	JSPlayScene::~JSPlayScene()
	{
	}
	bool JSPlayScene::Init()
	{
		//GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None);//, Vector2(344.0f, 442.0f)); //Vector2(758.0f, 540.0f));
		//Camera* cameraComp = camera->AddComponent<Camera>();
		//renderer::mainCamera = cameraComp;

		{
			m_Player = object::Instantiate<Player>(enums::eLayerType::Player);
			JSPlayerScript* plScr = m_Player->AddComponent<JSPlayerScript>();

			graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
			Animator* playerAni = m_Player->AddComponent<Animator>();
			playerAni->CreateAnimationByFolder(L"JsIdle", L"../../data/Mushroom", Vector2::Zero, 0.15f);
			playerAni->PlayAnimaiton(L"JsIdle", true);

			m_Player->GetComponent<Transform>()->SetPosition(Vector2(0.0f, 0.0f));
			m_Player->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));
		}

		Scene::Init();
		return true;
	}
	bool JSPlayScene::Update()
	{
		Scene::Update();
		return true;
	}
	bool JSPlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		return true;
	}
	bool JSPlayScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);

		std::wstring str = L"JsPlayScene";
		TextOut(_hdc, 0, 0, str.c_str(), str.length());

		return true;
	}
	void JSPlayScene::OnEnter()
	{
	}
	void JSPlayScene::OnExit()
	{
	}
}