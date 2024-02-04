#include "JSGameObject.h"
#include "Input.h"
#include "Time.h"
#include "Transform.h"

namespace J
{
	GameObject::GameObject()
		//: m_fX(0)
		//, m_fY(0)
	{
		initializeTransform();
	}
	GameObject::~GameObject()
	{
		for (auto comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			delete comp;
			comp = nullptr;
		}
	}

	bool GameObject::Init()
	{
		for (auto comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->Init();
		}
		return true;
	}

	bool GameObject::Update()
	{

		for (auto comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}

		return true;
	}

	bool GameObject::LateUpdate()
	{
		for (auto comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}

		return true;
	}

	bool GameObject::Render(HDC _hdc)
	{

		for (auto comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->Render(_hdc);
		}
		return true;
	}

	bool GameObject::Release()
	{
		for (auto comp : m_Components)
		{
			if (comp == nullptr)
				continue;

			comp->Release();
		}
		return true;
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}