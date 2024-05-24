#include "Js_Device.h"

int WINAPI wWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PWSTR pCmdLine,
	int nCmdShow)
{
	Js::Device device;

	device.CreateRegisterClass(hInstance);

	if (device.InitInstance(g_Width, g_Height))
	{
		device.CreateDevice();
		device.Run();		
		device.DeleteDeivce();
	}
	return 0;
}
