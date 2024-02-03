#pragma once
#include "Entity.h"
#include "Std.h"
#include "JSGameObject.h"

namespace J
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);
		virtual bool Release();

		void AddGameObject(GameObject* _gameObject);

	private:
		std::vector<GameObject*> m_GameObjects;
	};
}

