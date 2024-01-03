#pragma once
#include "TextureMgr.h"

struct Vertex
{
    Vec3 position;
    //Color color;
    Vec2 uv; //UV
};

class Object
{
public:

	W_STR							 m_csName;
	W_STR							 m_csDefaultVSFileName;
	W_STR							 m_csDefaultPSFileName;
	C_STR						     m_csDefaultVSEntryName;
	C_STR							 m_csDefaultPSEntryName;

	ComPtr<ID3D11Device>			m_pDevice = nullptr;
	ComPtr<ID3D11DeviceContext>		m_pContext = nullptr;


	RECT					    m_rtClient;
	//Texture*		  m_pTex = nullptr;
	//vector<Texture*>  m_pTexArray;
	shared_ptr<Texture>			m_pTex = nullptr;
	vector<shared_ptr<Texture>> m_pTexArray;

    // Geometry
    vector<Vertex>				_vertices;
    ComPtr<ID3D11Buffer>		_vertexBuffer = nullptr;
    vector<uint32>				_indices;
    ComPtr<ID3D11Buffer>		_indexBuffer = nullptr;
    ComPtr<ID3D11InputLayout>   _inputLayout = nullptr;

    // VS
    ComPtr<ID3D11VertexShader>	_vertexShader = nullptr;
    ComPtr<ID3DBlob>			_vsBlob = nullptr;

    // PS
    ComPtr<ID3D11PixelShader>   _pixelShader = nullptr;
    ComPtr<ID3DBlob>		    _psBlob = nullptr;
			
public:
	virtual void				Set(ComPtr<ID3D11Device>			_pDevice,
									ComPtr<ID3D11DeviceContext>		_pContext,
									RECT							_rtClient)
	{
		m_pDevice = _pDevice;
		m_pContext = _pContext;
		m_rtClient = _rtClient;
	}

	virtual bool				CreateVertexBuffer();
	virtual bool				CreateIndexBuffer();
	//ID3D11Buffer*	CreateBuffer(UINT ByteWidth, UINT BindFlags, void** pAddress);

	virtual bool				CreateVertexShader();
	virtual bool				CreatePixelShader();
	//ID3DBlob*		CreateShader(LPCWSTR pFileName, LPCSTR pEntrypoint, LPCSTR pTarget);
	virtual void				LoadShaderFromFile(const wstring& path, const string& name, const string& version, ComPtr<ID3DBlob>& blob);


	virtual bool				CreateInputLayout();

	virtual bool				LoadTexture(T_STR_VECTOR texFileName);
	virtual bool				LoadTexture(std::wstring texFileName);
public:
	virtual bool				Init();
	virtual bool				Create(W_STR name, T_STR_VECTOR texFileName);
	virtual bool				Create(W_STR name, W_STR texFileName);
	virtual bool				PreRender();
	virtual bool			    Frame();
	virtual bool				Render();
	virtual bool				PostRender();
	virtual bool			    Release();

public:
	Object() {}
	Object(ComPtr<ID3D11Device>			_pDevice,
		ComPtr<ID3D11DeviceContext>		_pContext,
		RECT							_rtClient)
	{
		m_pDevice  = _pDevice;
		m_pContext = _pContext;
		m_rtClient = _rtClient;
		_vertices.resize(4);
		Init();
	}
};

