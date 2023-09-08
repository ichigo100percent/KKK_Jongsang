#pragma once
#include "Core.h"

class Sample : public Core
{
public:
    // Geometry
    vector<Vertex> _vertices;
    ComPtr<ID3D11Buffer> _vertexBuffer = nullptr;
    vector<uint32> _indices;
    ComPtr<ID3D11Buffer> _indexBuffer = nullptr;
    ComPtr<ID3D11InputLayout> _inputLayout = nullptr;

    // VS
    ComPtr<ID3D11VertexShader> _vertexShader = nullptr;
    ComPtr<ID3DBlob> _vsBlob = nullptr;

    // PS
    ComPtr<ID3D11PixelShader> _pixelShader = nullptr;
    ComPtr<ID3DBlob> _psBlob = nullptr;

    // SRV
    ComPtr<ID3D11ShaderResourceView> _shaderResourveView = nullptr;

public:
    void CreateGeometry();
    void CreateInputLayout();
    void CreateVS();
    void CreatePS();

    void LoadShaderFromFile(const wstring& path, const string& name, const string& version, ComPtr<ID3DBlob>& blob);

public:
    bool  Init();
    bool  Frame();
    bool  Render();
    bool  Release();
};

