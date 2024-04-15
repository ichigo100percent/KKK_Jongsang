#pragma once
#include "SceneManager.h"
#include "PlayScene.h"
#include "TitleScene.h"
#include "ToolScene.h"


#include "MarioPlayScene.h"


namespace J
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		//SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<ToolScene>(L"ToolScene");
		SceneManager::CreateScene<MarioPlayScene>(L"MarioPlayScene");

		SceneManager::LoadScene(L"TitleScene");
		//SceneManager::LoadScene(L"PlayScene");
		//SceneManager::LoadScene(L"ToolScene");


		//SceneManager::LoadScene(L"MarioPlayScene");
	}
}

