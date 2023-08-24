#pragma once
#include "Core.h"
#include "PlaneObj.h"

class Sample : public Core
{
    TextureMgr             m_texMgr;
    ShaderMgr              m_shaderMgr;
    std::vector<Object*>   m_ObjList;
    ID3D11BlendState* m_AlphaBlend = nullptr;
public:
    bool  Init();
    bool  Frame();
    bool  Render();
    bool  Release();
public:
    void  CreateBlendState();
};
