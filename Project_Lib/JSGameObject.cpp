#include "JSGameObject.h"
#include "Input.h"
#include "JSTime.h"
#include "Transform.h"

namespace J::object
{
	void Destroy(GameObject* _gameObject)
	{
		if (_gameObject != nullptr)
			_gameObject->death();
	}
}

namespace J
{
	GameObject::GameObject()
		: m_State(eState::Active)
		, m_LayerType(eLayerType::None)
	{
		m_Components.resize((UINT)enums::eComponentType::End);
		initializeTransform();
	}
	GameObject::~GameObject()
	{
		for (Component* comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			delete comp;
			comp = nullptr;
		}

		//for (auto scr : m_Scripts)
		//{
		//	if (scr == nullptr)
		//		continue;

		//	delete scr;
		//	scr = nullptr;
		//}
	}

	bool GameObject::Init()
	{
		for (Component* comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->Init();
		}

		//for (auto scr : m_Scripts)
		//{
		//	if (scr == nullptr)
		//		continue;

		//	scr->Init();
		//}
		return true;
	}

	bool GameObject::Update()
	{

		for (Component* comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}

		//for (auto scr : m_Scripts)
		//{
		//	if (scr == nullptr)
		//		continue;

		//	scr->Update();
		//}
		return true;
	}

	bool GameObject::LateUpdate()
	{
		for (Component* comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}

		//for (auto scr : m_Scripts)
		//{
		//	if (scr == nullptr)
		//		continue;

		//	scr->LateUpdate();
		//}

		return true;
	}

	bool GameObject::Render(HDC _hdc)
	{

		for (Component* comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->Render(_hdc);
		}

		//for (auto scr : m_Scripts)
		//{
		//	if (scr == nullptr)
		//		continue;

		//	scr->Render(_hdc);
		//}
		return true;
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}

