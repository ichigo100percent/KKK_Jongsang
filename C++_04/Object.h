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

		//���� = ������ ��ġ - ���� ��ġ
		m_Direction = t - m_Position;

		//�������͸� ��� ���ؼ� ���⺤���� ũ�⸦ ��´�.
		float fDistance = m_Direction.GetDistance();

		//����ȭ �۾�(ũ�Ⱑ 1�� ���� ���ͷ� ��ȯ)
		//*���� ���ҷ���
		m_Direction /= fDistance;
	}

	void Move()
	{
		//���� ��ġ���� �̵� ��ǥ������ ���� ���͸� ����մϴ�.
		Point vDir = m_Target - m_Position;

		//���� ��ġ���� �̵� ��ǥ������ �Ÿ��� ����մϴ�.
		float fD = vDir.GetDistance();

		//�̵� ��ǥ���� �Ÿ��� 50.0.f���� ũ�ٸ� �̵��� �����մϴ�.
		if (fD > 50.0f)
		{
			//�̵� ���� ���Ϳ� �̵� �ӵ��� ���Ͽ� �̵� �ӵ� ���͸� ����ϴ�.
			Point vVelocity = m_Direction * m_fSpeed;

			//���� ��ġ�� �̵� �ӵ� ���͸� ���������ν� ��ü�� �̵���ŵ�ϴ�.
			m_Position = m_Position + vVelocity;
		}
	}

	//������: ��ü�� �̵� ���� �ʱ�ȭ
	DynamicObject()
	{
		m_Direction.x = 0.0f;
		m_Direction.y = 0.0f;
	}
};