#include "TPlaneObj.h"
bool  TPlaneObj::CreateVertexBuffer()
{
    /*m_VertexList.resize(6);
    m_VertexList[0].t.x = 0.0f; m_VertexList[0].t.y = 0.0f;
    m_VertexList[1].t.x = 1.0f; m_VertexList[1].t.y = 0.0f;
    m_VertexList[2].t.x = 0.0f; m_VertexList[2].t.y = 1.0f;
    m_VertexList[3].t.x = 0.0f; m_VertexList[3].t.y = 1.0f;
    m_VertexList[4].t.x = 1.0f; m_VertexList[4].t.y = 0.0f;
    m_VertexList[5].t.x = 1.0f; m_VertexList[5].t.y = 1.0f;

    m_VertexList[0].p.x = -1.0f; m_VertexList[0].p.y = 1.0f;  m_VertexList[0].p.z = 0.0f;
    m_VertexList[1].p.x = 1.0f; m_VertexList[1].p.y = 1.0f;  m_VertexList[1].p.z = 0.0f;
    m_VertexList[2].p.x = -1.0f; m_VertexList[2].p.y = -1.0f;  m_VertexList[2].p.z = 0.0f;
    m_VertexList[3] = m_VertexList[2];
    m_VertexList[4] = m_VertexList[1];
    m_VertexList[5].p.x = 1.0f; m_VertexList[5].p.y = -1.0f;  m_VertexList[5].p.z = 0.0f;*/

    //_vertices.resize(4);
    m_VertexList.resize(4);
    //24
    //13
   // _vertices[0].uv = flip ? Vec2(1.f, 1.f) : Vec2(0.f, 1.f);
   // _vertices[1].uv = flip ? Vec2(1.f, 0.f) : Vec2(0.f, 0.f);
   m_VertexList[0].p = TVector3(-1.f, -1.f, 0.f);
   m_VertexList[0].t = TVector2(1.f, 1.f);
    //_vertices[0].color = Color(1.f, 0.f, 0.f, 1.f);
   m_VertexList[1].p = TVector3(-1.f, 1.f, 0.f);
   m_VertexList[1].t = TVector2(1.f, 0.f);
    //_vertices[1].color = Color(1.f, 0.f, 0.f, 1.f);
   m_VertexList[2].p = TVector3(1.f, -1.f, 0.f);
   m_VertexList[2].t = TVector2(0.f, 1.f);
    //_vertices[2].color = Color(1.f, 0.f, 0.f, 1.f);
   m_VertexList[3].p = TVector3(1.f, 1.f, 0.f);
   m_VertexList[3].t = TVector2(0.f, 0.f);
    //_vertices[3].color = Color(1.f, 0.f, 0.f, 1.f);
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
}

bool TPlaneObj::Frame()
{
    TMatrix matScale, matRotation, matTranslate;
    matScale.Scale(m_vScale);
    matRotation.ZRotate(m_vRotation.z);
    matTranslate.Translation(m_vPos);
    m_matWorld = matScale * matRotation * matTranslate;        
    return true;
}
