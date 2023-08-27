#pragma once
#include "Std.h"

struct VertexTextureData
{
	Vec3 position = { 0, 0, 0 };
	Vec2 uv = { 0, 0 };

	static vector<D3D11_INPUT_ELEMENT_DESC> descs;
};

class Geometry
{
public:
	Geometry() {}
	~Geometry() {}

	uint32 GetVertexCount() { return static_cast<uint32>(_vertices.size()); }
	void* GetVertexData() { return _vertices.data(); }
	const vector<VertexTextureData>& GetVertices() { return _vertices; }

	uint32 GetIndexCount() { return static_cast<uint32>(_indices.size()); }
	void* GetIndexData() { return _indices.data(); }
	const vector<uint32>& GetIndices() { return _indices; }

	void AddVertex(const VertexTextureData& vertex) { _vertices.push_back(vertex); }
	void AddVertices(const vector<VertexTextureData>& vertices) { _vertices.insert(_vertices.end(), vertices.begin(), vertices.end()); }
	void SetVertices(vector<VertexTextureData>& vertices) { _vertices = vertices; }

	void AddIndex(uint32 index) { _indices.push_back(index); }
	void AddIndices(const vector<uint32>& indices) { _indices.insert(_indices.end(), indices.begin(), indices.end()); }
	void SetIndices(vector<uint32>& indices) { _indices = indices; }


    void CreateRectangle()
	{
		vector<VertexTextureData> vertices;
		vertices.resize(4);

		vertices[0].position = Vec3(-0.5f, -0.5f, 0.f);
		vertices[0].uv = Vec2(0.f, 1.f);
		vertices[1].position = Vec3(-0.5f, 0.5f, 0.f);
		vertices[1].uv = Vec2(0.f, 0.f);
		vertices[2].position = Vec3(0.5f, -0.5f, 0.f);
		vertices[2].uv = Vec2(1.f, 1.f);
		vertices[3].position = Vec3(0.5f, 0.5f, 0.f);
		vertices[3].uv = Vec2(1.f, 0.f);
		SetVertices(vertices);

		vector<uint32> indices = { 0, 1, 2, 2, 1, 3 };
		SetIndices(indices);
	}

private:
	vector<VertexTextureData> _vertices;
	vector<uint32> _indices;
};
