#include "TexMgr.h"

bool Texture::Load(ComPtr<ID3D11Device> _device, wstring _fileName)
{
	auto m_texImage = std::make_unique<DirectX::ScratchImage>();
	DirectX::TexMetadata md;

	HRESULT hr = ::LoadFromWICFile(_fileName.c_str(), WIC_FLAGS_NONE, &md, *m_texImage);
	if (SUCCEEDED(hr))
	{
		hr = ::CreateShaderResourceView(_device.Get(),
			m_texImage->GetImages(),
			m_texImage->GetImageCount(),
			md,
			m_TexSRV.GetAddressOf());

		if (SUCCEEDED(hr))
		{
			return true;
		}
	}

	hr = DirectX::LoadFromDDSFile(_fileName.c_str(), DirectX::DDS_FLAGS_NONE, &md, *m_texImage);
	if (SUCCEEDED(hr))
	{
		hr = DirectX::CreateShaderResourceView(_device.Get(),
			m_texImage->GetImages(),
			m_texImage->GetImageCount(),
			md,
			m_TexSRV.GetAddressOf());
		if (SUCCEEDED(hr))
		{
			return true;
		}
	}

	hr = DirectX::LoadFromTGAFile(_fileName.c_str(), DirectX::TGA_FLAGS_NONE, &md, *m_texImage);
	if (SUCCEEDED(hr))
	{
		hr = DirectX::CreateShaderResourceView(_device.Get(),
			m_texImage->GetImages(),
			m_texImage->GetImageCount(),
			md,
			m_TexSRV.GetAddressOf());
		if (SUCCEEDED(hr))
		{
			return true;
		}
	}

	hr = DirectX::LoadFromHDRFile(_fileName.c_str(), &md, *m_texImage);
	if (SUCCEEDED(hr))
	{
		hr = DirectX::CreateShaderResourceView(_device.Get(),
			m_texImage->GetImages(),
			m_texImage->GetImageCount(),
			md,
			m_TexSRV.GetAddressOf());
		if (SUCCEEDED(hr))
		{
			return true;
		}
	}

	return false;
}

bool Texture::Release()
{
	if (m_TexSRV)
		m_TexSRV->Release();

	m_TexSRV = nullptr;

	return true;
}

void				TextureMgr::Set(ComPtr<ID3D11Device> _device, ComPtr<ID3D11DeviceContext> _context)
{
	m_Device = _device;
	m_Context = _context;
}
shared_ptr<Texture>	TextureMgr::Load(wstring _fileName)
{
	size_t found = _fileName.find_last_of(L"/");
	wstring path = _fileName.substr(0, found + 1);
	wstring key = _fileName.substr(found + 1);

	shared_ptr<Texture> data = GetPtr(key);

	if (data != nullptr)
	{
		return data;
	}
	shared_ptr<Texture> newData = make_shared<Texture>();
	if (newData->Load(m_Device, _fileName)) //key
	{
		m_TextureList.insert(make_pair(key, newData));
		return newData;
	}

	newData.reset();
	return nullptr;
}
shared_ptr<Texture> TextureMgr::GetPtr(wstring _key)
{
	auto iter = m_TextureList.find(_key);

	if (iter == m_TextureList.end())
	{
		return nullptr;
	}

	return iter->second;
}
bool				TextureMgr::Get(wstring _key, Texture& ret)
{
	auto iter = m_TextureList.find(_key);

	if (iter == m_TextureList.end())
	{
		return false;
	}

	ret = *(iter->second);

	return true;
}
bool				TextureMgr::Release()
{
	for (auto& data : m_TextureList)
	{
		data.second->Release();
		data.second.reset();
	}
	m_TextureList.clear();

	return true;
}

