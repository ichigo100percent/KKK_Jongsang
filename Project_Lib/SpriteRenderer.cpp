#include "SpriteRenderer.h"
#include "JSGameObject.h"
#include "Transform.h"

namespace J
{
	SpriteRenderer::SpriteRenderer()
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	bool SpriteRenderer::Init()
	{
		return true;
	}
	bool SpriteRenderer::Update()
	{
		return true;
	}
	bool SpriteRenderer::LateUpdate()
	{
		return true;
	}
	bool SpriteRenderer::Render(HDC _hdc)
	{

		//파랑브러쉬 생성
		HBRUSH blue = CreateSolidBrush(RGB(0, 0, 255));

		//파랑브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, blue);


		HPEN red = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(_hdc, red);
		SelectObject(_hdc, oldPen);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Rectangle(_hdc,  tr->GetX(),  tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY());

		SelectObject(_hdc, oldBrush);
		DeleteObject(blue);
		DeleteObject(red);


		return true;
	}
	bool SpriteRenderer::Release()
	{
		return true;
	}
}