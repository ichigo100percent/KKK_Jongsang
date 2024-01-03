#pragma once
//#include "Std.h"


//class Texture
//{
//public:
//	Texture() {}
//	~Texture() {}
//
//public:
//	unique_ptr<ScratchImage> m_texImage = nullptr;
//	ComPtr<ID3D11ShaderResourceView> m_pTextureSRV = nullptr;
//
//public:
//	bool Load(ComPtr<ID3D11Device> pd3dDevice,
//		ComPtr<ID3D11DeviceContext> pd3dContext,
//		std::wstring texFileName);
//	bool Release();
//
//};
//
//class TextureMgr
//{
//public:
//	ComPtr<ID3D11Device> m_pDevice = nullptr;
//	ComPtr<ID3D11DeviceContext> m_pContext = nullptr;
//
//public:
//	static TextureMgr& Get()
//	{
//		static TextureMgr mgr;
//		return mgr;
//	}
//	std::map<std::wstring, std::shared_ptr<Texture>> m_list;
//	shared_ptr<Texture> Load(std::wstring loadfilename);
//
//	//Texture* Load(std::wstring loadfilename);
//	bool   Release();
//	void  Set(ComPtr<ID3D11Device> pd3dDevice,
//		      ComPtr<ID3D11DeviceContext> pd3dContext)
//	{
//		m_pDevice = pd3dDevice;
//		m_pContext = pd3dContext;
//	}
//private:
//	TextureMgr() {}
//public:
//	~TextureMgr() {}
//};
//
//
