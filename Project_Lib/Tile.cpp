#include "Tile.h"
#include "Input.h"
#include "Transform.h"
#include "JSTime.h"


namespace J
{
	bool Tile::Init()
	{
		GameObject::Init();
		return true;
	}

	bool Tile::Update()
	{
		GameObject::Update();
		return true;
	}

	bool Tile::LateUpdate()
	{
		GameObject::LateUpdate();
		return true;
	}

	bool Tile::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
		return true;
	}
}
