#include "Goomba.h"


namespace J
{
	Goomba::Goomba()
	{
	}
	Goomba::~Goomba()
	{
	}
	bool Goomba::Init()
	{
		GameObject::Init();
		return true;
	}
	bool Goomba::Update()
	{
		GameObject::Update();
		return true;
	}
	bool Goomba::LateUpdate()
	{
		GameObject::LateUpdate();
		return true;
	}
	bool Goomba::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
		return true;
	}
}