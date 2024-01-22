#include "SceneManager.h"


namespace J
{
	SceneMap SceneManager::m_Scene = {};
	Scene* SceneManager::m_ActiveScene = nullptr;

	bool SceneManager::Init()
	{
		return true;
	}

	bool SceneManager::Frame()
	{
		m_ActiveScene->Frame();
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