#include "SceneManager.h"


namespace J
{
	SceneMap SceneManager::m_Scene = {};
	Scene* SceneManager::m_ActiveScene = nullptr;

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