#include "Layer.h"


namespace J
{
	Layer::Layer()
		: m_GameObjects{}
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
		for (GameObject* gameObj : m_GameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Init();
		}
		return true;
	}
	bool Layer::Update()
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			if (gameObj == nullptr)
				continue;
			if (gameObj->IsActive() == false)
				continue;

			gameObj->Update();
		}
		return true;
	}
	bool Layer::LateUpdate()
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			if (gameObj == nullptr)
				continue;
			if (gameObj->IsActive() == false)
				continue;

			gameObj->LateUpdate();
		}
		return true;
	}
	bool Layer::Render(HDC _hdc)
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			if (gameObj == nullptr)
				continue;
			if (gameObj->IsActive() == false)
				continue;

			gameObj->Render(_hdc);
		}
		return true;
	}
	void Layer::Destroy()
	{
		std::vector<GameObject*> deleteObjects = {};
		findDeadGameObjects(deleteObjects);
		eraseGameObject();
		deleteGameObjects(deleteObjects);
	}

	void Layer::AddGameObject(GameObject* _gameObject)
	{
		if (_gameObject == nullptr)
			return;

		m_GameObjects.push_back(_gameObject);
	}
	void Layer::findDeadGameObjects(OUT std::vector<GameObject*>& _gameObjs)
	{
		for (GameObject* gameObj : m_GameObjects)
		{
			GameObject::eState active = gameObj->GetState();
			if (active == GameObject::eState::Dead)
				_gameObjs.push_back(gameObj);
		}
	}

	void Layer::deleteGameObjects(std::vector<GameObject*> _gameObjs)
	{
		for (GameObject* obj : _gameObjs)
		{
			delete obj;
			obj = nullptr;
		}
	}

	void Layer::eraseGameObject()
	{
		std::erase_if(m_GameObjects,
			[](GameObject* gameObj)
			{
				return (gameObj)->IsDead();
			});
	}
}