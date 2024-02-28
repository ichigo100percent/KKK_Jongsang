#pragma once
#include "Std.h"
#include "Component.h"
//#include "Script.h"

namespace J::object
{
	void Destroy(GameObject* _gameObject);
}

namespace J
{
    class GameObject : public Entity
	{
	public:
		friend void object::Destroy(GameObject* _obj);

		enum class eState
		{
			Active,
			Paused,
			Dead,
			End,
		};

		GameObject();
		virtual ~GameObject();

	public:
		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);

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

		/*
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
		*/

		eState GetState() { return m_State; }
		void   SetActive(bool _power)
		{
			if (_power == true) m_State = eState::Active;
			if (_power == false) m_State = eState::Paused;
		}
		bool IsActive() { return m_State == eState::Active; }
		bool IsDead() { return m_State == eState::Dead; }
	
	private:
		void initializeTransform();
		void death() { m_State = eState::Dead; }

	private:
		eState					m_State;
		std::vector<Component*> m_Components;
		//std::vector<Script*>    m_Scripts;
	};
}

