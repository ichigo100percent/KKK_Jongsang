#pragma once
#include "Js_Window.h"
#include <wrl/client.h>

using namespace Microsoft::WRL;

namespace Js
{
	class Device : public Window
	{
	public:
		Device();
		
		void CreateDevice();
		void CreateDeviceAndSwapChain();
		void CreateRenderTargetView();
		void SetViewport();
		void DeleteDeivce();
		void PreRender();
		void PostRender();

		
	private:
		ComPtr<ID3D11Device>			m_Device;
		ComPtr<ID3D11DeviceContext>		m_Context;
		ComPtr<ID3D11RenderTargetView>	m_RenderTargetView;
		ComPtr<IDXGISwapChain>			m_SwapChain;
		
		D3D11_VIEWPORT viewport = { 0 };
	};
}
