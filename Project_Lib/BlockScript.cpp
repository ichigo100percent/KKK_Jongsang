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


		//if (playerTr->GetPosition().y > blockTr->GetPosition().y + blockCol->GetSize().y / 2.0f)
		//{
		//	playerRb->SetVelocity(Vector2(playerRb->GetVelocity().x, 0.0f));
		//}

		Transform* playerTr = other->GetOwner()->GetComponent<Transform>();
		Rigidbody* playerRb = other->GetOwner()->GetComponent<Rigidbody>();
		Collider* playerCol = other->GetOwner()->GetComponent<Collider>();

		Transform* blockTr = this->GetOwner()->GetComponent<Transform>();
		Collider* blockCol = this->GetOwner()->GetComponent<Collider>();

		// 플레이어와 블록의 위치와 크기 가져오기
		Vector2 playerPos = playerTr->GetPosition();
		Vector2 playerSize = playerCol->GetSize();

		Vector2 blockPos = blockTr->GetPosition();
		Vector2 blockSize = blockCol->GetSize();

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
		}
		else {
			// 상하로 밀어내기
			float pushY = (distance.y > 0 ? 1 : -1);
			playerTr->SetPosition(playerPos + Vector2(0, pushY));
		}

	}
	void BlockScript::OnCollisionStay(Collider* other)
	{
		Transform* playerTr = other->GetOwner()->GetComponent<Transform>();
		Rigidbody* playerRb = other->GetOwner()->GetComponent<Rigidbody>();
		Collider* playerCol = other->GetOwner()->GetComponent<Collider>();

		Transform* blockTr = this->GetOwner()->GetComponent<Transform>();
		Collider* blockCol = this->GetOwner()->GetComponent<Collider>();

		// 플레이어와 블록의 위치와 크기 가져오기
		Vector2 playerPos = playerTr->GetPosition();
		Vector2 playerSize = playerCol->GetSize();

		Vector2 blockPos = blockTr->GetPosition();
		Vector2 blockSize = blockCol->GetSize();

		// 플레이어와 블록 사이의 거리 계산
		Vector2 distance = playerPos - blockPos;

		// 충돌이 일어난 축을 결정하기 위한 변수
		float overlapX = (playerSize.x / 2.0f + blockSize.x / 2.0f) - abs(distance.x);
		float overlapY = (playerSize.y / 2.0f + blockSize.y / 2.0f) - abs(distance.y);

		
	}
	void BlockScript::OnCollisionExit(Collider* other)
	{

	}
	bool BlockScript::IsGrounded(Transform* playerTr, Collider* playerCol, Transform* blockTr)
	{
		// 플레이어의 바닥 위치를 계산합니다.
		float playerBottom = playerTr->GetPosition().y + playerCol->GetSize().y * 100.0f / 2.0f;

		// 블록의 윗면 위치를 계산합니다.
		float blockTop = blockTr->GetPosition().y - blockTr->GetScale().y * 100.0f / 2.0f;

		// 플레이어의 바닥 위치가 블록의 윗면 위치보다 높은지 확인하여 바닥에 닿은 상태를 반환합니다.
		return playerBottom >= blockTop;
	}
	void BlockScript::PushPlayer(Transform* playerTr, Collider* playerCol, Transform* blockTr, bool isGrounded)
	{
		// 플레이어와 블록의 충돌 범위를 계산합니다.
		float playerRadiusX = playerCol->GetSize().x * 100.0f / 2.0f;
		float blockRadiusX = blockTr->GetScale().x * 100.0f / 2.0f;

		// 플레이어와 블록의 수평 거리를 계산합니다.
		float distanceX = fabs(playerTr->GetPosition().x - blockTr->GetPosition().x);

		// 만약 플레이어가 블록의 좌우측에 위치하고, 바닥에 닿은 상태가 아니라면
		if (distanceX < playerRadiusX + blockRadiusX && !isGrounded)
		{
			// 플레이어를 밀어냅니다.
			Vector2 playerPos = playerTr->GetPosition();
			float pushDirection = playerTr->GetPosition().x < blockTr->GetPosition().x ? -1.0f : 1.0f;
			playerPos.x += pushDirection * (playerRadiusX + blockRadiusX - distanceX);
			playerTr->SetPosition(playerPos);
		}
	}
}