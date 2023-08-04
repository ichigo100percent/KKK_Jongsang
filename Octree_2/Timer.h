#pragma once
#include <Windows.h>
#include <iostream>
#pragma  comment (lib, "winmm.lib")

class Timer
{
public:
	float m_fGameTimer;            //������ ��� �ð��� �����ϴ� ����
	float m_fSecondPerFrame;       //�� ������ �� �ɸ��� �ð��� �����ϴ� ����
	DWORD m_dwBeforeTime;          //���� �������� ���۵� �ð��� �����ϴ� ����
	float m_fFrameFerSecond;       //FPS(�ʴ� ������ ��)�� �����ϴ� ����
	int m_iFPS;					   //FPS�� ���������� �����ϴ� ����

public:
	int GetFPS();
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};