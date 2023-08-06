#include "Object.h"

void   Object2D::SetRect(Vector2& c, float w, float h)
{
	m_tRT.Set(c, w, h);
}
void	TDynamicObject2D::SetTarget(Vector2& t)
{
	m_Target = t;
	// ���� = ������ ��ġ - ���� ��ġ
	m_Direction = t - m_Position;
	// �������͸� ��� ���ؼ� ���⺤���� ũ�⸦ ��´�.
	float fDistance = m_Direction.Length();
	// ����ȭ �۾�
	m_Direction /= fDistance;
}

void			TDynamicObject2D::Move(float fSecond)
{
	Vector2 vDir = m_Target - m_Position;
	float fD = vDir.Length();
	//	// �ð��� ����ȭ
	Vector2 vVelocity = m_Direction * m_fSpeed * fSecond;
	m_Position = m_Position + vVelocity;
	m_tRT.Set(m_Position, m_tRT.m_fWidth, m_tRT.m_fHeight);
	//if (fD > 5.0f)
	//{
	//	// �ð��� ����ȭ
	//	TVector2 vVelocity = m_Direction * m_fSpeed * fSecond;
	//	m_Position = m_Position + vVelocity;
	//	m_Position.x = max(m_Position.x, 0.0f);
	//	m_Position.y = max(m_Position.y, 0.0f);
	//	m_Position.x = min(m_Position.x, 800.0f);
	//	m_Position.y = min(m_Position.y, 600.0f);
	//}
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

	if (m_Position.x > 800.0f)
	{
		m_Direction.x *= -1.0f;
		m_Position.x = 800.0f;
	}
	if (m_Position.y > 600.0f)
	{
		m_Direction.y *= -1.0f;
		m_Position.y = 600.0f;
	}
};
TDynamicObject2D::TDynamicObject2D()
{
	m_Direction.x = 0.0f;
	m_Direction.y = 0.0f;
}


void   Object3D::SetBox(Vector3& c, float w, float h, float z)
{
	m_tBox.Set(c, w, h, z);
}
void	DynamicObject3D::SetTarget(Vector3& t)
{
	m_Target = t;
	// ���� = ������ ��ġ - ���� ��ġ
	m_Direction = t - m_Position;
	// �������͸� ��� ���ؼ� ���⺤���� ũ�⸦ ��´�.
	float fDistance = m_Direction.Length();
	// ����ȭ �۾�
	m_Direction /= fDistance;
}
void			DynamicObject3D::Move(float fSecond)
{
	Vector3 vDir = m_Target - m_Position;
	float fD = vDir.Length();
	//	// �ð��� ����ȭ
	Vector3 vVelocity = m_Direction * m_fSpeed * fSecond;
	m_Position = m_Position + vVelocity;
	m_tBox.Set(m_Position, m_tBox.m_fWidth, m_tBox.m_fHeight, m_tBox.m_fDepth);
	//if (fD > 5.0f)
	//{
	//	// �ð��� ����ȭ
	//	TVector2 vVelocity = m_Direction * m_fSpeed * fSecond;
	//	m_Position = m_Position + vVelocity;
	//	m_Position.x = max(m_Position.x, 0.0f);
	//	m_Position.y = max(m_Position.y, 0.0f);
	//	m_Position.x = min(m_Position.x, 800.0f);
	//	m_Position.y = min(m_Position.y, 600.0f);
	//}
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
	if (m_Position.z < 0.0f)
	{
		m_Direction.z *= -1.0f;
		m_Position.z = 0.0f;
	}

	if (m_Position.x > 800.0f)
	{
		m_Direction.x *= -1.0f;
		m_Position.x = 800.0f;
	}
	if (m_Position.y > 600.0f)
	{
		m_Direction.y *= -1.0f;
		m_Position.y = 600.0f;
	}
	if (m_Position.z > 600.0f)
	{
		m_Direction.z *= -1.0f;
		m_Position.z = 600.0f;
	}

};
DynamicObject3D::DynamicObject3D()
{
	m_Direction.x = 0.0f;
	m_Direction.y = 0.0f;
	m_Direction.z = 0.0f;
}