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
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(_type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(J::enums::eLayerType _type, math::Vector2 _pos)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(_type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(_pos);

		return gameObject;
	}

	//static void Destroy(GameObject* _obj)
	//{
	//	if (_obj == nullptr)
	//		return;

	//	_obj->Death();
	//}
}