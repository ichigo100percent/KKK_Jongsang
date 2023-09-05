#pragma once
#include "MonoBehaviour.h"

class Test : public MonoBehaviour 
{
public:

	Test(ComPtr<ID3D11Device> device, ComPtr<ID3D11DeviceContext> deviceContext)
		: _device(device), _deviceContext(deviceContext)
	{

	}
	ComPtr<ID3D11Device> _device;
	ComPtr<ID3D11DeviceContext> _deviceContext;
	virtual void Awake() override;
	virtual void Update() override;


	void MoveObjectForward();
};

