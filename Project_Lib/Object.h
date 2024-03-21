#pragma once
#include "Component.h"
#include "JSGameObject.h"
#include "Layer.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Transform.h"

namespace J::object
{
	template <typename T>
	static T* Instantiate(J::enums::eLayerType _type)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(_type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(_type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(J::enums::eLayerType _type, math::Vector2 _pos)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(_type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(_type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(_pos);

		return gameObject;
	}

	static void DontDestroyOnLoad(GameObject* _gameObject)
	{
		Scene* activeScene = SceneManager::GetActiveScene();
		//현재 씬에서 게임오브젝트를 지워준다.
		activeScene->EraseGameObejct(_gameObject);

		//해당 게임오브젝트를 ->DontDestroy씬으로 넣어준다.
		Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(_gameObject, _gameObject->GetLayerType());
	}
}