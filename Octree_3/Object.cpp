#include "Object.h"

void Object3D::SetBox(Vector3& c, float w, float h, float z)
{
	m_Box.Set(c, w, h, z);
}

void DynamicObject3D::SetTarget(Vector3& t)
{
	m_Target = t;

	//방향 = 목적지 위치 - 현재 위치
	m_Direction = t - m_Position;

	float fDistance = m_Direction.Length();
	//정규화 작업
	m_Direction /= fDistance;
}

void DynamicObject3D::Move(float fSecond)
{
	Vector3 vDir = m_Target - m_Position;
	float fD = vDir.Length();

	// 시간의 동기화
	Vector3 vVelocity = m_Direction * m_fSpeed * fSecond;
	m_Position = m_Position + vVelocity;
	m_Box.Set(m_Position, m_Box.m_fWidth, m_Box.m_fHeight, m_Box.m_fDepth);

	if (m_Position.x < 0.0f)
	{
		m_Direction.x *= -1.0f;
		m_Position.x = 0.0f;
	}
	if (m_Position.y < 0.0f)
	{
		m_Direction.y *= -1.0f;
		m_Position.y = 0.0f;
	}
	if (m_Position.z < -g_fMapSize * 0.5f)
	{
		m_Direction.z *= -1.0f;
		m_Position.z = -g_fMapSize * 0.5f;
	}

	if (m_Position.x > g_fMapSize * 0.5f)
	{
		m_Direction.x *= -1.0f;
		m_Position.x = g_fMapSize * 0.5f;
	}
	if (m_Position.y > g_fMapSize * 0.5f)
	{
		m_Direction.y *= -1.0f;
		m_Position.y = g_fMapSize * 0.5f;
	}
	if (m_Position.z > g_fMapSize * 0.5f)
	{
		m_Direction.z *= -1.0f;
		m_Position.z = g_fMapSize * 0.5f;
	}
}

DynamicObject3D::DynamicObject3D()
{
	m_Direction.x = 0.0f;
	m_Direction.y = 0.0f;
	m_Direction.z = 0.0f;
}