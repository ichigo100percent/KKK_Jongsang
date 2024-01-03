#include "Core.h"

bool Core::Init() { return true; }
bool Core::Frame() { return true; }
bool Core::Render() { return true; }
bool Core::Release() { return true; }

bool Core::EngineInit()
{
    
    Device::Init();
    ShaderMgr::Instance().Set(m_pDevice, m_pContext);
    TextureMgr::Instance().Set(m_pDevice, m_pContext);

    ComPtr<IDXGISurface> dxgiSurface;
    HRESULT hr = m_pSwapChain->GetBuffer(0, __uuidof(IDXGISurface), (void**)&dxgiSurface);
    if (SUCCEEDED(hr))
    {
        m_dxWrite.Init(dxgiSurface);
        if (dxgiSurface)dxgiSurface->Release();
    }

    Input::Get().Init();
    m_time.init();


	Init();
	return true;
}

bool  Core::EngineFrame()
{
    Device::Frame();
    m_time.Frame();
    Input::Get().Frame();
   
	Frame();
	return true;
}

bool  Core::EngineRender()
{
    Device::RenderBegin();
    Render();

    m_time.Render();
    Input::Get().Render();

    m_dxWrite.Draw20(0, 30, m_time.m_outmsg);
    Device::RenderEnd();
	return true;
}

bool  Core::EngineRelease()
{
    Input::Get().Release();
    m_mainCamera.Release();
    m_time.Release();
    Device::Release();
	Release();
	return true;
}

bool Core::Run()
{
    EngineInit();
    MSG msg = { 0 };
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            if (!EngineFrame() || !EngineRender())
            {
                break;
            }
        }
     }
    EngineRelease();
    return true;
}

