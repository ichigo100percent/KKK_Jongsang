#include "BoxCollider2D.h"
#include "Transform.h"
#include "JSGameObject.h"
#include "Renderer.h"
#include "Camera.h"
#include "CollisionManager.h"

namespace J
{
	BoxCollider2D::BoxCollider2D()
		: Collider(eColliderType::Rect2D)
	{
	}
	BoxCollider2D::~BoxCollider2D()
	{
	}
	bool BoxCollider2D::Init()
	{
		return true;
	}
	bool BoxCollider2D::Update()
	{
		return true;
	}
	bool BoxCollider2D::LateUpdate()
	{
		return true;
	}
	bool BoxCollider2D::Render(HDC _hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

			Vector2 offset = GetOffset();

			HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
			HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, transparentBrush);

			HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
			HPEN oldPen = (HPEN)SelectObject(_hdc, greenPen);

			Rectangle(_hdc
				, pos.x
				, pos.y
				, pos.x + 100.0f * GetSize().x
				, pos.y + 100.0f * GetSize().y);

			//Rectangle(_hdc
			//	, pos.x + offset.x
			//	, pos.y + offset.y
			//	, pos.x + offset.x + 100.0f * GetSize().x
			//	, pos.y + offset.y + 100.0f * GetSize().y);

			SelectObject(_hdc, oldBrush);
			SelectObject(_hdc, oldPen);
			DeleteObject(greenPen);
	

		return true;
	}
}