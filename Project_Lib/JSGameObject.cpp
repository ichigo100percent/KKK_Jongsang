#include "JSGameObject.h"
#include "Input.h"
#include "JSTime.h"
#include "Transform.h"

namespace J
{
	GameObject::GameObject()
		: m_Scripts{}
	{
		m_Components.resize((UINT)enums::EComponentType::End);
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

		for (auto scr : m_Scripts)
		{
			if (scr == nullptr)
				continue;

			scr->Init();
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

		for (auto scr : m_Scripts)
		{
			if (scr == nullptr)
				continue;

			scr->Update();
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

		for (auto scr : m_Scripts)
		{
			if (scr == nullptr)
				continue;

			scr->LateUpdate();
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

		for (auto scr : m_Scripts)
		{
			if (scr == nullptr)
				continue;

			scr->Render(_hdc);
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

		for (auto scr : m_Scripts)
		{
			if (scr == nullptr)
				continue;

			scr->Release();
		}
		return true;
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}