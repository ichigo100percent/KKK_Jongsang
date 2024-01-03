#pragma once
#include "Std.h"
#include "ShaderMgr.h"
#include "TexMgr.h"

struct CB_Data
{
	Matrix matWorld;
	Matrix matView;
	Matrix matProj;
};

struct Vertex
{
	Vec3 p;
	Vec2 t;
};

class Object
{
public:
	ComPtr<ID3D11Device>				m_Device = nullptr;
	ComPtr<ID3D11DeviceContext>			m_Context = nullptr;

	ComPtr<ID3D11Buffer>				m_VertexBuffer = nullptr;
	//ComPtr<ID3D11Buffer>				m_IndexBuffer = nullptr;
	ComPtr<ID3D11Buffer>				m_ConstantBuffer = nullptr;
	ComPtr<ID3D11InputLayout>			m_InputLayout = nullptr;

	vector<Vertex>						m_VertexList;
	vector<uint32>						m_IndexList;
	CB_Data								m_cbData;

	shared_ptr<Texture>					m_Texture = nullptr;
	shared_ptr<Shader>					m_Shader = nullptr;

public:
	void								Set(ComPtr<ID3D11Device> _device, ComPtr<ID3D11DeviceContext> _context);
	virtual bool						CreateVertexBuffer();
	//virtual bool						CreateIndexBuffer();
	virtual bool						CreateConstantBuffer();
	virtual bool						CreateInputLayout();

public:
	virtual bool    Init();
	virtual bool    Frame();
	virtual bool    Render();
	virtual bool    Release();

public:
	virtual ~Object() {};
};

