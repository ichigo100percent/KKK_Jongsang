#include "FloorScript.h"
#include "Input.h"
#include "Transform.h"
#include "JSTime.h"
#include "JSGameObject.h"
#include "Animator.h"
#include "Object.h"
#include "Rigidbody.h"

namespace J
{
	FloorScript::FloorScript()
	{
	}
	FloorScript::~FloorScript()
	{
	}
	bool FloorScript::Init()
	{
		return true;
	}
	bool FloorScript::Update()
	{
		return true;
	}
	bool FloorScript::LateUpdate()
	{
		return true;
	}
	bool FloorScript::Render(HDC _hdc)
	{
		return true;
	}
	void FloorScript::OnCollisionEnter(Collider* other)
	{
		Rigidbody* playerRb = other->GetOwner()->GetComponent<Rigidbody>();
		Transform* playerTr = other->GetOwner()->GetComponent<Transform>();
		Collider* playerCol = other;

		Rigidbody* floorRb = this->GetOwner()->GetComponent<Rigidbody>();
		Transform* floorTr = this->GetOwner()->GetComponent<Transform>();
		Collider* floorCol = this->GetOwner()->GetComponent<Collider>();

		float len = fabs(playerTr->GetPosition().y - floorTr->GetPosition().y);
		float scale = fabs(playerCol->GetSize().y * 100 / 2.0f - floorCol->GetSize().y * 100 / 2.0f);

		if (len < scale)
		{
			Vector2 playerPos = playerTr->GetPosition();
			playerPos.y -= (scale - len) - 1.0f;

			playerTr->SetPosition(playerPos);
		}

		playerRb->SetGround(true);
	}
	void FloorScript::OnCollisionStay(Collider* other)
	{
	}
	void FloorScript::OnCollisionExit(Collider* other)
	{
	}
}