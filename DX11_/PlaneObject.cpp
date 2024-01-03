#include "PlaneObject.h"

bool PlaneObject::CreateVertexBuffer()
{
	m_VertexList.resize(6);

	m_VertexList[0].p = Vec3(-1.0f, 1.0f, 0.0f);
	m_VertexList[1].p = Vec3(-1.0f, -1.0f, 0.0f);
	m_VertexList[2].p = Vec3(1.0f, 1.0f, 0.0f);
	m_VertexList[3].p = m_VertexList[2].p;
	m_VertexList[4].p = m_VertexList[1].p;
	m_VertexList[5].p = Vec3(1.0f, -1.0f, 0.0f);

	m_VertexList[0].t = Vec2(0.0f, 0.0f);
	m_VertexList[1].t = Vec2(1.0f, 0.0f);
	m_VertexList[2].t = Vec2(0.0f, 1.0f);
	m_VertexList[3].t = Vec2(0.0f, 1.0f);
	m_VertexList[4].t = Vec2(1.0f, 0.0f);
	m_VertexList[5].t = Vec2(1.0f, 1.0f);

	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	desc.ByteWidth = sizeof(Vertex) * m_VertexList.size();

	D3D11_SUBRESOURCE_DATA data;
	ZeroMemory(&data, sizeof(data));
	data.pSysMem = m_VertexList.data();

	HRESULT hr = m_Device->CreateBuffer(&desc, &data, m_VertexBuffer.GetAddressOf());

	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

bool PlaneObject::Frame()
{
	Matrix matScale, matRotation, matTranslate;
	matScale.CreateScale(m_Scale);
	matRotation.CreateRotationZ(m_Rotation.z);
	matTranslate.CreateTranslation(m_Postion);
	
	m_World = matScale * matRotation * matTranslate;

	return true;
}