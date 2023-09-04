#include "TPlayer.h"
#include "TInput.h"

bool TPlayer::Frame()
{
    if (TInput::GetInstance().m_dwKeyState['A'] > KEY_UP)
    {
        m_vRotation.z = DegreeToRadian(90.f);
        m_vPos.x -= 500.0f * g_fSecondPerFrame;
    }
    if (TInput::GetInstance().m_dwKeyState['D'] > KEY_UP)
    {
        m_vRotation.z = DegreeToRadian(0.f);
        m_vPos.x += 500.0f * g_fSecondPerFrame;
    }
    if (TInput::GetInstance().m_dwKeyState['W'] > KEY_UP)
    {
       // m_vRotation.z = DegreeToRadian(90.f);
        m_vPos.y += 500.0f * g_fSecondPerFrame;
    }
    if (TInput::GetInstance().m_dwKeyState['S'] > KEY_UP)
    {
        //m_vRotation.z = DegreeToRadian(270.f);
        m_vPos.y -= 500.0f * g_fSecondPerFrame;
    }

    float fSizeHalfWidth = m_vScale.x;
    float fSizeHalfHeight = m_vScale.y;
    if (m_vPos.x < -g_fMapHalfSizeX + fSizeHalfWidth)
    {
        m_vPos.x = -g_fMapHalfSizeX + fSizeHalfWidth;
    }
    if (m_vPos.y < -g_fMapHalfSizeY + fSizeHalfHeight)
    {
        m_vPos.y = -g_fMapHalfSizeY + fSizeHalfHeight;
    }
    if (m_vPos.x > g_fMapHalfSizeX - fSizeHalfWidth)
    {
        m_vPos.x = g_fMapHalfSizeX - fSizeHalfWidth;
    }
    if (m_vPos.y > g_fMapHalfSizeY - fSizeHalfHeight)
    {
        m_vPos.y = g_fMapHalfSizeY - fSizeHalfHeight;
    }
    // 충돌데이터 업데이트( 회전 처리 미반영 )
    TVector2 rt = { m_vPos.x, m_vPos.y };
    SetRect(rt, m_vScale.x * 2.0f, m_vScale.y * 2.0f);

    TMatrix matScale, matRotation, matTranslate;
    matScale.Scale(m_vScale);
    //matRotation.ZRotate(m_vRotation.z);
    matRotation.XRotate(m_vRotation.x); // x 축 회전
    matRotation.YRotate(m_vRotation.y); // y 축 회전
    matRotation.ZRotate(m_vRotation.z); // z 축 회전
    matTranslate.Translation(m_vPos);
    m_matWorld = matScale * matRotation * matTranslate;
    return true;
}

bool TPlayer::CreateVertexBuffer()
{
    m_VertexList.resize(4);
    //24
    //13

    m_VertexList[0].p = TVector3(-1.f, -1.f, 0.f);
    m_VertexList[1].p = TVector3(-1.f, 1.f, 0.f);
    m_VertexList[2].p = TVector3(1.f, -1.f, 0.f);
    m_VertexList[3].p = TVector3(1.f, 1.f, 0.f);


    if (_bFlip) {
        m_VertexList[0].t = TVector2(1.f, 1.f);
        m_VertexList[1].t = TVector2(1.f, 0.f);
        m_VertexList[2].t = TVector2(0.f, 1.f);
        m_VertexList[3].t = TVector2(0.f, 0.f);
    }
    else {
        m_VertexList[0].t = TVector2(0.f, 1.f);
        m_VertexList[1].t = TVector2(0.f, 0.f);
        m_VertexList[2].t = TVector2(1.f, 1.f);
        m_VertexList[3].t = TVector2(1.f, 0.f);
    }

    //m_VertexList[3].color = Color(1.f, 0.f, 0.f, 1.f);
    {
        D3D11_BUFFER_DESC Desc;
        ZeroMemory(&Desc, sizeof(Desc));
        Desc.ByteWidth = sizeof(PT_Vertex) * m_VertexList.size();
        Desc.Usage = D3D11_USAGE_DEFAULT;
        Desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;


        D3D11_SUBRESOURCE_DATA InitialData;
        ZeroMemory(&InitialData, sizeof(InitialData));
        InitialData.pSysMem = &m_VertexList.at(0);

        HRESULT hr = m_pDevice->CreateBuffer(
            &Desc,
            &InitialData,
            &m_pVertexBuffer);
        if (FAILED(hr))
        {
            return false;
        }
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
        if (FAILED(hr))
        {
            return false;
        }
    }


    return true;

    return true;
}

bool TPlayer::Init()
{
    return true;
}
bool TPlayer::Render()
{
    TPlaneObj::Render();
    return true;
}
bool TPlayer::Release()
{
    return true;
}

