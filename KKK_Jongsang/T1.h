#pragma once
#include <iostream>
using namespace std;

class T1
{
public:
	virtual bool Init();
	virtual bool Render();
	virtual bool Update();
	virtual bool Release();
	bool		 Run();

private:
	virtual bool  EngineInit();
	virtual bool  EngineFrame();
	virtual bool  EngineRender();
	virtual bool  EngineRelease();
};

