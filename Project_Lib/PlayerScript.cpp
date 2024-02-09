#include "PlayerScript.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"
#include "JSGameObject.h"

namespace J
{
	PlayerScript::PlayerScript()
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	bool PlayerScript::Init()
	{
		return true;
	}
	bool PlayerScript::Update()
	{
		auto tr = GetOwner()->GetComponent<Transform>();
		auto pos = tr->GetPosition();

		if (Input::GetkeyDown(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetkeyDown(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetkeyDown(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetkeyDown(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}


		return true;
	}
	bool PlayerScript::LateUpdate()
	{
		return true;
	}
	bool PlayerScript::Render(HDC _hdc)
	{
		return true;
	}
	bool PlayerScript::Release()
	{
		return true;
	}
}