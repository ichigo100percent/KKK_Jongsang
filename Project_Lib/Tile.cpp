#include "Tile.h"
#include "Input.h"
#include "Transform.h"
#include "JSTime.h"
#include "TilemapRenderer.h"

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
	void Tile::SetPosition(int _x, int _y)
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos;
		pos.x = _x * TilemapRenderer::TileSize.x;
		pos.y = _y * TilemapRenderer::TileSize.y;
		tr->SetPosition(pos);
	}
}
