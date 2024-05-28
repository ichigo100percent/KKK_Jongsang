#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <assert.h>


#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>
#include "SimpleMath.h"
#include "DirectXTex.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

const int g_Width = 800;
const int g_Height = 600;

using namespace Microsoft::WRL;

#define CHECK(p)	assert(SUCCEEDED(p))


