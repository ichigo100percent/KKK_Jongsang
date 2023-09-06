#pragma once
#include "TCore.h"
#include "TPlaneObj.h"
#include "Player.h"

class Sample : public TCore
{
	TObject* m_pMapObj = nullptr;
	Player* m_pPlayer = new Player;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

