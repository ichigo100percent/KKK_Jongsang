#include "SceneManager.h"
#include "DontDestroyOnLoad.h"

namespace J
{
	SceneMap SceneManager::m_Scene = {};
	Scene* SceneManager::m_ActiveScene = nullptr;
	Scene* SceneManager::m_DontDestroyOnLoad = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& _name)
	{
		if (m_ActiveScene)
			m_ActiveScene->OnExit();

		SceneIter iter = m_Scene.find(_name);

		if (iter == m_Scene.end())
			return nullptr;

		m_ActiveScene = iter->second;
		m_ActiveScene->OnEnter();

		return iter->second;
	}

	std::vector<GameObject*> SceneManager::GetGameObjects(eLayerType _layer)
	{
		std::vector<GameObject*> gameObejcts
			= m_ActiveScene->GetLayer(_layer)->GetGameObjects();
		std::vector<GameObject*> dontDestroyOnLoad
			= m_DontDestroyOnLoad->GetLayer(_layer)->GetGameObjects();

		gameObejcts.insert(gameObejcts.end()
			, dontDestroyOnLoad.begin()
			, dontDestroyOnLoad.end());

		return gameObejcts;
	}

	bool SceneManager::Init()
	{
		m_DontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
		return true;
	}

	bool SceneManager::Update()
	{
		m_ActiveScene->Update();
		m_DontDestroyOnLoad->Update();
		return true;
	}

	bool SceneManager::LateUpdate()
	{
		m_ActiveScene->LateUpdate();
		m_DontDestroyOnLoad->LateUpdate();
		return true;
	}

	bool SceneManager::Render(HDC _hdc)
	{
		m_ActiveScene->Render(_hdc);
		m_DontDestroyOnLoad->Render(_hdc);
		return true;
	}

	bool SceneManager::Release()
	{
		for (auto& iter : m_Scene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
		return true;
	}
	void SceneManager::Destroy()
	{
		m_ActiveScene->Destroy();
		m_DontDestroyOnLoad->Destroy();
	}
}