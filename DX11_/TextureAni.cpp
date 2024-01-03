//#include "TextureAni.h"
//
//bool TextureAni::Create(W_STR name, T_STR_VECTOR texFileName)
//{
//    m_csName = name;
//    m_rtRect.left = _vertices[0].position.x;
//    m_rtRect.top = _vertices[0].position.y;
//    m_rtRect.right = _vertices[2].position.x;
//    m_rtRect.bottom = _vertices[2].position.y;
//    //m_uiState = T_CONTROL_STATE::T_STATE_NORMAL;
//    LoadTexture(texFileName);
//    return true;
//}
//
//bool TextureAni::Create(W_STR name,
//    W_STR texFileName, UINT iNumWidth, UINT iNumHeight, float fAnimTime)
//{
//    m_csName = name;
//    m_rtRect.left = _vertices[0].position.x;
//    m_rtRect.top = _vertices[0].position.y;
//    m_rtRect.right = _vertices[2].position.x;
//    m_rtRect.bottom = _vertices[2].position.y;
//
//    m_iNumWidth = iNumWidth;
//    m_iNumHeight = iNumHeight;
//    float fWidthStep = 1.0f / iNumWidth;
//    float fHeightStep = 1.0f / iNumHeight;
//    for (int y = 0; y < iNumHeight; y++)
//    {
//        for (int x = 0; x < iNumWidth; x++)
//        {
//            UVRECT tRt;
//            tRt.top = y * fHeightStep;
//            tRt.left = x * fWidthStep;
//            tRt.right = tRt.left + fWidthStep;
//            tRt.bottom = tRt.top + fHeightStep;
//            m_pUVArray.push_back(tRt);
//        }
//    }
//
//    m_iApplyIndex = 0;
//    m_fTimer = 0.0f;
//    m_fInitAnimationTime = m_fAnimationTime = fAnimTime;
//    m_fStepTime = m_fAnimationTime / m_pUVArray.size();
//
//    m_uvIndex = m_pUVArray[m_iApplyIndex];
//    _vertices[0].uv = Vec2(m_uvIndex.left, m_uvIndex.top);      // 0
//    _vertices[1].uv = Vec2(m_uvIndex.right, m_uvIndex.top);    // 1
//    _vertices[2].uv = Vec2(m_uvIndex.right, m_uvIndex.bottom);  // 2
//    _vertices[3].uv = Vec2(m_uvIndex.left, m_uvIndex.bottom);    // 3
//
//    LoadTexture(texFileName);
//    return true;
//}
//
//
//bool    TextureAni::Init() {
//    return true;
//};
//
//
//bool TextureAni::LoadTexture(T_STR_VECTOR texArray)
//{
//    for (int i = 0; i < texArray.size(); i++)
//    {
//        m_pTexArray.push_back(TextureMgr::Get().Load(texArray[i]));
//    }
//    //m_ptTex = m_pTexArray[m_uiState];
//    return true;
//}
//bool    TextureAni::LoadTexture(std::wstring texFileName) {
//    m_ptTex = TextureMgr::Get().Load(texFileName);
//    if (m_ptTex != nullptr)
//        return true;
//    return false;
//};
//bool    TextureAni::PreRender() {
//    return true;
//};
//bool    TextureAni::Frame(float fElapsTime)
//{
//    if (m_fAnimationTime <= 0.0f)
//    {
//        //m_bStop = true;
//         //return true;
//        m_iApplyIndex = 0;
//        m_fAnimationTime = m_fInitAnimationTime;
//        return true;
//    }
//    m_fAnimationTime -= fElapsTime;
//    m_fTimer += fElapsTime;
//    if (m_fTimer >= m_fStepTime)
//    {
//        m_iApplyIndex++;
//        m_iApplyIndex = min(m_pUVArray.size() - 1, m_iApplyIndex);
//        m_fTimer -= m_fStepTime;
//
//        m_uvIndex = m_pUVArray[m_iApplyIndex];
//        _vertices[0].uv = Vec2(m_uvIndex.left, m_uvIndex.top);      // 0
//        _vertices[1].uv = Vec2(m_uvIndex.right, m_uvIndex.top);    // 1
//        _vertices[2].uv = Vec2(m_uvIndex.right, m_uvIndex.bottom);  // 2
//        _vertices[3].uv = Vec2(m_uvIndex.left, m_uvIndex.bottom);    // 3
//    }
//    return true;
//}
//bool    TextureAni::Render(ID3D11DeviceContext* pd3dContext) {
//    if (m_ptTex == nullptr) return true;
//    pd3dContext->PSSetShaderResources(0, 1, &m_ptTex->m_pTextureSRV);
//    return true;
//};
//bool    TextureAni::PostRender() { return true; };
//bool    TextureAni::Release() { return true; };
//
