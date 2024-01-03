#pragma once
#include "Window.h"


class Device : public Window
{
public:
	ComPtr<ID3D11Device>			m_pDevice = nullptr;
	ComPtr<ID3D11DeviceContext>		m_pContext = nullptr;
	ComPtr<ID3D11RenderTargetView>	m_pRenderTargetView = nullptr;
	ComPtr<IDXGISwapChain>			m_pSwapChain = nullptr;

	D3D11_VIEWPORT viewport = { 0 };
	float clearColor[4] = { 0.f, 1.f, 0.f, 0.f };

public:
	bool Init();
	bool Frame();
	bool RenderBegin();
	bool RenderEnd();
	bool Render();
	bool Release();

public:
	void CreateDevice();
	void CreateDeviceAndSwapChain();
	void CreateRenderTargetView();
	void SetViewport();
};

