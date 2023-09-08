#pragma once
#include "Types.h"
#include "Struct.h"

//STL
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//DX
#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>
#include <DirectXMath.h>
//#include <DirectXTex/DirectXTex.h>
//#include <DirectXTex/DirectXTex.inl>

using namespace DirectX;
using namespace Microsoft::WRL;

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#define CHECK(p)	assert(SUCCEEDED(p))


#define TGAME_START int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR    lpCmdLine, int       nCmdShow){ Sample win;
#define TGAME_REGISTER      win.SetRegisterClassWindow(hInstance);
#define TGAME_WINDOW(s,w,h) win.SetWindow(L#s, w, h);
#define TGAME_RUN win.Run();
#define TGAME_END return 0; };

#define TGAME(s,w,h) TGAME_START;TGAME_REGISTER;TGAME_WINDOW(s,w,h);TGAME_RUN;TGAME_END;