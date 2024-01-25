#include "Component.h"

namespace J
{
	Component::Component()
		:m_Owner(nullptr)
	{
	}
	Component::~Component()
	{
	}

	bool Component::Init()
	{
		return true;
	}

	bool Component::Update()
	{
		return true;
	}

	bool Component::LateUpdate()
	{
		return true;
	}

	bool Component::Render(HDC _hdc)
	{
		return true;
	}

	bool Component::Release()
	{
		return true;
	}
}