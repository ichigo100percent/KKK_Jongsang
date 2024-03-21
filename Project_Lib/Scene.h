#pragma once
#include "Entity.h"
#include "JSGameObject.h"
#include "Layer.h"

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
		
		virtual void Destroy();
		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* _gameObject, const enums::eLayerType _type);
		void EraseGameObejct(GameObject* _gameObject);
		Layer* GetLayer(const enums::eLayerType _type) { return m_Layers[(UINT)_type]; }

	private:
		void createLayers();

	private:
		//std::vector<GameObject*> m_GameObjects;
		std::vector<Layer*> m_Layers;
	};

}

