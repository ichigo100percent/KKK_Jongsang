#include "Collider.h"
#include "JSGameObject.h"
#include "Script.h"

namespace J
{
	UINT Collider::CollisionID = 1;

	Collider::Collider(eColliderType _type)
		: Component(enums::EComponentType::Collider)
		, m_Type(_type)
		, m_ID(CollisionID++)
		, m_Size(Vector2::One)
	{
	}
	Collider::~Collider()
	{
	}
	bool Collider::Init()
	{
		return true;
	}
	bool Collider::Update()
	{
		return true;
	}
	bool Collider::LateUpdate()
	{
		return true;
	}
	bool Collider::Render(HDC _hdc)
	{
		return true;
	}
	void Collider::OnCollisionEnter(Collider* _other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionEnter(_other);
	}
	void Collider::OnCollisionStay(Collider* _other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionStay(_other);
	}
	void Collider::OnCollisionExit(Collider* _other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionExit(_other);
	}
}