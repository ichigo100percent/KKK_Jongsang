#pragma once
#include "Utils.h"

class Collision
{
public:
	static bool RectToRect(Rect& rt1, Rect& rt2)
	{
		//�� �簢���� ���ؼ� �ϳ��� ū �簢���� ����
		Rect sum = rt1 + rt2;

		//�� �簢���� �ʺ�� ������ ���� ���
		float fX = rt1.m_fWidth + rt2.m_fWidth;
		float fY = rt1.m_fHight + rt2.m_fHight;
		
		//������� ū �簢���� �ʺ�� ���̰� �� �簢���� �պ��� �۰ų� ������ �� �簢����
		//��ħ
		if (sum.m_fWidth <= fX)
		{
			if (sum.m_fHight <= fY)
			{
				//�浹����
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