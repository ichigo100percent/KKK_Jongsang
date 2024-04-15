#include "DeadLineScript.h"
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
	DeadLineScript::DeadLineScript()
		: m_ShouldRespawn(false)
	{
	}
	DeadLineScript::~DeadLineScript()
	{
	}
	bool DeadLineScript::Init()
	{
		return true;
	}
	bool DeadLineScript::Update()
	{
		return true;
	}
	bool DeadLineScript::LateUpdate()
	{
		if (m_ShouldRespawn)
		{
			gotoBack();
			m_ShouldRespawn = false; // 다음 LateUpdate에서 다시 호출되지 않도록 플래그를 재설정합니다.
		}

		return true;
	}
	bool DeadLineScript::Render(HDC _hdc)
	{
		return true;
	}
	void DeadLineScript::OnCollisionEnter(Collider* other)
	{
		auto  mario = other->GetOwner()->GetComponent<MarioScript>();
		if (mario->GetisDie() || mario)
		{
			m_ShouldRespawn = true;
		}
	}
	void DeadLineScript::OnCollisionStay(Collider* other)
	{
	}
	void DeadLineScript::OnCollisionExit(Collider* other)
	{
	}
	void DeadLineScript::gotoBack()
	{
		SceneManager::LoadScene(L"TitleScene");
	}
}