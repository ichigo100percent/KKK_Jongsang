#include "CircleCollider2D.h"
#include "Transform.h"
#include "JSGameObject.h"
#include "Renderer.h"
#include "Camera.h"

namespace J
{
	CircleCollider2D::CircleCollider2D()
		: Collider(enums::eColliderType::Circle2D)
		, m_Radius(0.0f)
	{
	}
	CircleCollider2D::~CircleCollider2D()
	{
	}
	bool CircleCollider2D::Init()
	{
		return true;
	}
	bool CircleCollider2D::Update()
	{
		return true;
	}
	bool CircleCollider2D::LateUpdate()
	{
		return true;
	}
	bool CircleCollider2D::Render(HDC _hdc)
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

		Vector2 rightBottom;
		rightBottom.x = pos.x + offset.x + 100 * GetSize().x;
		rightBottom.y = pos.y + offset.y + 100 * GetSize().y;

		Ellipse(_hdc, pos.x + offset.x
			, pos.y + offset.y
			, rightBottom.x
			, rightBottom.y);

		SelectObject(_hdc, oldBrush);
		SelectObject(_hdc, oldPen);
		DeleteObject(greenPen);

		return true;
	}
}