#include "BlockScript.h"
#include "Input.h"
#include "Transform.h"
#include "JSTime.h"
#include "JSGameObject.h"
#include "Animator.h"
#include "Object.h"
#include "Rigidbody.h"
#include "MarioScript.h"
#include "BoxCollider2D.h"
#include "CollisionManager.h"

namespace J
{
	BlockScript::BlockScript()
	{
	}
	BlockScript::~BlockScript()
	{
	}
	bool BlockScript::Init()
	{
		return true;
	}
	bool BlockScript::Update()
	{
		return true;
	}
	bool BlockScript::LateUpdate()
	{
		return true;
	}
	bool BlockScript::Render(HDC _hdc)
	{
		return true;
	}
	void BlockScript::OnCollisionEnter(Collider* other)
	{
		Transform* playerTr = other->GetOwner()->GetComponent<Transform>();
		Rigidbody* playerRb = other->GetOwner()->GetComponent<Rigidbody>();
		Collider* playerCol = other->GetOwner()->GetComponent<Collider>();

		Transform* blockTr = this->GetOwner()->GetComponent<Transform>();
		Collider* blockCol = this->GetOwner()->GetComponent<Collider>();

		// 플레이어와 블록의 위치와 크기 가져오기
		Vector2 playerPos = playerTr->GetPosition();
		Vector2 playerSize = playerCol->GetSize() * 100.0f;

		Vector2 blockPos = blockTr->GetPosition();
		Vector2 blockSize = blockCol->GetSize() * 100.0f;

		if (playerTr->GetPosition().y >
			blockTr->GetPosition().y + blockSize.y / 2.0f)
		{
			playerRb->SetVelocity(Vector2(playerRb->GetVelocity().x, 0.0f));
		}

		//MarioScript* mario = other->GetOwner()->GetComponent<MarioScript>();

		//if (!mario->GetisDie())
		//{
		//	playerRb->SetGround(true);
		//}


		// 플레이어와 블록 사이의 거리 계산
		Vector2 distance = playerPos - blockPos;

		// 충돌이 일어난 축을 결정하기 위한 변수
		float overlapX = (playerSize.x / 2.0f + blockSize.x / 2.0f) - abs(distance.x);
		float overlapY = (playerSize.y / 2.0f + blockSize.y / 2.0f) - abs(distance.y);

		// 밀어내는 방향과 거리 계산
		if (overlapX < overlapY) { 
			// 좌우로 밀어내기
			float pushX = (distance.x > 0 ? 1 : -1);
			playerTr->SetPosition(playerPos + Vector2(pushX, 0));
			playerRb->SetVelocity(Vector2::Zero);
		}
		else {
			// 상하로 밀어내기
			float pushY = (distance.y > 0 ? 1 : -1);
			playerTr->SetPosition(playerPos + Vector2(0, pushY));
			playerRb->SetVelocity(Vector2::Zero);
		}

	}
	void BlockScript::OnCollisionStay(Collider* other)
	{

	}
	void BlockScript::OnCollisionExit(Collider* other)
	{

	}

}