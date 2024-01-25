#pragma once
#include "Entity.h"

namespace J
{
	class GameObject;

	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);
		virtual bool Release();

		void SetOwner(GameObject* _owner) { m_Owner = _owner; }
		GameObject* GetOwner() { return m_Owner; }

	private:
		GameObject* m_Owner;
	};
}
