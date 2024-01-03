#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;

	_graphics = make_shared<Graphics>(hwnd);
	_vertexBuffer = make_shared<VertexBuffer>(_graphics->GetDevice());
	_indexBuffer = make_shared<IndexBuffer>(_graphics->GetDevice());
	_inputLayout = make_shared<InputLayout>(_graphics->GetDevice());
	_geometry = make_shared<Geometry>();
	_vertexShader = make_shared<VertexShader>(_graphics->GetDevice());
	_pixelShader = make_shared<PixelShader>(_graphics->GetDevice());
	_constantBuffer = make_shared<ConstantBuffer<TransformData>>(_graphics->GetDevice(), _graphics->GetDeviceContext());
	_texture1 = make_shared<Texture>(_graphics->GetDevice());
	_rasterizerState = make_shared<RasterizerState>(_graphics->GetDevice());
	_samplerState = make_shared<SamplerState>(_graphics->GetDevice());
	_blendState = make_shared<BlendState>(_graphics->GetDevice());
	_pipeline = make_shared<Pipeline>(_graphics->GetDeviceContext());

	// VertexData
	_geometry->CreateRectangle();

	// VertexBuffer
	_vertexBuffer->Create(_geometry->GetVertices());

	// IndexBuffer
	_indexBuffer->Create(_geometry->GetIndices());

	_vertexShader->Create(L"Default.hlsl", "VS", "vs_5_0");
	_inputLayout->Create(VertexTextureData::descs, _vertexShader->GetBlob());
	_pixelShader->Create(L"Default.hlsl", "PS", "ps_5_0");

	_rasterizerState->Create();
	_samplerState->Create();
	_blendState->Create();

	_texture1->Create(L"Skeleton.png");
	_constantBuffer->Create();
}

void Game::Update()
{
	_localPosition.x += 0.001f;

	Matrix matScale = Matrix::CreateScale(_localScale);
	Matrix matRotation = Matrix::CreateRotationX(_localRotation.x);
	matRotation *= Matrix::CreateRotationY(_localRotation.y);
	matRotation *= Matrix::CreateRotationZ(_localRotation.z);
	Matrix matTranslation = Matrix::CreateTranslation(_localPosition);

	Matrix matWorld = matScale * matRotation * matTranslation; // SRT
	_transformData.matWorld = matWorld;

	_constantBuffer->CopyData(_transformData);
}

void Game::Render()
{
	//RenderBegin();
	_graphics->RenderBegin();

	{
		PipelineInfo info;
		info.inputLayout = _inputLayout;
		info.vertexShader = _vertexShader;
		info.pixelShader = _pixelShader;
		info.rasterizerState = _rasterizerState;
		info.blendState = _blendState;

		_pipeline->UpdatePipeline(info);

		_pipeline->SetVertexBuffer(_vertexBuffer);
		_pipeline->SetIndexBuffer(_indexBuffer);
		_pipeline->SetConstantBuffer(0, SS_VertexShader, _constantBuffer);
		_pipeline->SetTexture(0, SS_PixelShader, _texture1);
		_pipeline->SetSamplerState(0, SS_PixelShader, _samplerState);
		_pipeline->DrawIndexed(_geometry->GetIndexCount(), 0, 0);


		//uint32 stride = sizeof(VertexTextureData);
		//uint32 offset = 0;

		//auto _deviceContext = _graphics->GetDeviceContext();
		//// IA
		//_deviceContext->IASetVertexBuffers(0, 1, _vertexBuffer->GetComPtr().GetAddressOf(), &stride, &offset);
		//_deviceContext->IASetIndexBuffer(_indexBuffer->GetComPtr().Get(), DXGI_FORMAT_R32_UINT, 0);
		//_deviceContext->IASetInputLayout(_inputLayout->GetComPtr().Get());
		//_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		//// VS
		//_deviceContext->VSSetShader(_vertexShader->GetComPtr().Get(), nullptr, 0);
		//_deviceContext->VSSetConstantBuffers(0, 1, _constantBuffer->GetComPtr().GetAddressOf());

		//// RS
		//_deviceContext->RSSetState(_rasterizerState->GetComPtr().Get());

		//// PS
		//_deviceContext->PSSetShader(_pixelShader->GetComPtr().Get(), nullptr, 0);
		//_deviceContext->PSSetShaderResources(0, 1, _texture1->GetComPtr().GetAddressOf());
		////_deviceContext->PSSetShaderResources(1, 1, _shaderResourveView2.GetAddressOf());
		//_deviceContext->PSSetSamplers(0, 1, _samplerState->GetComPtr().GetAddressOf());

		//// OM
		//_deviceContext->OMSetBlendState(_blendState->GetComPtr().Get(), nullptr, 0xFFFFFFFF);

		////_deviceContext->Draw(_vertices.size(), 0);
		//_deviceContext->DrawIndexed(_geometry->GetIndexCount(), 0, 0);
	}

	_graphics->RenderEnd();
}


 