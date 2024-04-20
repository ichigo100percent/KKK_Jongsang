#include "GoombaScript.h"
#include "PlayerScript.h"
#include "Input.h"
#include "Transform.h"
#include "JSTime.h"
#include "JSGameObject.h"
#include "Animator.h"
#include "Monster.h"
#include "MonsterScript.h"
#include "Object.h"
#include "Resources.h"
#include "Rigidbody.h"

#include "Mario.h"
#include "MarioScript.h"
#include "Goomba.h"
#include "GoombaScript.h"
#include "DeadLineScript.h"

namespace J
{
	GoombaScript::GoombaScript()
	{
	}
	GoombaScript::~GoombaScript()
	{
	}
	bool GoombaScript::Init()
	{
		return false;
	}
	bool GoombaScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100 * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100 * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100 * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100 * Time::DeltaTime();
		}

		tr->SetPosition(pos);

		return true;
	}
	bool GoombaScript::LateUpdate()
	{
		return true;
	}
	bool GoombaScript::Render(HDC _hdc)
	{
		return true;
	}
	void GoombaScript::OnCollisionEnter(Collider* other)
	{

	}
	void GoombaScript::OnCollisionStay(Collider* other)
	{
	}
	void GoombaScript::OnCollisionExit(Collider* other)
	{
	}
}