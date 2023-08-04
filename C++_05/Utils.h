#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <math.h>

//#define randstep(fmin, fmax) ((float)fmin+(float)fmax-(float)fmin) * rand() / RAND_MAX)
#define randstep(fmin, fmax) ((float)fmin+((float)fmax-(float)fmin)*rand() / RAND_MAX)


struct Point
{
	float x;
	float y;

	Point operator +(Point& p)
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

	Point& operator /= (float fValue)
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

struct  Float2
{
	union 
	{
		struct 
		{
			float m_fx;
			float m_fy;
		};

		float v[2];
	};
};

struct Rect : Float2
{
	float m_fWidth;
	float m_fHight;

	Point m_Point[4];
	Point m_Center;
	Point m_Half;
	Point m_Min;
	Point m_Max;
	Point v;
	Point s;

	Rect operator +(Rect& p)
	{
		Rect rt;
		float fMinX = min(m_fx, p.m_fx);
		float fMinY = min(m_fy, p.m_fy);
		float fMaxX = max(m_Point[2].x, p.m_Point[2].x);
		float fMaxY = max(m_Point[2].y, p.m_Point[2].y);

		Point pos = { fMinX, fMinY };
		rt.Set(pos, fMaxX - fMinX, fMaxY - fMinY);

		return rt;
	}

	void Set(Point p)
	{
		v = { p.x, p.y };
		s = { m_fWidth, m_fHight };
		m_fx = m_fx;
		m_fy = m_fy;

		Set(m_fWidth, m_fHight);
	}

	void Set(float fw, float fh)
	{
		m_fWidth = fw;
		m_fHight = fh;
		m_Half = { m_fWidth * 0.5f, m_fHight * 0.5f };
		m_Point[0] = { m_fx, m_fy };
		m_Point[1] = { m_fx + m_fWidth , m_fy };
		m_Point[2] = { m_fx + m_fWidth, m_fy + m_fHight };
		m_Point[3] = { m_fx, m_fy + m_fHight };
		m_Center = (m_Point[0] + m_Point[2]) * 0.5f;
		m_Min = m_Point[0];
		m_Max = m_Point[2];
	}

	void Set(Point p, float fw, float fh)
	{
		v = { p.x, p.y };
		s = { fw, fh };
		m_fx = p.x;
		m_fy = p.y;
		Set(fw, fh);
	}

	void Set(float fx, float fy, float fw, float fh)
	{
		v = { fx, fy };
		s = { fw, fh };

		m_fx = fx;
		m_fy = fy;
		Set(fw, fh);
	}

	Rect()
	{

	}

	Rect(float _x, float _y, float _fw, float _fh)
	{
		Set(_x, _y, _fw, _fh);
	}
};