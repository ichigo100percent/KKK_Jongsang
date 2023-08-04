#include "Object.h"

void Object3D::setBox(Vector3& c, float w, float h, float z)
{
	m_Box.Set(c, w, h, z);
}

void DynamicObject3D::SetTarget(Vector3& t)
{
	m_Target = t;

	//방향 = 목적지 위치 - 현재 위치
	m_Direction = t - m_position;

	float fDistance = m_Direction.Length();
	//정규화 작업
	m_Direction /= fDistance;
}

void DynamicObject3D::Move(float fSecond)
{
	Vector3 vDir = m_Target - m_position;
	float fD = vDir.Length();

	// 시간의 동기화
	Vector3 vVelocity = m_Direction * m_fSpeed * fSecond;
	m_position = m_position + vVelocity;
	m_Box.Set(m_position, m_Box.m_fWidth, m_Box.m_fHeight, m_Box.m_fDepth);

	if (m_position.x < 0.0f)
	{
		m_Direction.x *= -1.0f;
		m_position.x = 0.0f;
	}
	if (m_position.y < 0.0f)
	{
		m_Direction.y *= -1.0f;
		m_position.y = 0.0f;
	}
	if (m_position.z < -g_fMapSize * 0.5f)
	{
		m_Direction.z *= -1.0f;
		m_position.z = -g_fMapSize * 0.5f;
	}

	if (m_position.x > g_fMapSize * 0.5f)
	{
		m_Direction.x *= -1.0f;
		m_position.x = g_fMapSize * 0.5f;
	}
	if (m_position.y > g_fMapSize * 0.5f)
	{
		m_Direction.y *= -1.0f;
		m_position.y = g_fMapSize * 0.5f;
	}
	if (m_position.z > g_fMapSize * 0.5f)
	{
		m_Direction.z *= -1.0f;
		m_position.z = g_fMapSize * 0.5f;
	}
}