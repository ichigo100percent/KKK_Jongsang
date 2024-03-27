#pragma once
#include "Entity.h"

//순환참조 오류일어남
//#include "JSGameObject.h"

namespace J
{
	using namespace enums;

	class GameObject;
	class Component : public Entity
	{
	public:
		Component(enums::eComponentType _type);
		~Component();

		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);

		void SetOwner(GameObject* _owner) { m_Owner = _owner; }
		GameObject* GetOwner() { return m_Owner; }
		enums::eComponentType GetType() { return m_Type; }

	private:
		GameObject* m_Owner;
		enums::eComponentType m_Type;
	};
}
