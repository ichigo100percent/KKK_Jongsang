#pragma once
#include "Utils.h"

class Collsion
{
public:
	static bool RectToPoint(Rect& rt, Point& p)
	{
		if (rt.m_Min.x <= p.x && rt.m_Max.x >= p.x
			&&
			rt.m_Min.y <= p.y && rt.m_Min.y >= p.y)
		{
			return true;
		}

		return false;
	}
};