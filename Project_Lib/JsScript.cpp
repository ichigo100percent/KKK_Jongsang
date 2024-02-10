#include "JsScript.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"
#include "JSGameObject.h"
#include "PlayerScript.h"

namespace J
{
	JsScript::JsScript()
	{
	}
	JsScript::~JsScript()
	{
	}
	bool JsScript::Init()
	{
		return true;
	}
	bool JsScript::Update()
	{
		auto tr = GetOwner()->GetComponent<Transform>();
		auto pos = tr->GetPosition();

		if (Input::Getkey(eKeyCode::D))
		{
			pos.x += 500.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::Getkey(eKeyCode::A))
		{
			pos.x -= 500.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::Getkey(eKeyCode::W))
		{
			pos.y -= 500.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::Getkey(eKeyCode::S))
		{
			pos.y += 500.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		return true;
	}
	bool JsScript::LateUpdate()
	{
		return true;
	}
	bool JsScript::Render(HDC _hdc)
	{
		return true;
	}
	bool JsScript::Release()
	{
		return true;
	}
}