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

		// �÷��̾�� ����� ��ġ�� ũ�� ��������
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


		// �÷��̾�� ��� ������ �Ÿ� ���
		Vector2 distance = playerPos - blockPos;

		// �浹�� �Ͼ ���� �����ϱ� ���� ����
		float overlapX = (playerSize.x / 2.0f + blockSize.x / 2.0f) - abs(distance.x);
		float overlapY = (playerSize.y / 2.0f + blockSize.y / 2.0f) - abs(distance.y);

		// �о�� ����� �Ÿ� ���
		if (overlapX < overlapY) { 
			// �¿�� �о��
			float pushX = (distance.x > 0 ? 1 : -1);
			playerTr->SetPosition(playerPos + Vector2(pushX, 0));
			playerRb->SetVelocity(Vector2::Zero);
		}
		else {
			// ���Ϸ� �о��
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