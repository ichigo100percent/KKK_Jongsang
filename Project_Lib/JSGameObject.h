#pragma once
#include "Std.h"
#include "Component.h"
#include "Script.h"

namespace J
{
    class GameObject : public Entity
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
			//m_Components.push_back(comp);
			m_Components[(UINT)comp->GetType()] = comp;

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

		template<typename T>
		T* AddScript()
		{
			T* script = new T();
			script->Init();
			script->SetOwner(this);
			m_Scripts.push_back(script);
			//m_Components[(UINT)comp->GetType()] = comp;

			return script;
		}

	private:
		void initializeTransform();

	private:
		std::vector<Component*> m_Components;
		std::vector<Script*>    m_Scripts;
	};
}

