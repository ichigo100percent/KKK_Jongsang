#pragma once
#include "Windows.h"

class Device : public TWindow
{

public:
    //Device & SwapChain
    ComPtr<IDXGISwapChain>          _swapChain = nullptr;
    ComPtr<ID3D11Device>            _device = nullptr;
    ComPtr<ID3D11DeviceContext>     _deviceContext = nullptr;

    /// RTV
    ComPtr<ID3D11RenderTargetView>  _renderTargetView;

    // Misc
    D3D11_VIEWPORT _viewport = { 0 };
    float _clearColor[4] = { 1.f, 1.f, 1.f, 0.f };

public:
    bool  Init();
    bool  Frame();
    bool  Render();
    bool  Release();

    void RenderBegin();
    void RenderEnd();

private:
    void CreateDeviceAndSwapChain();
    void CreateRenderTargetView();
    void SetViewport();
};

