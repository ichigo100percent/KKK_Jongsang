#include "Floor.h"
#include "Input.h"
#include "Transform.h"
#include "JSTime.h"

namespace J
{
	Floor::Floor()
	{
	}
	Floor::~Floor()
	{
	}
	bool Floor::Init()
	{
		GameObject::Init();
		return true;
	}
	bool Floor::Update()
	{
		GameObject::Update();
		return true;
	}
	bool Floor::LateUpdate()
	{
		GameObject::LateUpdate();
		return true;
	}
	bool Floor::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
		return true;
	}
}