#pragma once
#include "Device.h"
#include "Input.h"
#include "Time.h"
#include "DxWrite.h"
#include "Camera.h"
#include "ShaderMgr.h"
#include "TexMgr.h"

class Core : public Device
{
public:
	Camera		m_mainCamera;
	Time		m_time;
	DxWrite		m_dxWrite;

public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();
	
	bool		 Run();

private:
	virtual bool EngineInit();
	virtual bool EngineFrame();
	virtual bool EngineRender();
	virtual bool EngineRelease();

};

