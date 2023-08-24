#pragma once
#include <windows.h>
#include <string>
#include <vector>
#include <memory>
#include <wrl.h>

#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>			//D3DComplileFromFile
#include "DirectXMath.h"

#pragma comment (lib, "dxgi.lib") // d3d11.dll
#pragma comment (lib, "d3d11.lib") // d3d11.dll
#pragma comment (lib, "d3dcompiler.lib") // d3d11.dll
#pragma comment (lib, "DirectXTex.lib")

#define TGAME_START int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR    lpCmdLine, int       nCmdShow){ Sample win;
#define TGAME_REGISTER      win.SetRegisterClassWindow(hInstance);
#define TGAME_WINDOW(s,w,h) win.SetWindow(L#s, w, h);
#define TGAME_RUN win.Run();
#define TGAME_END return 0; };

#define TGAME(s,w,h) TGAME_START;TGAME_REGISTER;TGAME_WINDOW(s,w,h);TGAME_RUN;TGAME_END;

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

using Vec2 = DirectX::XMFLOAT2;
using Vec3 = DirectX::XMFLOAT3;
using Vec4 = DirectX::XMFLOAT4;
using Color = DirectX::XMFLOAT4;

using namespace DirectX;
using namespace Microsoft::WRL;