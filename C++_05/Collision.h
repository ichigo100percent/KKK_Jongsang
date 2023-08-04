#pragma once
#include "Utils.h"

class Collision
{
public:

	//�簢���� �簢���� �浹 �˻� �Լ�
	static bool RectToRect(Rect& rt1, Rect& rt2)
	{
		//�� �簢���� ��ģ �簢���� ���
		Rect sum = rt1 + rt2;
		float fX = rt1.m_fWidth + rt2.m_fWidth;
		float fY = rt1.m_fHight + rt2.m_fHight;

		//��ģ �簢���� �ʺ�� ���̸� ���Ͽ� �浹 ���� �Ǵ�
		if (sum.m_fWidth <= fX)
		{
			if (sum.m_fHight <= fY)
			{
				return true;
			}
		}
		return false;
	}

	static bool RectToPoint(Rect& rt, Point& p)
	{
		if (rt.m_Min.x <= p.x && rt.m_Max.x >= p.x
			&&
			rt.m_Min.y <= p.y && rt.m_Max.y >= p.y)
		{
			return true;
		}
		return false;
	}
};