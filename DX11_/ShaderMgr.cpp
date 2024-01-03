#include "ShaderMgr.h"

bool Shader::Load(ComPtr<ID3D11Device> _device, wstring _fileName)
{
    if (LoadVertexShader(_device, _fileName) == false)
    {
        return false;
    }
    if (LoadPixelShader(_device, _fileName) == false)
    {
        return false;
    }
    
    return true;
}

bool Shader::LoadVertexShader(ComPtr<ID3D11Device> _device, wstring _fileName)
{
    HRESULT hr = ::D3DCompileFromFile(
        _fileName.c_str(),
        nullptr,
        nullptr,
        "VS",
        "vs_5_0",
        0,
        0,
        m_vsBlob.GetAddressOf(),
        nullptr);

    if (FAILED(hr))
    {
        return false;
    }

    hr = _device->CreateVertexShader(
        m_vsBlob->GetBufferPointer(),
        m_vsBlob->GetBufferSize(),
        nullptr,
        m_VS.GetAddressOf());

    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

bool Shader::LoadPixelShader(ComPtr<ID3D11Device> _device, wstring _fileName)
{
    HRESULT hr = ::D3DCompileFromFile(
        _fileName.c_str(),
        nullptr,
        nullptr,
        "PS",
        "ps_5_0",
        0,
        0,
        m_psBlob.GetAddressOf(),
        nullptr);

    if (FAILED(hr))
    {
        return false;
    }

    hr = _device->CreatePixelShader(
        m_psBlob->GetBufferPointer(),
        m_psBlob->GetBufferSize(),
        nullptr,
        m_PS.GetAddressOf());

    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

bool Shader::Release()
{
    if (m_vsBlob) m_vsBlob->Release();
    if (m_psBlob) m_psBlob->Release();
    if (m_VS) m_VS->Release();
    if (m_PS) m_PS->Release();
    return true;
}





void ShaderMgr::Set(ComPtr<ID3D11Device> _device, ComPtr<ID3D11DeviceContext> _context)
{
    m_Device  = _device;
    m_Context = _context;
}

shared_ptr<Shader> ShaderMgr::Load(wstring _fileName)
{
    size_t found = _fileName.find_last_of(L"/");
    wstring path = _fileName.substr(0, found + 1);
    wstring key = _fileName.substr(found + 1);

    shared_ptr<Shader> data = GetPtr(key);
    if (data != nullptr)
    {
        return data;
    }
    shared_ptr<Shader> newData = make_shared<Shader>();
    if (newData->Load(m_Device, _fileName)) //key
    {
        m_ShaderList.insert(make_pair(key, newData));
        return newData;
    }

    newData.reset();
    return nullptr;
}

shared_ptr<Shader> ShaderMgr::GetPtr(wstring _key)
{
    auto iter = m_ShaderList.find(_key);

    if (iter == m_ShaderList.end())
    {
        return nullptr;
    }

    return iter->second;
}

bool ShaderMgr::Get(wstring _key, Shader& ret)
{
    auto iter = m_ShaderList.find(_key);

    if (iter == m_ShaderList.end())
    {
        return false;
    }

    ret = *(iter->second);

    return true;
}

bool ShaderMgr::Release()
{
    for (auto& data : m_ShaderList)
    {
        data.second->Release();
        data.second.reset();
    }
    m_ShaderList.clear();

    return true;
}

ShaderMgr::ShaderMgr()
{
}

ShaderMgr::~ShaderMgr()
{
    Release();
}
