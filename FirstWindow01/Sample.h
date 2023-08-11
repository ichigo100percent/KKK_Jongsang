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
//	//���ؽ� ���� �� ���̾ƿ�
//	ID3D11Buffer*				m_pVertexBuffer = nullptr;
//	ID3D11InputLayout*			m_pVertexLayout = nullptr;
//	//���ؽ� �� �ȼ� ���̴�
//	ID3D11VertexShader*		    m_pVS = nullptr;
//	ID3D11PixelShader*			m_pPS = nullptr;
//
//	ID3DBlob*					m_VertexShaderCode;
//public:
//	//���� ���� ����
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
