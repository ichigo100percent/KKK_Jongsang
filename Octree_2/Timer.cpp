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
	//현재 시간을 얻어옵니다.
	DWORD dwCurrentTime = timeGetTime();
	//이전 프레임부터 현재까지의 시간 간격을 계산합니다.
	DWORD dwElapseTime = dwCurrentTime - m_dwBeforeTime;

	//한 프레임당 걸린 시간을 초 단위로 계산합니다.
	m_fSecondPerFrame = dwElapseTime / 1000.0f;
	//게임의 경과 시간을 누적합니다.
	m_fGameTimer += m_fSecondPerFrame;
	//이전 프레임 시작 시간을 갱신합니다.
	m_dwBeforeTime = dwCurrentTime;

	//FPS 계산을 위해 누적 시간을 갱신합니다.
	m_fFrameFerSecond += m_fSecondPerFrame;
	return true;
}

int Timer::GetFPS()
{
	static int iFPS = 0;

	//1초를 초과한 누적 시간을 처리합니다.
	if (m_fFrameFerSecond >= 1.0f)
	{
		//현재까지의 프레임 수를 FPS로 저장합니다.
		m_iFPS = iFPS;
		//프레임 수를 다시 초기화합니다.
		iFPS = 0;
		//1초를 초과한 누적 시간을 1초를 빼서 남아있지 않도록 합니다.
		m_fFrameFerSecond -= 1.0f;
	}
	//프레임 수를 증가합니다.
	iFPS++;
	return m_iFPS;
}

bool Timer::Render()
{
	//FPS, 게임의 경과 시간, 한 프레임당 걸린 시간을 콘솔에 출력합니다.
	std::cout << "[FPS]" << GetFPS() << " [GT]" << m_fGameTimer << " [SPF]" << m_fSecondPerFrame << std::endl;
	return true;
}

bool Timer::Release()
{
	return true;
}