#pragma once
#include "SceneManager.h"
#include "PlayScene.h"
#include "TitleScene.h"

namespace J
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<PlayScene>(L"JSPlayScene");

		//SceneManager::LoadScene(L"TitleScene");
		//SceneManager::LoadScene(L"PlayScene");
		SceneManager::LoadScene(L"JSPlayScene");
	}
}