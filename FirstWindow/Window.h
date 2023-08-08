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
public:
    virtual bool  EngineInit();
    virtual bool  EngineFrame();
    virtual bool  EngineRender();
    virtual bool  EngineRelease();
public:
    bool  SetRegisterClassWindow(HINSTANCE hInstance);
    bool  SetWindow(const WCHAR* szTitle, //std::wstring szTitle, 
        DWORD       dwWindowWidth = 800,
        DWORD       dwWindowHeight = 600);
    bool  Run();
public:
    virtual ~Window() {}
public:
};
