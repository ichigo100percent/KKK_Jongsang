#pragma once
#include "Core.h"
#include "PlayerObject.h"


class Game : public Core
{
public:
    ComPtr<ID3D11BlendState> m_AlphaBlend = nullptr;
    unique_ptr<GameObject>   m_mapObj = nullptr;

public:
    bool Init() override;
    bool Frame() override;
    bool Render() override;
    bool Release() override;

    void  CreateBlendState();
};

