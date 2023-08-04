#pragma once
#include <Windows.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")  //timeGetTime()

class Timer
{
public:
	float m_fGameTimer;               //게임 시간을 나타내는 변수
	float m_fSecondPerFrame;		  //프레임 당 소요 시간
	DWORD m_dwBeforeTime;		      //이전에 계산한 시간을 저장하는 변수
	float m_fFramePerSecond;		  //초당 프레임 수	
	int m_IFPS;						  //FPS를 저장하는 변수

public:
	int GetFPS();                     //FPS 값을 반환하는 함수
public:
	bool Init(); //초기화 작업
	bool Frame(); //실시간 계산
	bool Render(); //실시간 랜더링, 드로우
	bool Release(); //객체의 소멸 작업
};