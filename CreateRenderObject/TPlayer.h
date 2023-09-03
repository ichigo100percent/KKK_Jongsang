#pragma once
#include "TPlaneObj.h"
#include "TTextureMgr.h"
#include "TShaderMgr.h"

class TPlayer : public TPlaneObj
{
public:
    virtual bool	CreateVertexBuffer() override;
    bool            _bFlip = false;

    bool  Init();
    bool  Frame();
    bool  Render();
    bool  Release();
};

