#include "Core.h"

bool Core::Init()
{
	return true;
}

bool Core::Update()
{
	return true;
}

bool Core::End()
{
	return true;
}

void Core::Run()
{
	Init();

	while (1)
	{
		Update();
	}
	End();
}