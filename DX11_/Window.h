#pragma once
#include "Std.h"

class Window
{
public:
    HINSTANCE   m_hInstance;               
    HWND        m_hWnd;
    DWORD       m_dwExStyle = 0;
    DWORD       m_dwStyle = WS_OVERLAPPEDWINDOW;
    DWORD       m_dwWindowPosX = 0;
    DWORD       m_dwWindowPosY = 0;
    DWORD       m_dwWindowWidth;
    DWORD       m_dwWindowHeight;

    RECT        m_rtWindow;
    RECT        m_rtClient;

public:
    bool  SetRegisterClassWindow(HINSTANCE hInstance);
    bool  SetWindow(const WCHAR* szTitle, 
        DWORD       dwWindowWidth = 800,
        DWORD       dwWindowHeight = 600);

public:
    virtual ~Window() {}
};

