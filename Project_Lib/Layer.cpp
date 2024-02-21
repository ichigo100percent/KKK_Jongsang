#include "Layer.h"


namespace J
{
	Layer::Layer()
		:m_GameObjects{}
	{

	}
	Layer::~Layer()
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			if (gameObj == nullptr)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
	}
	bool Layer::Init()
	{
		for (auto gameObj : m_GameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Init();
		}
		return true;
	}
	bool Layer::Update()
	{
		for (auto gameObj : m_GameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Update();
		}
		return true;
	}
	bool Layer::LateUpdate()
	{
		for (auto gameObj : m_GameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->LateUpdate();
		}
		return true;
	}
	bool Layer::Render(HDC _hdc)
	{
		for (auto gameObj : m_GameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render(_hdc);
		}
		return true;
	}
	bool Layer::Release()
	{
		for (auto gameObj : m_GameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Release();
		}
		return true;
	}
	void Layer::AddGameObject(GameObject* _gameObject)
	{
		if (_gameObject == nullptr)
			return;

		m_GameObjects.push_back(_gameObject);
	}
}