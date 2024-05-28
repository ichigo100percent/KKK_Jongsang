#include "framework.h"
#include "Js_ProjectEngine.h"


#include "Js_Core.h"

Js::Core core;

int WINAPI wWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PWSTR pCmdLine,
	int nCmdShow)
{
	Js::Core core;

	core.CreateRegisterClass(hInstance);

	if (core.InitInstance(g_Width, g_Height))
	{
		core.CreateDevice();
		core.Run();
		core.DeleteDeivce();
	}
	return 0;
}