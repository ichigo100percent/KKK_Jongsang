#include "JSGameObject.h"
#include "Input.h"
#include "Time.h"

namespace J
{
	GameObject::GameObject()
		//: m_fX(0)
		//, m_fY(0)
	{

	}
	GameObject::~GameObject()
	{
		for (auto comp : m_Components)
		{
			delete comp;
			comp = nullptr;
		}
	}

	bool GameObject::Init()
	{
		for (auto comp : m_Components)
		{
			comp->Init();
		}
		return true;
	}

	bool GameObject::Update()
	{

		//const int speed = 150.0f;

		//if (Input::Getkey(eKeyCode::A))
		//{
		//	m_fX -= speed * Time::DeltaTime();
		//}

		//if (Input::Getkey(eKeyCode::D))
		//{
		//	m_fX += speed * Time::DeltaTime();
		//}

		//if (Input::Getkey(eKeyCode::W))
		//{
		//	m_fY -= speed * Time::DeltaTime();
		//}

		//if (Input::Getkey(eKeyCode::S))
		//{
		//	m_fY += speed * Time::DeltaTime();
		//}

		for (auto comp : m_Components)
		{
			comp->Update();
		}

		return true;
	}

	bool GameObject::LateUpdate()
	{
		for (auto comp : m_Components)
		{
			comp->LateUpdate();
		}

		return true;
	}

	bool GameObject::Render(HDC _hdc)
	{

		//HBRUSH blue = CreateSolidBrush(RGB(0, 0, 255));
		//HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, blue);

		//HPEN red = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(_hdc, red);
		//SelectObject(_hdc, oldPen);

		//Rectangle(_hdc,  m_fX,  m_fY, 100 + m_fX, 100 + m_fY);

		//SelectObject(_hdc, oldBrush);
		//DeleteObject(blue);
		//DeleteObject(red);

		for (auto comp : m_Components)
		{
			comp->Render(_hdc);
		}
		return true;
	}

	bool GameObject::Release()
	{
		for (auto comp : m_Components)
		{
			comp->Release();
		}
		return true;
	}

}