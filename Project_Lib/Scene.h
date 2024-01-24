#pragma once
#include "Entity.h"
#include "JSGameObject.h"


namespace J
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);
		virtual bool Release();

		void AddGameObject(GameObject* _gameObject);

	private:
		vector<GameObject*> m_GameObjects;

	};

}
