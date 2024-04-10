#include "CameraScript.h"
#include "Input.h"
#include "Transform.h"
#include "JSTime.h"
#include "JSGameObject.h"
#include "Animator.h"
#include "Object.h"
#include "Resources.h"

namespace J
{
	CameraScript::CameraScript()
	{
	}
	CameraScript::~CameraScript()
	{
	}
	bool CameraScript::Init()
	{
		return true;
	}
	bool CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);

		return true;
	}
	bool CameraScript::LateUpdate()
	{
		return true;
	}
	bool CameraScript::Render(HDC _hdc)
	{
		return true;
	}
}