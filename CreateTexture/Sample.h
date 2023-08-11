//#pragma once
//#include "Core.h"
//
//struct P3VERTEX
//{
//	float fx; float fy; float fz;
//};
//
//class Sample: public Core
//{
//	//버텍스 버퍼 및 레이아웃
//	ID3D11Buffer*				m_pVertexBuffer = nullptr;
//	ID3D11InputLayout*			m_pVertexLayout = nullptr;
//	//버텍스 및 픽셀 쉐이더
//	ID3D11VertexShader*		    m_pVS = nullptr;
//	ID3D11PixelShader*			m_pPS = nullptr;
//
//	ID3DBlob*					m_VertexShaderCode;
//public:
//	//정점 버퍼 생성
//	bool						CreateVertexBuffer();
//	bool						LoadVertexShader();
//	bool						LoadPixelShader();
//	bool						CreateInputLayout();
//
//public:
//	bool						Init();
//	bool						Frame();
//	bool						Render();
//	bool						Release();
//
//};

#pragma once
#include "Core.h"

struct P_Vertex
{
    float x, y, z;
};

class Sample : public Core
{
public:
    ID3D11Buffer* m_pVertexBuffer = nullptr;
    ID3DBlob* m_VertexShaderCode;
    ID3D11InputLayout* m_pVertexLayout = nullptr;
    ID3D11VertexShader* m_pVS = nullptr;
    ID3D11PixelShader* m_pPS = nullptr;
public:
    bool CreateVertexBuffer();
    //bool LoadShaderAndInputLayout();
    bool  LoadVertexShader();
    bool  LoadPixelShader();
    bool  CreateInputLayout();
public:
    bool  Init();
    bool  Frame();
    bool  Render();
    bool  Release();
};
