#pragma once
#include <Windows.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")  //timeGetTime()

class Timer
{
public:
	float m_fGameTimer;               //���� �ð��� ��Ÿ���� ����
	float m_fSecondPerFrame;		  //������ �� �ҿ� �ð�
	DWORD m_dwBeforeTime;		      //������ ����� �ð��� �����ϴ� ����
	float m_fFramePerSecond;		  //�ʴ� ������ ��	
	int m_IFPS;						  //FPS�� �����ϴ� ����

public:
	int GetFPS();                     //FPS ���� ��ȯ�ϴ� �Լ�
public:
	bool Init(); //�ʱ�ȭ �۾�
	bool Frame(); //�ǽð� ���
	bool Render(); //�ǽð� ������, ��ο�
	bool Release(); //��ü�� �Ҹ� �۾�
};