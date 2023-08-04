#pragma once
#include "Collision.h"

class Object
{
public:
	std::wstring m_csName;
	Point m_Position;
	virtual void Move() {};
	virtual void SetTarget(Point& t) {};

};

class StaticObject : public Object
{
public:
	void Move() {};
};

class DynamicObject : public Object
{
public:
	float m_fSpeed = 30.0f;
	Point m_Direction;
	Point m_Target;

	void SetTarget(Point& t)
	{
		m_Target = t;

		//방향 = 목적지 위치 - 현재 위치
		m_Direction = t - m_Position;

		//단위벡터를 얻기 위해서 방향벡터의 크기를 얻는다.
		float fDistance = m_Direction.GetDistance();

		//정규화 작업(크기가 1인 단위 벡터로 변환)
		//*방향 구할려고
		m_Direction /= fDistance;
	}

	void Move()
	{
		//현재 위치에서 이동 목표까지의 방향 벡터를 계산합니다.
		Point vDir = m_Target - m_Position;

		//현재 위치에서 이동 목표까지의 거리를 계산합니다.
		float fD = vDir.GetDistance();

		//이동 목표와의 거리가 50.0.f보다 크다면 이동을 진행합니다.
		if (fD > 50.0f)
		{
			//이동 방향 벡터에 이동 속도를 곱하여 이동 속도 벡터를 얻습니다.
			Point vVelocity = m_Direction * m_fSpeed;

			//현재 위치에 이동 속도 벡터를 더해줌으로써 객체를 이동시킵니다.
			m_Position = m_Position + vVelocity;
		}
	}

	//생성자: 객체의 이동 방향 초기화
	DynamicObject()
	{
		m_Direction.x = 0.0f;
		m_Direction.y = 0.0f;
	}
};