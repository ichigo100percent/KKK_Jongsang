#include "Object.h"

//void Object::SetGeometry(Vec3 pos, Vec2 uv)
//{
//    //_vertices.resize(4);
//
//    //_vertices[0] = { Vec3(0.f, 0.f, 0.f), Vec2(0.f, 0.f) };
//    //_vertices[1] = { Vec3(800.f, 0.f, 0.f), Vec2(1.f, 0.f) };
//    //_vertices[2] = { Vec3(800.f, 600.f, 0.f), Vec2(1.f, 1.f) };
//    //_vertices[3] = { Vec3(0.f, 600.f, 0.f), Vec2(0.f, 1.f) };
//
//    //_vertices[0] = { pos, uv };
//
//    //_indices.push_back(0);
//    //_indices.push_back(1);
//    //_indices.push_back(2);
//
//    //_indices.push_back(2);
//    //_indices.push_back(3);
//    //_indices.push_back(0);
//}

bool Object::CreateVertexBuffer()
{
    D3D11_BUFFER_DESC desc;
    ZeroMemory(&desc, sizeof(desc));
    desc.Usage = D3D11_USAGE_IMMUTABLE;
    desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    desc.ByteWidth = (uint32)(sizeof(Vertex) * _vertices.size());

    D3D11_SUBRESOURCE_DATA data;
    ZeroMemory(&data, sizeof(data));
    data.pSysMem = _vertices.data();

    HRESULT hr = m_pDevice->CreateBuffer(&desc, &data, _vertexBuffer.GetAddressOf());

    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

bool Object::CreateIndexBuffer()
{
    D3D11_BUFFER_DESC desc;
    ZeroMemory(&desc, sizeof(desc));
    desc.Usage = D3D11_USAGE_IMMUTABLE;
    desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    desc.ByteWidth = (uint32)(sizeof(uint32) * _indices.size());

    D3D11_SUBRESOURCE_DATA data;
    ZeroMemory(&data, sizeof(data));
    data.pSysMem = _indices.data();

    HRESULT hr = m_pDevice->CreateBuffer(&desc, &data, _indexBuffer.GetAddressOf());
    
    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

//ID3D11Buffer* Object::CreateBuffer(UINT ByteWidth, UINT BindFlags, void** pAddress)
//{
//    ComPtr<ID3D11Buffer> pBuffer = nullptr;
//    D3D11_BUFFER_DESC bd;
//    ZeroMemory(&bd, sizeof(D3D11_BUFFER_DESC));
//    bd.ByteWidth = ByteWidth; //  메모리 할당 크기
//    bd.Usage = D3D11_USAGE_DEFAULT;     // 버퍼의 저장소 및 접근권한 설정
//    bd.BindFlags = BindFlags; //  버퍼의 용도
//
//
//    D3D11_SUBRESOURCE_DATA sd;
//    ZeroMemory(&sd, sizeof(D3D11_SUBRESOURCE_DATA));
//    sd.pSysMem = pAddress;
//
//
//    HRESULT hr = m_pDevice->CreateBuffer(
//        &bd,
//        &sd,
//        pBuffer.GetAddressOf());
//    if (FAILED(hr))
//    {
//        return pBuffer.Get();
//    }
//    return pBuffer.Get();
//}

bool Object::CreateVertexShader()
{
    LoadShaderFromFile(m_csDefaultVSFileName, m_csDefaultVSEntryName, "vs_5_0", _vsBlob);
    HRESULT hr = m_pDevice->CreateVertexShader(_vsBlob->GetBufferPointer(), _vsBlob->GetBufferSize(),
        nullptr, _vertexShader.GetAddressOf());
    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

bool Object::CreatePixelShader()
{
    LoadShaderFromFile(m_csDefaultPSFileName, m_csDefaultPSEntryName, "ps_5_0", _psBlob);
    HRESULT hr = m_pDevice->CreatePixelShader(_psBlob->GetBufferPointer(),
        _psBlob->GetBufferSize(), nullptr, _pixelShader.GetAddressOf());
    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

void Object::LoadShaderFromFile(const wstring& path, const string& name, const string& version, ComPtr<ID3DBlob>& blob)
{
    HRESULT hr = ::D3DCompileFromFile(
        path.c_str(),
        nullptr,
        nullptr,
        name.c_str(),
        version.c_str(),
        0,
        0,
        blob.GetAddressOf(),
        nullptr);
}

//ID3DBlob* Object::CreateShader(LPCWSTR pFileName, LPCSTR pEntrypoint, LPCSTR pTarget)
//{
//    return nullptr;
//}

bool Object::CreateInputLayout()
{
    D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    const int32 count = sizeof(layout) / sizeof(D3D11_INPUT_ELEMENT_DESC);
    HRESULT hr = m_pDevice->CreateInputLayout(layout, count, _vsBlob->GetBufferPointer(), _vsBlob->GetBufferSize(), _inputLayout.GetAddressOf());
    
    if (FAILED(hr))
    {
        return false;
    }

    return true;
}

//bool Object::LoadTexture(T_STR_VECTOR texArray)
//{
//    for (int i = 0; i < texArray.size(); i++)
//    {
//        m_pTexArray.push_back(TextureMgr::Get().Load(texArray[i]));
//    }
//    m_pTex = m_pTexArray[0];
//    return true;
//}
//
//bool Object::LoadTexture(std::wstring texFileName)
//{
//    m_pTex = TextureMgr::Get().Load(texFileName);
//    if (m_pTex != nullptr)
//        return true;
//
//    return false;
//}

bool Object::LoadTexture(T_STR_VECTOR texArray)
{
    for (int i = 0; i < texArray.size(); i++)
    {
        m_pTexArray.push_back(TextureMgr::Get().Load(texArray[i]));
    }
    m_pTex = m_pTexArray[0];
    return true;
}

bool Object::LoadTexture(std::wstring texFileName)
{
    m_pTex = TextureMgr::Get().Load(texFileName);
    if (m_pTex != nullptr)
        return true;

    return false;
}

bool Object::Init()
{
    m_csDefaultVSFileName = L"../../data/shader/Default.hlsl";
    m_csDefaultPSFileName = L"../../data/shader/Default.hlsl";
    m_csDefaultVSEntryName = "VS";
    m_csDefaultPSEntryName = "PS";

    return true;
}

bool Object::Create(W_STR name, T_STR_VECTOR texFileName)
{
    m_csName = name;
    if (!texFileName.empty())
    {
        if (!LoadTexture(texFileName))
        {
            return false;
        }
    }

    _indices.push_back(0);
    _indices.push_back(1);
    _indices.push_back(2);

    _indices.push_back(2);
    _indices.push_back(3);
    _indices.push_back(0);

    if (!CreateVertexBuffer() || !CreateIndexBuffer())
    {
        return false;
    }
    if (!CreateVertexShader() || !CreatePixelShader())
    {
        return false;
    }

    if (!CreateInputLayout())
    {
        return false;
    }


    return true;
}

bool Object::Create(W_STR name, W_STR texFileName)
{
    m_csName = name;
    if (!texFileName.empty())
    {
        if (!LoadTexture(texFileName))
        {
            return false;
        }
    }
    //_vertices.resize(4);

    _indices.push_back(0);
    _indices.push_back(1);
    _indices.push_back(2);

    _indices.push_back(2);
    _indices.push_back(3);
    _indices.push_back(0);

    if (!CreateVertexBuffer() || !CreateIndexBuffer())
    {
        return false;
    }
    if (!CreateVertexShader() || !CreatePixelShader())
    {
        return false;
    }

    if (!CreateInputLayout())
    {
        return false;
    }


    return true;
}

bool Object::PreRender()
{
    uint32 stride = sizeof(Vertex);
    uint32 offset = 0;
    // IA
    m_pContext->IASetVertexBuffers(0, 1, _vertexBuffer.GetAddressOf(), &stride, &offset);
    m_pContext->IASetIndexBuffer(_indexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);
    m_pContext->IASetInputLayout(_inputLayout.Get());
    m_pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    // VS
    m_pContext->VSSetShader(_vertexShader.Get(), nullptr, 0);

    // PS
    m_pContext->PSSetShader(_pixelShader.Get(), nullptr, 0);
    m_pContext->PSSetShaderResources(0, 1, m_pTex->m_pTextureSRV.GetAddressOf());

    return true;
}

bool Object::Frame()
{
    return true;
}

bool Object::Render()
{
    PreRender();

    PostRender();

    return true;
}

bool Object::PostRender()
{
    m_pContext->DrawIndexed(_indices.size(), 0, 0);

    return true;
}

bool Object::Release()
{
    return true;
}
