#include "Mario.h"

namespace J
{
	Mario::Mario()
	{
	}
	Mario::~Mario()
	{
	}
	bool Mario::Init()
	{
		GameObject::Init();
		return true;
	}
	bool Mario::Update()
	{
		GameObject::Update();
		return true;
	}
	bool Mario::LateUpdate()
	{
		GameObject::LateUpdate();
		return true;
	}
	bool Mario::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
		return true;
	}
}