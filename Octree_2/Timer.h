#pragma once
#include <Windows.h>
#include <iostream>
#pragma  comment (lib, "winmm.lib")

class Timer
{
public:
	float m_fGameTimer;            //게임의 경과 시간을 저장하는 변수
	float m_fSecondPerFrame;       //한 프레임 당 걸리는 시간을 저장하는 변수
	DWORD m_dwBeforeTime;          //이전 프레임이 시작된 시간을 저장하는 변수
	float m_fFrameFerSecond;       //FPS(초당 프레임 수)를 저장하는 변수
	int m_iFPS;					   //FPS를 정수형으로 저장하는 변수

public:
	int GetFPS();
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};