#pragma once
#include "Utils.h"

class Collision
{
public:
	static bool RectToRect(Rect& rt1, Rect& rt2)
	{
		//두 사각형을 더해서 하나의 큰 사각형을 만듦
		Rect sum = rt1 + rt2;

		//두 사각형의 너비와 높이의 합을 계산
		float fX = rt1.m_fWidth + rt2.m_fWidth;
		float fY = rt1.m_fHight + rt2.m_fHight;
		
		//만들어진 큰 사각형의 너비와 높이가 두 사각형의 합보다 작거나 같으면 두 사각형은
		//겹침
		if (sum.m_fWidth <= fX)
		{
			if (sum.m_fHight <= fY)
			{
				//충돌했음
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