#pragma once
#include "Utils.h"

class Collision
{
public:
	static bool RectToRect(Rect& rt1, Rect& rt2)
	{
		Rect sum = rt1 + rt2;
		float fX = rt1.m_fWidth + rt2.m_fWidth;
		float fY = rt1.m_fHeight + rt2.m_fHeight;
		if (sum.m_fWidth <= fX)
		{
			if (sum.m_fHeight <= fY)
			{
				return true;
			}
		}
		return false;
	}
	static bool RectToPoint(Rect& rt, Vector2& p)
	{
		if (rt.m_Min.x <= p.x && rt.m_Max.x >= p.x
			&&
			rt.m_Min.y <= p.y && rt.m_Max.y >= p.y)
		{
			return true;
		}
		return false;
	}
	static bool BoxToBox(Box& rt1, Box& rt2)
	{
		Box sum = rt1 + rt2;
		float fX = rt1.m_fWidth + rt2.m_fWidth;
		float fY = rt1.m_fHeight + rt2.m_fHeight;
		float fZ = rt1.m_fDepth + rt2.m_fDepth;
		if (sum.m_fWidth <= fX)
		{
			if (sum.m_fHeight <= fY)
			{
				if (sum.m_fDepth <= fZ)
				{
					return true;
				}
			}
		}
		return false;
	}
	static bool BoxToPoint(Box& rt, Vector3& p)
	{
		if (rt.m_Min.x <= p.x && rt.m_Max.x >= p.x
			&&
			rt.m_Min.y <= p.y && rt.m_Max.y >= p.y
			&&
			rt.m_Min.z <= p.z && rt.m_Max.z >= p.z)
		{
			return true;
		}
		return false;
	}
};