#include "T1.h"

bool T1::Init()
{
	cout << "Init" << endl;
	return true;
}

bool T1::Render()
{
	cout << "Render" << endl;
	return true;
}

bool T1::Update()
{
	cout << "Update" << endl;
	return true;
}

bool T1::Release()
{
	cout << "Release" << endl;
	return true;
}

bool T1::Run()
{
	EngineInit();
	while (1)
	{
		EngineFrame();
		EngineRender();
	}
	EngineRelease();
	return true;
}

bool T1::EngineInit()
{
	Init();
	return true;
}

bool T1::EngineFrame()
{
	Update();
	return true;
}

bool T1::EngineRender()
{
	Render();
	return true;
}

bool T1::EngineRelease()
{
	Release();
	return true;
}
