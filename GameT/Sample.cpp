#include "Sample.h"

void Sample::CreateGeometry()
{
	// VertexData
	{
		//_vertices.resize(4);

		//_vertices[0].position = Vec3(-0.5f, -0.5f, 0.f);
		////_vertices[0].uv = Vec2(0.f, 1.f);
		//_vertices[0].color = Color(1.f, 0.f, 0.f, 1.f);
		//_vertices[1].position = Vec3(-0.5f, 0.5f, 0.f);
		////_vertices[1].uv = Vec2(0.f, 0.f);
		//_vertices[1].color = Color(1.f, 0.f, 0.f, 1.f);
		//_vertices[2].position = Vec3(0.5f, -0.5f, 0.f);
		////_vertices[2].uv = Vec2(1.f, 1.f);
		//_vertices[2].color = Color(1.f, 0.f, 0.f, 1.f);
		//_vertices[3].position = Vec3(0.5f, 0.5f, 0.f);
		////_vertices[3].uv = Vec2(1.f, 0.f);
		//_vertices[3].color = Color(1.f, 0.f, 0.f, 1.f);

		_vertices.resize(3);

		_vertices[0].position = Vec3(-0.5f, -0.5f, 0.f);
		_vertices[0].color = Color(1.f, 0.f, 0.f, 1.f);
		_vertices[1].position = Vec3(0.f, 0.5f, 0.f);
		_vertices[1].color = Color(0.f, 1.f, 0.f, 1.f);
		_vertices[2].position = Vec3(0.5f, -0.5f, 0.f);
		_vertices[2].color = Color(0.f, 0.f, 1.f, 1.f);
	}

	// VertexBuffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(desc));
		desc.Usage = D3D11_USAGE_IMMUTABLE;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		desc.ByteWidth = (uint32)(sizeof(Vertex) * _vertices.size());

		D3D11_SUBRESOURCE_DATA data;
		ZeroMemory(&data, sizeof(data));
		data.pSysMem = _vertices.data();

		HRESULT hr = _device->CreateBuffer(&desc, &data, _vertexBuffer.GetAddressOf());
		CHECK(hr);
	}

	//// Index
	//{
	//	_indices = { 0, 1, 2, 2, 1, 3 };
	//}

	//// IndexBuffer
	//{
	//	D3D11_BUFFER_DESC desc;
	//	ZeroMemory(&desc, sizeof(desc));
	//	desc.Usage = D3D11_USAGE_IMMUTABLE;
	//	desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	//	desc.ByteWidth = (uint32)(sizeof(uint32) * _indices.size());

	//	D3D11_SUBRESOURCE_DATA data;
	//	ZeroMemory(&data, sizeof(data));
	//	data.pSysMem = _indices.data();

	//	HRESULT hr = _device->CreateBuffer(&desc, &data, _indexBuffer.GetAddressOf());
	//	CHECK(hr);
	//}
}

void Sample::CreateInputLayout()
{
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	const int32 count = sizeof(layout) / sizeof(D3D11_INPUT_ELEMENT_DESC);
	_device->CreateInputLayout(layout, count, _vsBlob->GetBufferPointer(), _vsBlob->GetBufferSize(), _inputLayout.GetAddressOf());
}

void Sample::CreateVS()
{
	LoadShaderFromFile(L"Default.hlsl", "VS", "vs_5_0", _vsBlob);
	HRESULT hr = _device->CreateVertexShader(_vsBlob->GetBufferPointer(), _vsBlob->GetBufferSize(), nullptr, _vertexShader.GetAddressOf());
	CHECK(hr);
}

void Sample::CreatePS()
{
	LoadShaderFromFile(L"Default.hlsl", "PS", "ps_5_0", _psBlob);
	HRESULT hr = _device->CreatePixelShader(_psBlob->GetBufferPointer(), _psBlob->GetBufferSize(), nullptr, _pixelShader.GetAddressOf());
	CHECK(hr);
}

void Sample::LoadShaderFromFile(const wstring& path, const string& name, const string& version, ComPtr<ID3DBlob>& blob)
{
	const uint32 compileFlag = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;

	HRESULT hr = ::D3DCompileFromFile(
		path.c_str(),
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE,
		name.c_str(),
		version.c_str(),
		compileFlag,
		0,
		blob.GetAddressOf(),
		nullptr);

	CHECK(hr);
}


bool  Sample::Init()
{
	CreateGeometry();
	CreateVS();
	CreatePS();
	CreateInputLayout();
    return true;
}
bool  Sample::Frame()
{
    return true;
}
bool  Sample::Render()
{
	uint32 stride = sizeof(Vertex);
	uint32 offset = 0;
	// IA
	_deviceContext->IASetVertexBuffers(0, 1, _vertexBuffer.GetAddressOf(), &stride, &offset);
	//_deviceContext->IASetIndexBuffer(_indexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);
	_deviceContext->IASetInputLayout(_inputLayout.Get());
	_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// VS
	_deviceContext->VSSetShader(_vertexShader.Get(), nullptr, 0);

	// PS
	_deviceContext->PSSetShader(_pixelShader.Get(), nullptr, 0);

	// OM
	_deviceContext->Draw(_vertices.size(), 0);
	//_deviceContext->DrawIndexed(_indices.size(), 0, 0);
    return true;
}
bool  Sample::Release()
{
    return true;
}


TGAME(L"TEST", 800, 600)