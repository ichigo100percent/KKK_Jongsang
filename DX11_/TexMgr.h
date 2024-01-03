#pragma once
#include "Std.h"

class Texture
{
public:
	ComPtr<ID3D11ShaderResourceView> m_TexSRV = nullptr;

	wstring m_csName;
	wstring m_csPath;

	void Apply(ComPtr<ID3D11DeviceContext> _context, int _slot)
	{
		_context->PSSetShaderResources(_slot, 1, m_TexSRV.GetAddressOf());
	}

	bool Load(ComPtr<ID3D11Device> _device, wstring _fileName);
	bool Release();
};



class TextureMgr
{
public:
	ComPtr<ID3D11Device> m_Device = nullptr;
	ComPtr<ID3D11DeviceContext> m_Context = nullptr;
	using TextureList = map<wstring, shared_ptr<Texture>>;

	TextureList			m_TextureList;

public:
	static TextureMgr& Instance()
	{
		static TextureMgr mgr;

		return mgr;
	}

	void					Set(ComPtr<ID3D11Device> _device, ComPtr<ID3D11DeviceContext> _context);
	shared_ptr<Texture>		Load(wstring _fileName);
	shared_ptr<Texture>		GetPtr(wstring _key);
	bool					Get(wstring _key, Texture& ret);
	bool					Release();

public:
	TextureMgr() {};
	
	virtual ~TextureMgr()
	{
		Release();
	}
};