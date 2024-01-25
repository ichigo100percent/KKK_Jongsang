#include "Player.h"


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
