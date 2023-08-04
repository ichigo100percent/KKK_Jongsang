#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct Point
{
	float x;
	float y;

	Point operator + (Point& p)
	{
		return Point(x + p.x, y + p.y);
	}

	Point operator - (Point& p)
	{
		return Point(x - p.x, y - p.y);
	}

	Point operator * (float fValue)
	{
		return Point(x * fValue, y * fValue);
	}

	Point operator / (float fValue)
	{
		return Point(x / fValue, y / fValue);
	}

	Point()
	{

	}
	Point(float _x, float _y)
		:x(_x), y(_y)
	{

	}
};


struct Rect
{
	float m_fx;
	float m_fy;
	float m_fWidth;
	float m_fHeight;

	Point m_Point[4];
	Point m_Center;
	Point m_Half;
	Point m_Min;
	Point m_Max;
	Point v;
	Point s;

	void Set(float _x, float _y, float _w, float _h)
	{
		v = { _x, _y };
		s = { _w, _h };

		m_fx = _x;
		m_fy = _y;
		m_fWidth = _w;
		m_fHeight = _h;
		m_Half = { m_fWidth * 0.5f, m_fHeight * 0.5f };
		m_Point[0] = { m_fx, m_fy };
		m_Point[1] = { m_fx + m_fWidth, m_fy };
		m_Point[2] = { m_fx + m_fWidth, m_fy + m_fHeight };
		m_Point[3] = { m_fx, m_fy + m_fHeight };
		m_Center = (m_Point[0] + m_Point[2]) * 0.5f;
		m_Min = m_Point[0];
		m_Max = m_Point[2];
	}

	Rect()
	{

	}
	Rect(float _x, float _y, float _w, float _h)
	{
		Set(_x, _y, _w, _h);
	}
};