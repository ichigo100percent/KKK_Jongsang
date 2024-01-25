#include "Transform.h"


namespace J
{
	Transform::Transform()
		:m_fX(0)
		,m_fY(0)
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