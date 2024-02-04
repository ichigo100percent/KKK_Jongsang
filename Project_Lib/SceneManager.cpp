#include "SceneManager.h"


namespace J
{
	SceneMap SceneManager::m_Scene = {};
	Scene* SceneManager::m_ActiveScene = nullptr;

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

	bool SceneManager::Init()
	{

		return true;
	}

	bool SceneManager::Update()
	{
		m_ActiveScene->Update();
		return true;
	}

	bool SceneManager::LateUpdate()
	{
		m_ActiveScene->LateUpdate();
		return true;
	}

	bool SceneManager::Render(HDC _hdc)
	{
		m_ActiveScene->Render(_hdc);
		return true;
	}

	bool SceneManager::Release()
	{
		return true;
	}
}