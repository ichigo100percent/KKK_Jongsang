#include "TitleScene.h"
#include "SceneManager.h"
#include "PlayScene.h"
#include "Input.h"

namespace J
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	bool TitleScene::Init()
	{
		Scene::Init();
		return true;
	}
	bool TitleScene::Update()
	{
		Scene::Update();
		return true;
	}
	bool TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetkeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}

		return true;
	}
	bool TitleScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);

		std::wstring str = L"Title Scene";
		TextOut(_hdc, 0, 0, str.c_str(), str.length());

		return true;
	}
	//bool TitleScene::Release()
	//{
	//	Scene::Release();
	//	return true;
	//}
}
