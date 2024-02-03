//#pragma once
//#include "Scene.h"
//
//
//namespace J
//{
//	using SceneMap = std::map<std::wstring, Scene*>;
//	using SceneIter = std::map<std::wstring, Scene*>::iterator;
//
//	class SceneManager
//	{
//	public:
//		template<typename T>
//		static Scene* CreateScene(const std::wstring& _name)
//		{
//			T* scene = new T();
//			scene->SetName(_name);
//			scene->Init();
//
//			m_Scene.insert(make_pair(_name, scene));
//
//			return scene;
//
//		}
//
//		static Scene* LoadScene(const std::wstring& _name)
//		{
//			SceneIter iter = m_Scene.find(_name);
//
//			if (iter == m_Scene.end())
//				return nullptr;
//
//			m_ActiveScene = iter->second;
//
//			return iter->second;
//		}
//
//		static bool Init();
//		static bool Update();
//		static bool LateUpdate();
//		static bool Render(HDC _hdc);
//		static bool Release();
//
//	private:
//		static SceneMap				m_Scene;
//		static Scene*				m_ActiveScene;
//	};
//}
