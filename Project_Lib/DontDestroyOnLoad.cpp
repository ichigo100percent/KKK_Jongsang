#include "DontDestroyOnLoad.h"


namespace J
{
	DontDestroyOnLoad::DontDestroyOnLoad()
	{
	}
	DontDestroyOnLoad::~DontDestroyOnLoad()
	{
	}
	bool DontDestroyOnLoad::Init()
	{
		Scene::Init();
		return true;
	}
	bool DontDestroyOnLoad::Update()
	{
		Scene::Update();
		return true;
	}
	bool DontDestroyOnLoad::LateUpdate()
	{
		Scene::LateUpdate();
		return true;
	}
	bool DontDestroyOnLoad::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
		return true;
	}
	void DontDestroyOnLoad::OnEnter()
	{
		Scene::OnEnter();
	}
	void DontDestroyOnLoad::OnExit()
	{
		Scene::OnExit();
	}
}