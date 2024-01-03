#include "Time.h"

float g_fSecPerFrame = 0.0f;

bool Time::init()
{
    m_dwTickStart = timeGetTime();

    return true;
}

bool Time::Frame()
{
    m_dwTickEnd = timeGetTime();
    DWORD dwElapseTick = m_dwTickEnd - m_dwTickStart;

    g_fSecPerFrame = m_fSecondPerFrame = dwElapseTick / 1000.0f;
    m_fGameTimer += m_fSecondPerFrame;

    m_iFPS++;
    m_dwTime += dwElapseTick;
    if (m_dwTime >= 1000)
    {
        m_msg = std::to_wstring(m_iFPS);
        m_msg += L" FPS\n";
        m_dwTime -= 1000;
        m_iFPS = 0;
    }

    m_dwTickStart = m_dwTickEnd;

    return true;
}

bool Time::Render()
{
    m_outmsg.clear();
    m_outmsg = L"���Ӱ���ð�:";
    m_outmsg += std::to_wstring(m_fGameTimer);
    m_outmsg += L" ";
    m_outmsg += L"1������ ����ð�:";
    m_outmsg += std::to_wstring(m_fSecondPerFrame);
    m_outmsg += L" ";
    m_outmsg += L"�ʴ� ������:";
    m_outmsg += m_msg;
    m_outmsg += L"\n";

    return true;
}

bool Time::Release()
{
    return true;
}
