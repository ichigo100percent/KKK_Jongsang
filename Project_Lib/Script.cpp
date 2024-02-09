#include "Script.h"


namespace J
{
	Script::Script()
		: Component(enums::EComponentType::Script)
	{
	}
	Script::~Script()
	{
	}
	bool Script::Init()
	{
		return true;
	}
	bool Script::Update()
	{
		return true;
	}
	bool Script::LateUpdate()
	{
		return true;
	}
	bool Script::Render(HDC _hdc)
	{
		return true;
	}
	bool Script::Release()
	{
		return true;
	}
}