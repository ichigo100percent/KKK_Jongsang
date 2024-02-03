#include "Player.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"


namespace J
{
	bool Player::Init()
	{
		GameObject::Init();
		return true;
	}

	bool Player::Update()
	{
		GameObject::Update();
		return true;
	}

	bool Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (Input::Getkey(eKeyCode::Right))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
		return true;
	}

	bool Player::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
		return true;
	}

	bool Player::Release()
	{
		GameObject::Release();
		return true;
	}
}
