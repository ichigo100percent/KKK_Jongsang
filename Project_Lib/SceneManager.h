#pragma once
#include "Scene.h"


namespace J
{
	using SceneMap = std::map<std::wstring, Scene*>;
	using SceneIter = std::map<std::wstring, Scene*>::iterator;

	class SceneManager
	{
	public:
		template<typename T>
		static Scene* CreateScene(const std::wstring& _name)
		{
			T* scene = new T();
			scene->SetName(_name);
			m_ActiveScene = scene;
			scene->Init();

			m_Scene.insert(make_pair(_name, scene));

			return scene;

		}

		static Scene* LoadScene(const std::wstring& _name);
		static Scene* GetActiveScene() { return m_ActiveScene; }


		static bool Init();
		static bool Update();
		static bool LateUpdate();
		static bool Render(HDC _hdc);
		static bool Release();

		static void Destroy();

	private:
		static SceneMap				m_Scene;
		static Scene*				m_ActiveScene;
	};
}
