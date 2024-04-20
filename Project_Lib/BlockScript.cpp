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

		// �÷��̾�� ����� ��ġ�� ũ�� ��������
		Vector2 playerPos = playerTr->GetPosition();
		Vector2 playerSize = playerCol->GetSize();

		Vector2 blockPos = blockTr->GetPosition();
		Vector2 blockSize = blockCol->GetSize();

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
		}
		else {
			// ���Ϸ� �о��
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

		// �÷��̾�� ����� ��ġ�� ũ�� ��������
		Vector2 playerPos = playerTr->GetPosition();
		Vector2 playerSize = playerCol->GetSize();

		Vector2 blockPos = blockTr->GetPosition();
		Vector2 blockSize = blockCol->GetSize();

		// �÷��̾�� ��� ������ �Ÿ� ���
		Vector2 distance = playerPos - blockPos;

		// �浹�� �Ͼ ���� �����ϱ� ���� ����
		float overlapX = (playerSize.x / 2.0f + blockSize.x / 2.0f) - abs(distance.x);
		float overlapY = (playerSize.y / 2.0f + blockSize.y / 2.0f) - abs(distance.y);

		
	}
	void BlockScript::OnCollisionExit(Collider* other)
	{

	}
	bool BlockScript::IsGrounded(Transform* playerTr, Collider* playerCol, Transform* blockTr)
	{
		// �÷��̾��� �ٴ� ��ġ�� ����մϴ�.
		float playerBottom = playerTr->GetPosition().y + playerCol->GetSize().y * 100.0f / 2.0f;

		// ����� ���� ��ġ�� ����մϴ�.
		float blockTop = blockTr->GetPosition().y - blockTr->GetScale().y * 100.0f / 2.0f;

		// �÷��̾��� �ٴ� ��ġ�� ����� ���� ��ġ���� ������ Ȯ���Ͽ� �ٴڿ� ���� ���¸� ��ȯ�մϴ�.
		return playerBottom >= blockTop;
	}
	void BlockScript::PushPlayer(Transform* playerTr, Collider* playerCol, Transform* blockTr, bool isGrounded)
	{
		// �÷��̾�� ����� �浹 ������ ����մϴ�.
		float playerRadiusX = playerCol->GetSize().x * 100.0f / 2.0f;
		float blockRadiusX = blockTr->GetScale().x * 100.0f / 2.0f;

		// �÷��̾�� ����� ���� �Ÿ��� ����մϴ�.
		float distanceX = fabs(playerTr->GetPosition().x - blockTr->GetPosition().x);

		// ���� �÷��̾ ����� �¿����� ��ġ�ϰ�, �ٴڿ� ���� ���°� �ƴ϶��
		if (distanceX < playerRadiusX + blockRadiusX && !isGrounded)
		{
			// �÷��̾ �о���ϴ�.
			Vector2 playerPos = playerTr->GetPosition();
			float pushDirection = playerTr->GetPosition().x < blockTr->GetPosition().x ? -1.0f : 1.0f;
			playerPos.x += pushDirection * (playerRadiusX + blockRadiusX - distanceX);
			playerTr->SetPosition(playerPos);
		}
	}
}