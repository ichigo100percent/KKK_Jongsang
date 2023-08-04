#include "Timer.h"

bool Timer::Init()
{
    m_fFramePerSecond = 0.0f;
    m_fGameTimer = 0.0f;
    m_fSecondPerFrame = 0.0f;
    m_dwBeforeTime = timeGetTime();   //tick counter 1000 => 1��
    return true;
}

bool Timer::Frame()
{
    DWORD dwCurrentTime = timeGetTime();                    
    DWORD dwElapseTime = dwCurrentTime - m_dwBeforeTime;     //���� �ð����κ��� ����� �ð� ���
    m_fSecondPerFrame = dwElapseTime / 1000.0f;              //��� �ð��� �ʷ� ��ȯ�Ͽ� �����Ӵ� �ҿ� �ð� ���
    m_fGameTimer += m_fSecondPerFrame;                       //���� �ð��� ����
    m_dwBeforeTime = dwCurrentTime;                          //���� �ð��� ���� �ð����� ������Ʈ
    m_fFramePerSecond += m_fSecondPerFrame;                  //�ʴ� ������ ���� ����
    return true;
}

int Timer::GetFPS()
{
    static int iFPS = 0;
    if (m_fFramePerSecond >= 1.0f)
    {
        m_IFPS = iFPS;                                  //FPS ���� ����
        iFPS = 0;
        m_fFramePerSecond -= 1.0f;                      //�ʴ� ������ ���� ����
    }
    iFPS++;                      //������ �� ����
    return m_IFPS;               //FPS ���� ��ȯ
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