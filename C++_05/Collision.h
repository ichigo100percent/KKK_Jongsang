#pragma once
#include "Utils.h"

class Collision
{
public:

	//사각형과 사각형의 충돌 검사 함수
	static bool RectToRect(Rect& rt1, Rect& rt2)
	{
		//두 사각형을 합친 사각형을 계산
		Rect sum = rt1 + rt2;
		float fX = rt1.m_fWidth + rt2.m_fWidth;
		float fY = rt1.m_fHight + rt2.m_fHight;

		//합친 사각형의 너비와 높이를 비교하여 충돌 여부 판단
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