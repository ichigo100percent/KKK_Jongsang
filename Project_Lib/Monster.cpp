#include "Monster.h"
#include "Input.h"
#include "Transform.h"
#include "JSTime.h"

namespace J
{
	bool Monster::Init()
	{
		GameObject::Init();
		return true;
	}
	bool Monster::Update()
	{
		GameObject::Update();
		return true;
	}
	bool Monster::LateUpdate()
	{
		GameObject::LateUpdate();
		return true;
	}
	bool Monster::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
		return true;
	}
	bool Monster::Release()
	{
		GameObject::Release();
		return true;
	}
}