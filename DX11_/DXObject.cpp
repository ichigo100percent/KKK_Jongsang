#include "DXObject.h"

void Object::Set(ComPtr<ID3D11Device> _device, ComPtr<ID3D11DeviceContext> _context)
{
	m_Device = _device;
	m_Context = _context;
}


bool	Object::CreateVertexBuffer()
{
	return true;
}

//bool	Object::CreateIndexBuffer()
//{
//    D3D11_BUFFER_DESC desc;
//    ZeroMemory(&desc, sizeof(desc));
//    desc.ByteWidth = (uint32)(sizeof(uint32) * m_IndexList.size());
//    desc.Usage = D3D11_USAGE_IMMUTABLE;
//    desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
//
//    D3D11_SUBRESOURCE_DATA data;
//    ZeroMemory(&data, sizeof(data));
//    data.pSysMem = m_IndexList.data();
//
//    HRESULT hr = m_Device->CreateBuffer(&desc, &data, m_IndexBuffer.GetAddressOf());
//
//    if (FAILED(hr))
//    {
//        return false;
//    }
//
//	return true;
//}

bool Object::CreateConstantBuffer()
{
    D3D11_BUFFER_DESC Desc;
    ZeroMemory(&Desc, sizeof(Desc));
    Desc.ByteWidth = sizeof(CB_Data);
    Desc.Usage = D3D11_USAGE_DEFAULT;
    Desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

    HRESULT hr = m_Device->CreateBuffer(&Desc, nullptr, &m_ConstantBuffer);

    if (FAILED(hr))
    {
        return false;
    }

	return true;
}

bool	Object::CreateInputLayout()
{
    D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    const int32 count = sizeof(layout) / sizeof(D3D11_INPUT_ELEMENT_DESC);

    HRESULT hr = m_Device->CreateInputLayout(
        layout,
        count,
        m_Shader->GetBufferPointer(),
        m_Shader->GetBufferSize(),
        m_InputLayout.GetAddressOf());

    if (FAILED(hr))
    {
        return false;
    }

    return true;
}


bool   Object::Init()
{
    return true;
}
bool   Object::Frame()
{
    return true;
}
bool   Object::Render()
{
    if (m_Shader != nullptr)
    {
        m_Shader->Apply(m_Context, 0);
    }

    if (m_Texture != nullptr)
    {
        m_Texture->Apply(m_Context, 0);
    }

    uint32 stride = sizeof(Vertex);
    uint32 offset = 0;

    m_Context->VSSetConstantBuffers(0, 1, m_ConstantBuffer.GetAddressOf());
    m_Context->IASetVertexBuffers(0, 1, m_VertexBuffer.GetAddressOf(), &stride, &offset);
    //m_Context->IASetIndexBuffer(m_IndexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);
    m_Context->IASetInputLayout(m_InputLayout.Get());
    m_Context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    m_Context->Draw(m_VertexList.size(), 0);
    //m_Context->DrawIndexed(m_IndexList.size(), 0, 0);

    return true;
}

bool   Object::Release()
{
    if (m_VertexBuffer) m_VertexBuffer->Release();
    //if (m_IndexBuffer)  m_IndexBuffer->Release();
    if (m_ConstantBuffer) m_ConstantBuffer->Release();
    if (m_InputLayout) m_InputLayout->Release();

    return true;
}