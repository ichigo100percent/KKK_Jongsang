#include "BlockScript.h"
#include "Input.h"
#include "Transform.h"
#include "JSTime.h"
#include "JSGameObject.h"
#include "Animator.h"
#include "Object.h"
#include "Rigidbody.h"
#include "MarioScript.h"

namespace J
{
	BlockScript::BlockScript()
	{
	}
	BlockScript::~BlockScript()
	{
	}
	bool BlockScript::Init()
	{
		return true;
	}
	bool BlockScript::Update()
	{
		return true;
	}
	bool BlockScript::LateUpdate()
	{
		return true;
	}
	bool BlockScript::Render(HDC _hdc)
	{
		return true;
	}
	void BlockScript::OnCollisionEnter(Collider* other)
	{
	}
	void BlockScript::OnCollisionStay(Collider* other)
	{
	}
	void BlockScript::OnCollisionExit(Collider* other)
	{
	}
}