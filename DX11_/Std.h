#pragma once

//STL
#include <Windows.h>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <atlconv.h>

//DX
#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>
#include <DirectXMath.h>
#include "DirectXTex.h"
#include "DirectXTex.inl"
#include "SimpleMath.h"

#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")
#pragma comment (lib, "winmm.lib")

using namespace std;
using namespace DirectX;
using namespace Microsoft::WRL;


extern HWND		g_hWnd;
extern float	g_fSecPerFrame;
extern float	g_fMapHalfSizeX;
extern float	g_fMapHalfSizeY;

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

using Vec2 = DirectX::SimpleMath::Vector2;
using Vec3 = DirectX::SimpleMath::Vector3;
using Vec4 = DirectX::SimpleMath::Vector4;
using Color = DirectX::SimpleMath::Vector2;
using Matrix = DirectX::SimpleMath::Matrix;
using Quaternion = DirectX::SimpleMath::Quaternion;

typedef basic_string<TCHAR>				T_STR;
typedef basic_string<wchar_t>			W_STR;
typedef basic_string<char>				C_STR;
typedef vector<T_STR>					T_STR_VECTOR;
typedef basic_string<TCHAR>::iterator	T_ITOR;
typedef basic_string<wchar_t>::iterator	W_ITOR;
typedef basic_string<char>::iterator	C_ITOR;
typedef vector<T_STR>				T_ARRAY_ITOR;
typedef vector<DWORD>				DWORD_VECTOR;
typedef	vector< DWORD >::iterator	DWORD_VECTOR_ITOR;
typedef list<DWORD>					DWORD_LIST;
typedef list<DWORD>::iterator		DWORD_LIST_ITOR;
typedef list< HANDLE >				HANDLE_LIST;
typedef	list< HANDLE >::iterator	HANDLE_LIST_ITOR;

#define CHECK(p)	assert(SUCCEEDED(p))


#define GAME_START int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR    lpCmdLine, int       nCmdShow){ Game win;
#define GAME_REGISTER      win.SetRegisterClassWindow(hInstance);
#define GAME_WINDOW(s,w,h) win.SetWindow(L#s, w, h);
#define GAME_RUN win.Run();
#define GAME_END return 0; };

#define GAME(s,w,h) GAME_START; GAME_REGISTER; GAME_WINDOW(s,w,h); GAME_RUN; GAME_END;

