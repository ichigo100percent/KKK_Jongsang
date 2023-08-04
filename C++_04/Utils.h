#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <string>

#define randstep(fmin, fmax) ((float)fmin + ((float)fmax - (float)fmin) * rand() / RAND_MAX)

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

	Point& operator /=(float fValue)
	{
		x = x / fValue;
		y = y / fValue;

		return *this;
	}

	float GetDistance()
	{
		float fDistance = sqrt(x * x + y * y);

		return fDistance;
	}

	static float GetDistance(Point& p)
	{
		float fDistance = sqrt(p.x * p.x + p.y * p.y);

		return fDistance;
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
	float m_w;
	float m_h;

	Point m_Point[4];
	Point m_Center;
	Point m_Half;
	Point m_Min;
	Point m_Max;
	Point v;
	Point s;

	void Set(float fx, float fy, float fw, float fh)
	{
		v = { fx, fy };
		s = { fw, fh };

		m_fx = fx;
		m_fy = fy;
		m_w = fw;
		m_h = fh;


		m_Half = { m_w * 0.5f,m_h * 0.5f };
		m_Point[0] = { m_fx, m_fy };
		m_Point[1] = { m_fx + m_w, m_fy };
		m_Point[2] = { m_fx + m_w, m_fy + m_h };
		m_Point[3] = { m_fx, m_fy + m_h };
		m_Center = (m_Point[0] + m_Point[2]) * 0.5f;
		m_Min = m_Point[0];
		m_Max = m_Point[2];

	}

	Rect(){}
	Rect(float fx, float fy, float fw, float fh)
	{
		Set(fx, fy, fw, fh);
	}
};