#pragma once
#include "Entity.h"
#include "Std.h"
#include "JSGameObject.h"

namespace J
{
	using GameObjectIter = std::vector<GameObject*>::iterator;

	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* _gameObject);
		const std::vector<GameObject*> GetGameObjects() { return m_GameObjects; }

	private:
		void findDeadGameObjects(OUT std::vector<GameObject*>& _gameObjs);
		void deleteGameObjects(std::vector<GameObject*> _gameObjs);
		void eraseGameObject();

	private:
		std::vector<GameObject*> m_GameObjects;
	};
}

