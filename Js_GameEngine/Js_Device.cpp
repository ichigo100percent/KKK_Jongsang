#include "Js_Device.h"


namespace Js
{
	Device::Device() :
		m_Device(nullptr),
		m_Context(nullptr),
		m_RenderTargetView(nullptr),
		m_SwapChain(nullptr)
	{

	}
	void Device::CreateDevice()
	{
		CreateDeviceAndSwapChain();
		CreateRenderTargetView();
		SetViewport();
	}
	void Device::CreateDeviceAndSwapChain()
	{
		DXGI_SWAP_CHAIN_DESC desc;
		ZeroMemory(&desc, sizeof(DXGI_SWAP_CHAIN_DESC));
		{
			desc.BufferDesc.Width = 800;
			desc.BufferDesc.Height = 600;
			desc.BufferDesc.RefreshRate.Numerator = 60;
			desc.BufferDesc.RefreshRate.Denominator = 1;
			desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			desc.SampleDesc.Count = 1;
			desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
			desc.BufferCount = 1;
			desc.OutputWindow = m_Hwnd;
			desc.Windowed = true;
		}

		CONST D3D_FEATURE_LEVEL pFeatureLevels = D3D_FEATURE_LEVEL_11_0;
		HRESULT hr = D3D11CreateDeviceAndSwapChain
		(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			0,
			&pFeatureLevels,
			1,
			D3D11_SDK_VERSION,
			&desc,
			m_SwapChain.GetAddressOf(),
			m_Device.GetAddressOf(),
			nullptr,
			m_Context.GetAddressOf()
		);

		CHECK(hr);
	}
	void Device::CreateRenderTargetView()
	{
		if (m_Device != nullptr && m_SwapChain != nullptr)
		{
			ComPtr<ID3D11Texture2D> backBuffer = nullptr;
			HRESULT hr = m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)backBuffer.GetAddressOf());
			CHECK(hr);

			ComPtr<ID3D11Resource> pResource = backBuffer;
			D3D11_RENDER_TARGET_VIEW_DESC* pDesc = nullptr;
			hr = m_Device->CreateRenderTargetView(
				pResource.Get(),
				pDesc,
				m_RenderTargetView.GetAddressOf());

			m_Context->OMSetRenderTargets(1, m_RenderTargetView.GetAddressOf(), nullptr);

			CHECK(hr);
		}
	}
	void Device::SetViewport()
	{

	}

	void Device::DeleteDeivce()
	{
		if (m_Device) m_Device.Reset();
		if (m_Context)m_Context.Reset();
		if (m_RenderTargetView) m_RenderTargetView.Reset();
		if (m_SwapChain) m_SwapChain.Reset();
	}

	void Device::PreRender()
	{
		float clearColor[4] = { 0.5f, 0.5f, 0.5f, 1.f };
		m_Context->ClearRenderTargetView(m_RenderTargetView.Get(), clearColor);
	}
	void Device::PostRender()
	{
		HRESULT hr = m_SwapChain->Present(0, 0);
		CHECK(hr);
	}
}