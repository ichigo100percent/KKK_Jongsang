#pragma once
#include "TCore.h"
#include "Sprite.h"

class Sample : public TCore
{
	TObject* m_pMapObj = nullptr;
	TSpriteObj* m_pSpriteTexObj = nullptr;
	TSpriteObj* m_pSpriteUVObj = nullptr;
	TSpriteObj* m_pSpriteAirObj = nullptr;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

