#pragma once
#include "Std.h"
#include "Component.h"

namespace J
{
    class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();

	public:
		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);
		virtual bool Release();

		template<typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Init();
			comp->SetOwner(this);
			m_Components.push_back(comp);

			return comp;
		}

		template<typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (auto comp : m_Components)
			{
				component = dynamic_cast<T*>(comp);

				if (component)
					break;
			}

			return component;
		}

		//void SetPosition(float _x, float _y)
		//{
		//	m_fX = _x;
		//	m_fY = _y;
		//}

		//float GetX() const { return m_fX; }
		//float GetY() const { return m_fY; }

	private:
		std::vector<Component*> m_Components;
		//float m_fX;
		//float m_fY;
	};
}

