#pragma once
#include "Entity.h"

//순환참조 오류일어남
//#include "JSGameObject.h"

namespace J
{
	class GameObject;

	class Component : public Entity
	{
	public:
		Component(enums::EComponentType _type);
		~Component();

		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);
		virtual bool Release();

		void SetOwner(GameObject* _owner) { m_Owner = _owner; }
		GameObject* GetOwner() { return m_Owner; }
		enums::EComponentType GetType() { return m_Type; }

	private:
		GameObject* m_Owner;
		enums::EComponentType m_Type;
	};
}
