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
    m_plmmediateContext = pImmediateContext;
}

bool        Object::LoadTextureFile(std::wstring filename)
{
    //DirectX::ScratchImage �̹��� �����͸� �ε��ϰ� ������ �� �ٸ� �������� �����ϰų� ���� �����ϴ�.
    auto imageobj = std::make_unique<DirectX::ScratchImage>();

    //�ؽ��� ��Ÿ�����͸� �����ϴ� ����ü
    DirectX::TexMetadata mdata;

    //�⺻�������� �ε�(DDS_FLAGS_NONE)
    HRESULT hr = DirectX::GetMetadataFromDDSFile(filename.c_str(), DirectX::DDS_FLAGS_NONE, mdata);

    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromDDSFile
    }
}