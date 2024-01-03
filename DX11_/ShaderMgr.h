#pragma once
#include "Std.h"


class Shader
{
public:
	ComPtr<ID3D11VertexShader>	m_VS = nullptr;
	ComPtr<ID3DBlob>			m_vsBlob = nullptr;

	ComPtr<ID3D11PixelShader>	m_PS = nullptr;
	ComPtr<ID3DBlob>		    m_psBlob = nullptr;

	wstring						m_csName;
	wstring						m_csPath;
public:

	LPVOID GetBufferPointer(void) const
	{
		return m_vsBlob->GetBufferPointer();
	};
	SIZE_T GetBufferSize(void) const
	{
		return m_vsBlob->GetBufferSize();
	};

	void Apply(ComPtr<ID3D11DeviceContext> _context, int _slot)
	{
		_context->VSSetShader(m_VS.Get(), nullptr, 0);
		_context->PSSetShader(m_PS.Get(), nullptr, 0);
	}

	bool Load(ComPtr<ID3D11Device> _device, wstring _fileName);
	bool LoadVertexShader(ComPtr<ID3D11Device> _device, wstring _fileName);
	bool LoadPixelShader(ComPtr<ID3D11Device> _device, wstring _fileName);
	bool Release();
};

class ShaderMgr
{
public:
	ComPtr<ID3D11Device>			m_Device = nullptr;
	ComPtr<ID3D11DeviceContext>		m_Context = nullptr;

	using ShaderList = map<wstring, shared_ptr<Shader>>;

	ShaderList						m_ShaderList;
public:
	static ShaderMgr& Instance()
	{
		static ShaderMgr mgr;
		return mgr;
	}

	void Set(ComPtr<ID3D11Device> _device, ComPtr<ID3D11DeviceContext> _context);
	shared_ptr<Shader> Load(wstring _fileName);
	shared_ptr<Shader> GetPtr(wstring _key);
	bool			   Get(wstring _key, Shader& ret);
	bool			   Release();

public:
	ShaderMgr();

	virtual ~ShaderMgr();
};