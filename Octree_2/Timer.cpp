#include "Timer.h"

bool Timer::Init()
{
	m_fFrameFerSecond = 0.0f;
	m_fGameTimer = 0.0f;
	m_fSecondPerFrame = 0.0f;
	m_dwBeforeTime = timeGetTime();
	return true;
}

bool Timer::Frame()
{
	//���� �ð��� ���ɴϴ�.
	DWORD dwCurrentTime = timeGetTime();
	//���� �����Ӻ��� ��������� �ð� ������ ����մϴ�.
	DWORD dwElapseTime = dwCurrentTime - m_dwBeforeTime;

	//�� �����Ӵ� �ɸ� �ð��� �� ������ ����մϴ�.
	m_fSecondPerFrame = dwElapseTime / 1000.0f;
	//������ ��� �ð��� �����մϴ�.
	m_fGameTimer += m_fSecondPerFrame;
	//���� ������ ���� �ð��� �����մϴ�.
	m_dwBeforeTime = dwCurrentTime;

	//FPS ����� ���� ���� �ð��� �����մϴ�.
	m_fFrameFerSecond += m_fSecondPerFrame;
	return true;
}

int Timer::GetFPS()
{
	static int iFPS = 0;

	//1�ʸ� �ʰ��� ���� �ð��� ó���մϴ�.
	if (m_fFrameFerSecond >= 1.0f)
	{
		//��������� ������ ���� FPS�� �����մϴ�.
		m_iFPS = iFPS;
		//������ ���� �ٽ� �ʱ�ȭ�մϴ�.
		iFPS = 0;
		//1�ʸ� �ʰ��� ���� �ð��� 1�ʸ� ���� �������� �ʵ��� �մϴ�.
		m_fFrameFerSecond -= 1.0f;
	}
	//������ ���� �����մϴ�.
	iFPS++;
	return m_iFPS;
}

bool Timer::Render()
{
	//FPS, ������ ��� �ð�, �� �����Ӵ� �ɸ� �ð��� �ֿܼ� ����մϴ�.
	std::cout << "[FPS]" << GetFPS() << " [GT]" << m_fGameTimer << " [SPF]" << m_fSecondPerFrame << std::endl;
	return true;
}

bool Timer::Release()
{
	return true;
}