#include "Transform.h"
#include "Time.h"
#include "Input.h"

namespace J
{
	Transform::Transform()
		//:m_fX(0)
		//,m_fY(0)
	{

	}

	Transform::~Transform()
	{

	}

	bool Transform::Init()
	{
		return true;
	}

	bool Transform::Update()
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


		return true;
	}

	bool Transform::LateUpdate()
	{
		return true;
	}

	bool Transform::Render(HDC _hdc)
	{
		return true;
	}

	bool Transform::Release()
	{
		return true;
	}
}