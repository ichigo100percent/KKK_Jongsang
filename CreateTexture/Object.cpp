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
    //DirectX::ScratchImage 이미지 데이터를 로딩하고 조작한 후 다른 형식으로 저장하거나 전달 가능하다.
    auto imageobj = std::make_unique<DirectX::ScratchImage>();

    //텍스터 메타데이터를 저장하는 구조체
    DirectX::TexMetadata mdata;

    //기본설정으로 로딩(DDS_FLAGS_NONE)
    HRESULT hr = DirectX::GetMetadataFromDDSFile(filename.c_str(), DirectX::DDS_FLAGS_NONE, mdata);

    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromDDSFile
    }
}