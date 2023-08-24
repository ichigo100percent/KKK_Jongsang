#include "Object.h"
#include "DirectXTex.h"

bool		Object::Create(std::wstring texFilename)
{
    CreateVertexBuffer();
    LoadVertexShader();
    LoadPixelShader();
    CreateInputLayout();
    LoadTextureFile(texFilename);
    return true;
}

void        Object::Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext)
{
    m_pDevice = pDevice;
    m_pImmediateContext = pImmediateContext;
}

bool        Object::LoadTextureFile(std::wstring filename)
{
    //DirectX::ScratchImage 이미지 데이터를 로딩하고 조작한 후 다른 형식으로 저장하거나 전달 가능하다.
    auto imageobj = std::make_unique<DirectX::ScratchImage>();

    //텍스터 메타데이터를 저장하는 구조체
    DirectX::TexMetadata mdata;

    //기본설정으로 로딩(DDS_FLAGS_NONE)
    HRESULT hr = DirectX::GetMetadataFromDDSFile(filename.c_str(), DirectX::DDS_FLAGS_NONE, mdata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromDDSFile(filename.c_str(), DirectX::DDS_FLAGS_NONE, &mdata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(m_pDevice, imageobj->GetImages(), imageobj->GetImageCount(), mdata, &m_pTexSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }
    hr = DirectX::GetMetadataFromWICFile(filename.c_str(), DirectX::WIC_FLAGS_NONE, mdata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromWICFile(filename.c_str(), DirectX::WIC_FLAGS_NONE, &mdata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(m_pDevice, imageobj->GetImages(), imageobj->GetImageCount(), mdata, &m_pTexSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }
    hr = DirectX::GetMetadataFromTGAFile(filename.c_str(), DirectX::TGA_FLAGS_NONE, mdata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromTGAFile(filename.c_str(), DirectX::TGA_FLAGS_NONE, &mdata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(m_pDevice, imageobj->GetImages(), imageobj->GetImageCount(), mdata, &m_pTexSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }
    return false;
}

bool Object::CreateVertexBuffer()
{
    
    {
        _vertices.resize(4);

        _vertices[0].position = Vec3(-0.5f, -0.5f, 0.f);
        _vertices[0].uv = Vec2(0.f, 1.f);
        //_vertices[0].color = Color(1.f, 0.f, 0.f, 1.f);
        _vertices[1].position = Vec3(-0.5f, 0.5f, 0.f);
        _vertices[1].uv = Vec2(0.f, 0.f);
        //_vertices[1].color = Color(1.f, 0.f, 0.f, 1.f);
        _vertices[2].position = Vec3(0.5f, -0.5f, 0.f);
        _vertices[2].uv = Vec2(1.f, 1.f);
        //_vertices[2].color = Color(1.f, 0.f, 0.f, 1.f);
        _vertices[3].position = Vec3(0.5f, 0.5f, 0.f);
        _vertices[3].uv = Vec2(1.f, 0.f);
        //_vertices[3].color = Color(1.f, 0.f, 0.f, 1.f);
     
    }

    // VertexBuffer
    {
        D3D11_BUFFER_DESC desc;
        ZeroMemory(&desc, sizeof(desc));
        desc.Usage = D3D11_USAGE_IMMUTABLE;
        desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        desc.ByteWidth = (uint32)(sizeof(Vertex) * _vertices.size());

        D3D11_SUBRESOURCE_DATA data;
        ZeroMemory(&data, sizeof(data));
        data.pSysMem = _vertices.data();

        HRESULT hr = m_pDevice->CreateBuffer(&desc, &data, &m_pVertexBuffer);
        if (FAILED(hr))
        {
 
        }

        // Index
        {
            _indices = { 0, 1, 2, 2, 1, 3 };
        }

        // IndexBuffer
        {
            D3D11_BUFFER_DESC desc;
            ZeroMemory(&desc, sizeof(desc));
            desc.Usage = D3D11_USAGE_IMMUTABLE;
            desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
            desc.ByteWidth = (uint32)(sizeof(uint32) * _indices.size());

            D3D11_SUBRESOURCE_DATA data;
            ZeroMemory(&data, sizeof(data));
            data.pSysMem = _indices.data();

            HRESULT hr = m_pDevice->CreateBuffer(&desc, &data, &_indexBuffer);
            SUCCEEDED(hr);
        }

        return true;
    }
}

bool  Object::LoadVertexShader()
{
    ID3DBlob* ErrorCode;
    // 쉐이더 컴파일
    HRESULT hr = D3DCompileFromFile(
        L"Plane.hlsl",
        nullptr,
        nullptr,
        "VS",
        "vs_5_0",
        0,
        0,
        &m_VertexShaderCode,
        &ErrorCode);
    if (FAILED(hr))
    {

    }
    //ID3D11VertexShader* m_pVS
    hr = m_pDevice->CreateVertexShader(
        m_VertexShaderCode->GetBufferPointer(),
        m_VertexShaderCode->GetBufferSize(),
        nullptr,
        &m_pVS);

    if (ErrorCode) ErrorCode->Release();
    return true;
}
bool  Object::LoadPixelShader()
{
    ID3DBlob* ShaderCode;
    ID3DBlob* ErrorCode;
    // 쉐이더 컴파일
    HRESULT hr = D3DCompileFromFile(
        L"Plane.hlsl",
        nullptr,
        nullptr,
        "PS",
        "ps_5_0",
        0,
        0,
        &ShaderCode,
        &ErrorCode);
    if (FAILED(hr))
    {
        //ErrorCode
    }
    //ID3D11VertexShader* m_pVS
    hr = m_pDevice->CreatePixelShader(
        ShaderCode->GetBufferPointer(),
        ShaderCode->GetBufferSize(),
        nullptr,
        &m_pPS);

    if (ShaderCode) ShaderCode->Release();
    if (ErrorCode) ErrorCode->Release();
    return true;
}
bool  Object::CreateInputLayout()
{
    const D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POS",  0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEXTURE",  0, DXGI_FORMAT_R32G32_FLOAT, 0, 12,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    UINT iNumCount = sizeof(layout) / sizeof(layout[0]);
    HRESULT hr = m_pDevice->CreateInputLayout(
        layout,
        iNumCount,
        m_VertexShaderCode->GetBufferPointer(),
        m_VertexShaderCode->GetBufferSize(),
        &m_pVertexLayout);
    if (FAILED(hr))
    {
        return false;
    }
    return true;
}
bool  Object::Init()
{

    return true;
}
bool  Object::Frame()
{
    return true;
}
bool  Object::Render()
{
    m_pImmediateContext->PSSetShaderResources(0, 1, &m_pTexSRV);
    m_pImmediateContext->IASetInputLayout(m_pVertexLayout);
    m_pImmediateContext->IASetIndexBuffer(_indexBuffer, DXGI_FORMAT_R32_UINT, 0);
    m_pImmediateContext->VSSetShader(m_pVS, NULL, 0);
    m_pImmediateContext->PSSetShader(m_pPS, NULL, 0);
    UINT stride = sizeof(Vertex);
    UINT offset = 0;
    m_pImmediateContext->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);
    m_pImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    //m_pImmediateContext->Draw(_vertices.size(), 0);
    m_pImmediateContext->DrawIndexed(_indices.size(), 0, 0);
    return true;
}
bool  Object::Release()
{
    if (m_pTexSRV)m_pTexSRV->Release();
    if (m_pVertexBuffer) m_pVertexBuffer->Release();
    if (m_pVertexLayout) m_pVertexLayout->Release();
    if (m_pVS) m_pVS->Release();
    if (m_pPS) m_pPS->Release();
    return true;
}