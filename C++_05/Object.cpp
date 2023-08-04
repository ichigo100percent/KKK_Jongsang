#include "Object.h"

void Object::SetRect(Point& c, float w, float h)
{
	m_rt.Set(c, w, h);
}

void DynamicObject::SetTarget(Point& t)
{
	m_Target = t;
	//방향 = 목적지 위치 - 현재 위치
	m_Direction = t - m_Position;
	//단위 벡터를 얻기 위해서 방향 벡터의 크기를 얻는다.
	float fDistance = m_Direction.GetDistance();
	//정규화 작업
	m_Direction /= fDistance;
}

void DynamicObject::Move(float fSecond)
{
	Point vDir = m_Target - m_Position;
	float fD = vDir.GetDistance();

	Point vVelocity = m_Direction * m_fSpeed * fSecond;
	m_Position = m_Position + vVelocity;
	m_rt.Set(m_Position, m_rt.m_fWidth, m_rt.m_fHight);

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
}

DynamicObject::DynamicObject()
{
	m_Direction.x = 0.0f;
	m_Direction.y = 0.0f;
}