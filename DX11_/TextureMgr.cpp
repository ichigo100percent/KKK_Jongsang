//#include "TextureMgr.h"
//
////bool  Texture::Load(ComPtr<ID3D11Device> pd3dDevice,
////	ComPtr<ID3D11DeviceContext> pd3dContext,
////	std::wstring texFileName)
////{
////	m_texImage = std::make_unique<DirectX::ScratchImage>();
////	DirectX::TexMetadata metadata;
////
////
////
////	HRESULT hr = DirectX::GetMetadataFromWICFile(texFileName.c_str(), DirectX::WIC_FLAGS_NONE, metadata);
////	if (SUCCEEDED(hr))
////	{
////		hr = DirectX::LoadFromWICFile(texFileName.c_str(), DirectX::WIC_FLAGS_NONE, &metadata, *m_texImage);
////		if (SUCCEEDED(hr))
////		{
////			hr = DirectX::CreateShaderResourceView(pd3dDevice.Get(),
////				m_texImage->GetImages(), //_In_reads_(nimages) const Image * srcImages, 
////				m_texImage->GetImageCount(), // _In_ size_t nimages, 
////				metadata,// _In_ const TexMetadata & metadata,
////				m_pTextureSRV.GetAddressOf());//_Outptr_ ID3D11ShaderResourceView * *ppSRV
////
////			if (SUCCEEDED(hr))
////			{
////				return true;
////			}
////		}
////	}
////
////	//DDS 다이렉트SDK 전용 압축포맷
////	hr = DirectX::GetMetadataFromDDSFile(texFileName.c_str(), DirectX::DDS_FLAGS_NONE, metadata);
////	if (SUCCEEDED(hr))
////	{
////		hr = DirectX::LoadFromDDSFile(texFileName.c_str(), DirectX::DDS_FLAGS_NONE, &metadata, *m_texImage);
////		if (SUCCEEDED(hr))
////		{
////			hr = DirectX::CreateShaderResourceView(pd3dDevice.Get(),
////				m_texImage->GetImages(), //_In_reads_(nimages) const Image * srcImages, 
////				m_texImage->GetImageCount(), // _In_ size_t nimages, 
////				metadata,// _In_ const TexMetadata & metadata,
////				m_pTextureSRV.GetAddressOf());//_Outptr_ ID3D11ShaderResourceView * *ppSRV
////			if (SUCCEEDED(hr))
////			{
////				return true;
////			}
////		}
////	}
////	hr = DirectX::GetMetadataFromTGAFile(texFileName.c_str(), DirectX::TGA_FLAGS_NONE, metadata);
////	if (SUCCEEDED(hr))
////	{
////		hr = DirectX::LoadFromTGAFile(texFileName.c_str(), DirectX::TGA_FLAGS_NONE, &metadata, *m_texImage);
////		if (SUCCEEDED(hr))
////		{
////			hr = DirectX::CreateShaderResourceView(pd3dDevice.Get(),
////				m_texImage->GetImages(), //_In_reads_(nimages) const Image * srcImages, 
////				m_texImage->GetImageCount(), // _In_ size_t nimages, 
////				metadata,// _In_ const TexMetadata & metadata,
////				m_pTextureSRV.GetAddressOf());//_Outptr_ ID3D11ShaderResourceView * *ppSRV
////			if (SUCCEEDED(hr))
////			{
////				return true;
////			}
////		}
////	}
////
////	hr = DirectX::GetMetadataFromHDRFile(texFileName.c_str(), metadata);
////	if (SUCCEEDED(hr))
////	{
////		hr = DirectX::LoadFromHDRFile(texFileName.c_str(), &metadata, *m_texImage);
////		if (SUCCEEDED(hr))
////		{
////			hr = DirectX::CreateShaderResourceView(pd3dDevice.Get(),
////				m_texImage->GetImages(), //_In_reads_(nimages) const Image * srcImages, 
////				m_texImage->GetImageCount(), // _In_ size_t nimages, 
////				metadata,// _In_ const TexMetadata & metadata,
////				m_pTextureSRV.GetAddressOf());//_Outptr_ ID3D11ShaderResourceView * *ppSRV
////			if (SUCCEEDED(hr))
////			{
////				return true;
////			}
////		}
////	}
////	return false;
////
////}
//
//bool Texture::Load(ComPtr<ID3D11Device> pd3dDevice,
//	ComPtr<ID3D11DeviceContext> pd3dContext,
//	std::wstring texFileName)
//{
//	m_texImage = std::make_unique<DirectX::ScratchImage>();
//	DirectX::TexMetadata md;
//
//	HRESULT hr = ::LoadFromWICFile(texFileName.c_str(), WIC_FLAGS_NONE, &md, *m_texImage);
//	if (SUCCEEDED(hr))
//	{
//		hr = ::CreateShaderResourceView(pd3dDevice.Get(),
//			m_texImage->GetImages(),
//			m_texImage->GetImageCount(),
//			md,
//			m_pTextureSRV.GetAddressOf());
//		
//		if (SUCCEEDED(hr))
//		{
//			return true;
//		}
//	}
//
//	hr = DirectX::LoadFromDDSFile(texFileName.c_str(), DirectX::DDS_FLAGS_NONE, &md, *m_texImage);
//	if (SUCCEEDED(hr))
//	{
//		hr = DirectX::CreateShaderResourceView(pd3dDevice.Get(),
//			m_texImage->GetImages(),
//			m_texImage->GetImageCount(),
//			md,
//			m_pTextureSRV.GetAddressOf());
//		if (SUCCEEDED(hr))
//		{
//			return true;
//		}
//	}
//
//	hr = DirectX::LoadFromTGAFile(texFileName.c_str(), DirectX::TGA_FLAGS_NONE, &md, *m_texImage);
//	if (SUCCEEDED(hr))
//	{
//		hr = DirectX::CreateShaderResourceView(pd3dDevice.Get(),
//			m_texImage->GetImages(),
//			m_texImage->GetImageCount(),
//			md,
//			m_pTextureSRV.GetAddressOf());
//		if (SUCCEEDED(hr))
//		{
//			return true;
//		}
//	}
//
//	hr = DirectX::LoadFromHDRFile(texFileName.c_str(), &md, *m_texImage);
//	if (SUCCEEDED(hr))
//	{
//		hr = DirectX::CreateShaderResourceView(pd3dDevice.Get(),
//			m_texImage->GetImages(),
//			m_texImage->GetImageCount(),
//			md,
//			m_pTextureSRV.GetAddressOf());
//		if (SUCCEEDED(hr))
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//
//bool Texture::Release()
//{
//	return true;
//}
//
//
//bool TextureMgr::Release()
//{
//	for (auto data : m_list)
//	{
//		data.second->Release();
//	}
//	m_list.clear();
//	return true;
//}
//
//
//shared_ptr<Texture> TextureMgr::Load(std::wstring loadfilename)
//{
//	auto iter = m_list.find(loadfilename);
//	if (iter != m_list.end())
//	{
//		return iter->second;
//	}
//	std::shared_ptr<Texture>  pTex = std::make_shared<Texture>();
//	if (pTex->Load(m_pDevice, m_pContext, loadfilename))
//	{
//		m_list.insert(std::make_pair(loadfilename, pTex));
//		return pTex;
//	}
//	return nullptr;
//}
//
////Texture* TextureMgr::Load(std::wstring loadfilename)
////{
////	auto iter = m_list.find(loadfilename);
////	if (iter != m_list.end())
////	{
////		return iter->second.get();
////	}
////	std::shared_ptr<Texture>  pTex = std::make_shared<Texture>();
////	if (pTex->Load(m_pDevice, m_pContext, loadfilename))
////	{
////		m_list.insert(std::make_pair(loadfilename, pTex));
////		return pTex.get();
////	}
////	return nullptr;
////}

