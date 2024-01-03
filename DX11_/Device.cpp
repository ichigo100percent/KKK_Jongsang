#include "Device.h"


void Device::CreateDeviceAndSwapChain()
{
	D3D_DRIVER_TYPE DriverType = D3D_DRIVER_TYPE_HARDWARE;
	UINT Flags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#ifdef _DEBUG
	Flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	DXGI_SWAP_CHAIN_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	{
		desc.BufferDesc.Width = 800;
		desc.BufferDesc.Height = 600;
		desc.BufferDesc.RefreshRate.Numerator = 60;
		desc.BufferDesc.RefreshRate.Denominator = 1;
		desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		desc.SampleDesc.Count = 1;
		desc.SampleDesc.Quality = 0;
		desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		desc.BufferCount = 1;
		desc.OutputWindow = m_hWnd;
		desc.Windowed = true;
		desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	}

	HRESULT hr = ::D3D11CreateDeviceAndSwapChain
	(
		nullptr,
		DriverType,
		nullptr,
		Flags,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&desc,
		m_pSwapChain.GetAddressOf(),
		m_pDevice.GetAddressOf(),
		nullptr,
		m_pContext.GetAddressOf()
	);

	CHECK(hr);
}

void Device::CreateRenderTargetView()
{
	ComPtr<ID3D11Texture2D> backBuffer = nullptr;
	HRESULT hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)backBuffer.GetAddressOf());
	CHECK(hr);

	m_pDevice->CreateRenderTargetView(backBuffer.Get(), nullptr, m_pRenderTargetView.GetAddressOf());

	m_pContext->OMSetRenderTargets(1, m_pRenderTargetView.GetAddressOf(), nullptr);

	CHECK(hr);
}

void Device::SetViewport()
{
    viewport.Width = 800;
    viewport.Height = 600;
    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0f;
    viewport.TopLeftX = 0.0f;
    viewport.TopLeftY = 0.0f;
	m_pContext->RSSetViewports(1, &viewport);
}

void Device::CreateDevice()
{
	CreateDeviceAndSwapChain();
	CreateRenderTargetView();
	SetViewport();
}

bool Device::Init()
{
	CreateDevice();
	return true;
}

bool Device::Frame()
{
	return true;
}

bool Device::RenderBegin()
{
	m_pContext->ClearRenderTargetView(m_pRenderTargetView.Get(), clearColor);

	return true;
}

bool Device::RenderEnd()
{
    HRESULT hr = m_pSwapChain->Present(0, 0);
	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

bool Device::Render()
{
	RenderBegin();
	RenderEnd();

	return true;
}

bool Device::Release()
{
	if (m_pDevice) m_pDevice->Release();
	if (m_pContext) m_pContext->Release();
	if (m_pSwapChain) m_pSwapChain->Release();

	return true;
}