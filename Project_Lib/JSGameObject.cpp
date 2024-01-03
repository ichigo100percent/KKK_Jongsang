#include "JSGameObject.h"

namespace J
{
	GameObject::GameObject()
	{

	}
	GameObject::~GameObject()
	{

	}

	bool GameObject::Init()
	{
		return true;
	}

	bool GameObject::Frame()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			m_fX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			m_fX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			m_fY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			m_fY += 0.01f;
		}

		return true;
	}

	bool GameObject::Render(HDC _hdc)
	{

		HBRUSH blue = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, blue);

		HPEN red = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(_hdc, red);
		SelectObject(_hdc, oldPen);

		Rectangle(_hdc,  m_fX,  m_fY, 100 + m_fX, 100 + m_fY);

		SelectObject(_hdc, oldBrush);
		DeleteObject(blue);
		DeleteObject(red);


		return true;
	}

	bool GameObject::Release()
	{
		return true;
	}

}