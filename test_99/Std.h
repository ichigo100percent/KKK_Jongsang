#pragma once

#define _XM_NO_INTRINSICS_


#include "Types.h"
#include "Values.h"
#include "Struct.h"

//WIN
#include <windows.h>
#include <assert.h>

//STL
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

// DX
#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>			//D3DComplileFromFile
#include <wrl.h>
#include <DirectXMath.h>
#include "DirectXTex.h"

using namespace DirectX;
using namespace Microsoft::WRL;
#pragma comment (lib, "dxgi.lib") // d3d11.dll
#pragma comment (lib,  "d3d11.lib") // d3d11.dll
#pragma comment (lib, "d3dcompiler.lib") // d3d11.dll
#pragma comment (lib, "DirectXTex.lib")

#define CHECK(p)	assert(SUCCEEDED(p))

#include "Graphics.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "InputLayout.h"
#include "Shader.h"
#include "ConstantBuffer.h"
#include "Texture.h"
#include "RasterizerState.h"
#include "SamplerState.h"
#include "BlendState.h"
#include "Pipeline.h"
//#include "Transform.h"
#include "Geometry.h"
//#include "VertexData.h"