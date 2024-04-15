#include "MarioPlayScene.h"
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
#include "Rigidbody.h"
#include "Floor.h"
#include "FloorScript.h"


#include "Mario.h"
#include "MarioScript.h"
#include "Goomba.h"
#include "GoombaScript.h"
#include "DeadLineScript.h"

namespace J
{
	MarioPlayScene::MarioPlayScene()
	{
	}
	MarioPlayScene::~MarioPlayScene()
	{
	}
	bool MarioPlayScene::Init()
	{
		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		// mario
		{
			Mario* mario = object::Instantiate<Mario>(enums::eLayerType::Player);
			MarioScript* script = mario->AddComponent<MarioScript>();
			BoxCollider2D* collider = mario->AddComponent<BoxCollider2D>();

			mario->GetComponent<Transform>()->SetPosition(Vector2(0.0f, 0.0f));
			mario->AddComponent<Rigidbody>();
			cameraComp->SetTarget(mario);
		}

		// goomba
		{
			Goomba* goomba = object::Instantiate<Goomba>(eLayerType::Monster, Vector2(300.0f, 100.0f));
			goomba->SetName(L"Goomba");
			BoxCollider2D* floorCol = goomba->AddComponent<BoxCollider2D>();
			floorCol->SetSize(Vector2(0.5f, 0.5f));
			floorCol->SetOffset(Vector2(-25.0f, -25.0f));
			goomba->AddComponent<GoombaScript>();
		}

		// floor
		{
			Floor* floor = object::Instantiate<Floor>(eLayerType::Floor, Vector2(100.0f, 200.0f));
			floor->SetName(L"Floor");
			BoxCollider2D* floorCol = floor->AddComponent<BoxCollider2D>();
			floorCol->SetSize(Vector2(10.0f, 1.0f));
			floorCol->SetOffset(Vector2(-100.0f, -50.0f));
			floor->AddComponent<FloorScript>();
		}

		// deadline
		{
			Floor* deadline = object::Instantiate<Floor>(eLayerType::DeadLine, Vector2(-500.0f, 400.0f));
			BoxCollider2D* collider = deadline->AddComponent<BoxCollider2D>();
			collider->SetSize(Vector2(100.0f, 1.0f));
			deadline->AddComponent<DeadLineScript>();
		}

		Scene::Init();
		return true;
	}
	bool MarioPlayScene::Update()
	{
		Scene::Update();
		return true;
	}
	bool MarioPlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		return true;
	}
	bool MarioPlayScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
		return true;
	}
	void MarioPlayScene::OnEnter()
	{
		Scene::OnEnter();
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Npc, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::DeadLine, true);
	}
	void MarioPlayScene::OnExit()
	{
		Scene::OnExit();
	}
}