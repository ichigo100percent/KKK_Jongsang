#include "Component.h"

namespace J
{
	Component::Component(enums::EComponentType _type)
		: m_Type(_type)
		  /*m_Owner(nullptr)*/
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
}