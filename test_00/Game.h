#pragma once
#include "Std.h"

class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd;

	shared_ptr<Graphics> _graphics;
	shared_ptr<Pipeline> _pipeline;

private:
	// Geometry
	shared_ptr<Geometry> _geometry;
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<InputLayout> _inputLayout;

	// VS
	shared_ptr<VertexShader> _vertexShader;

	// RS
	shared_ptr<RasterizerState> _rasterizerState;

	// PS
	shared_ptr<PixelShader> _pixelShader;

	// SRV
	shared_ptr<Texture> _texture1;

	shared_ptr<SamplerState> _samplerState;
	shared_ptr<BlendState> _blendState;
	// [ CPU<->RAM ] [GPU<->VRAM]
private:
	// SRT
	TransformData _transformData;
	shared_ptr<ConstantBuffer<TransformData>> _constantBuffer;

	Vec3 _localPosition = { 0.f, 0.f, 0.f };
	Vec3 _localRotation = { 0.f, 0.f, 0.f };
	Vec3 _localScale = { 1.f, 1.f, 1.f };
};
