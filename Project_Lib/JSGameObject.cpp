#include "JSGameObject.h"
#include "Input.h"
#include "Time.h"

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
		const int speed = 150.0f;

		if (Input::Getkey(eKeyCode::A))
		{
			m_fX -= speed * Time::DeltaTime();
		}

		if (Input::Getkey(eKeyCode::D))
		{
			m_fX += speed * Time::DeltaTime();
		}

		if (Input::Getkey(eKeyCode::W))
		{
			m_fY -= speed * Time::DeltaTime();
		}

		if (Input::Getkey(eKeyCode::S))
		{
			m_fY += speed * Time::DeltaTime();
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