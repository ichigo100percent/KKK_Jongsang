#pragma once
#include "GameObject.h"

class PlaneObject : public GameObject
{
public:
	virtual bool		CreateVertexBuffer() override;
	virtual bool		Frame();
};

