#include "Transform.h"

namespace J
{
	Transform::Transform()
		: Component(enums::EComponentType::Transform)
		, m_Scale(Vector2::One)
		, m_Rotation(0.0f)
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

}