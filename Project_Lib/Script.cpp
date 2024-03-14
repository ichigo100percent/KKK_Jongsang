#include "Script.h"
#include "Collider.h"

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
	void Script::OnCollisionEnter(Collider* _other)
	{
	}
	void Script::OnCollisionStay(Collider* _other)
	{
	}
	void Script::OnCollisionExit(Collider* _other)
	{
	}
}