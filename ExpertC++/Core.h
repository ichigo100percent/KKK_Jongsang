#pragma once
#include "std.h"

class Core
{
public:
	virtual bool Init();
	virtual bool Update();
	virtual bool End();
	void Run();
};

