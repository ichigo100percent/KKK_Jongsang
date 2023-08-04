#include "Timer.h"

bool Timer::Init()
{
    m_fFramePerSecond = 0.0f;
    m_fGameTimer = 0.0f;
    m_fSecondPerFrame = 0.0f;
    m_dwBeforeTime = timeGetTime();   //tick counter 1000 => 1초
    return true;
}

bool Timer::Frame()
{
    DWORD dwCurrentTime = timeGetTime();                    
    DWORD dwElapseTime = dwCurrentTime - m_dwBeforeTime;     //이전 시간으로부터 경과한 시간 계산
    m_fSecondPerFrame = dwElapseTime / 1000.0f;              //경과 시간을 초로 변환하여 프레임당 소요 시간 계산
    m_fGameTimer += m_fSecondPerFrame;                       //게임 시간을 누적
    m_dwBeforeTime = dwCurrentTime;                          //이전 시간을 현재 시간으로 업데이트
    m_fFramePerSecond += m_fSecondPerFrame;                  //초당 프레임 수를 누적
    return true;
}

int Timer::GetFPS()
{
    static int iFPS = 0;
    if (m_fFramePerSecond >= 1.0f)
    {
        m_IFPS = iFPS;                                  //FPS 값을 저장
        iFPS = 0;
        m_fFramePerSecond -= 1.0f;                      //초당 프레임 수를 갱신
    }
    iFPS++;                      //프레임 수 증가
    return m_IFPS;               //FPS 값을 반환
}

bool Timer::Render()
{
    std::cout << "[FPS]" << GetFPS() << " [GT]" << m_fGameTimer << " [SPF]" << m_fFramePerSecond << std::endl;
    return true;
}

bool Timer::Release()
{
    return true;
}