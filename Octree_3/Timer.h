#pragma once
#include <Windows.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")

class Timer
{
public:
	float m_fGameTimer;
	float m_fSecondPerFrame;
	DWORD m_dwBeforeTime;
	float m_fFramePerSecond;
	float m_iFPS;

public:
	int GetFPS();
	
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};