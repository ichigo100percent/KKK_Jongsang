#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <math.h>


//�־��� �ּڰ��� �ִ� ������ ���� ���� �����ϱ� ���� ��ũ��
#define randstep(fmin, fmax) ((float)fmin+((float)fmax-(float)fmin)*rand() / RAND_MAX)

struct Point
{
	float x = 0.0f;
	float y = 0.0f;

	bool operator == (Point& p)
	{
		if (fabs(x - p.x) > 0.0001f)
		{
			if (fabs(y - p.y) > 0.0001f)
			{
				return true;
			}
		}
		return false;
	}

	bool operator != (Point& p)
	{
		return !(*this == p);
	}

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

	Point& operator /= (float fValue)
	{
		x = x / fValue;
		y = y / fValue;

		return *this;
	}

	float GetDistance()
	{
		float fDistnace = sqrt(x * x + y * y);

		return fDistnace;
	}

	static float GetDistance(Point& p)
	{
		float fDistance = sqrt(p.x * p.x + p.y * p.y);

		return fDistance;
	}

	Point(){}
	Point(float fx, float fy)
		:x(fx), y(fy)
	{

	}

};

struct Float2
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
	bool m_bEnable = true;

	float m_fWidth = 0.0f;
	float m_fHight = 0.0f;

	Point m_Point[4];
	Point m_Center;
	Point m_Half;
	Point m_Min;
	Point m_Max;
	Point v;
	Point s;


	//�� ���� �簢���� ��ġ���� �˻��ϰ� ��ġ�� ������ �����ϴ� �Լ�
	bool Intersect(Rect& p, Rect& ret)
	{
		return false;
	}

	//�� Rect ��ü�� ���� ������ ���ϴ� ������ �����ε�
	bool operator == (Rect& p)
	{
		if (fabs(m_fx - p.m_fx) > 0.0001f)
		{
			if (fabs(m_fy - p.m_fy) > 0.0001f)
			{
				if (fabs(m_fWidth - p.m_fWidth) > 0.0001f)
				{
					if (fabs(m_fHight - p.m_fHight) > 0.0001f)
					{
						//�� ������ 0.0001���� ũ�� ���̳��� �ٸ� ������ �Ǵ�
						return true;
					}
				}
			}
		}
		
		return false;
	}

	//�� rect ��ü�� �ٸ��� ���ϴ� ������ �����ε�
	bool operator != (Rect& p)
	{
		// == �������� �ݴ� ��� ��ȯ
		return !(*this == p);
	}

	//�� rect�� ��ģ ���ο� �簢���� ��ȯ�ϴ� ������ �����ε�
	Rect operator + (Rect& p)
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

	//�� rect�� ���� ��ġ�� ������ ������ ���ο� �簢���� ��ȯ�ϴ� ������ �����ε�
	Rect operator - (Rect& p)
	{
		Rect rt;
		rt.m_bEnable = false;
		if (ToRect(p))
		{
			float fx = (m_Min.x > p.m_Min.x) ? m_Min.x : p.m_Min.x;
			float fy = (m_Min.y > p.m_Min.y) ? m_Min.y : p.m_Min.y;
			float right = (m_Max.x < p.m_Max.x) ? m_Max.x : p.m_Max.x;
			float bottom = (m_Max.y < p.m_Max.y) ? m_Max.y : p.m_Max.y;
			rt.Set(fx, fy, right - fx, bottom - fy);
			rt.m_bEnable = true;
		}
		return rt;
	}

	//point�� ���� �簢���� ��ġ�� �̵���Ų ���ο� �簢���� ��ȯ�ϴ� ������ �����ε�
	Rect operator - (Point& p)
	{
		m_fx -= p.x;
		m_fy -= p.y;
		return Rect(m_fx, m_fy, m_fWidth, m_fHight);
	}

	Rect operator * (float fValue)
	{
		if (fValue <= 0.0f)
		{
			return *this;
		}

		m_fWidth *= fValue;
		m_fHight *= fValue;

		return Rect(m_fx, m_fy, m_fWidth, m_fHight);
	}

	Rect operator / (float fValue)
	{
		if (fValue <= 0.0f)
		{
			return *this;
		}
		m_fWidth /= fValue;
		m_fHight /= fValue;

		return Rect(m_fx, m_fy, m_fWidth, m_fHight);
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
		m_Point[1] = { m_fx + m_fWidth, m_fy };
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
		v = { fx, fh };
		s = { fw, fh };

		m_fx = fx;
		m_fy = fy;
		Set(fw, fh);
	}

	//�� ���� �簢���� ��ġ���� Ȯ���ϴ� �Լ�
	bool ToRect(Rect& rt)
	{
		Rect sum = (*this) + rt;
		float fX = m_fWidth + rt.m_fWidth;
		float fY = m_fHight + rt.m_fHight;

		if (sum.m_fWidth <= fX)
		{
			if (sum.m_fHight <= fY)
			{
				return true; //�� �簢���� ��ħ
			}
		}

		return false;
	}

	//�־��� point�� �簢�� �ȿ� �ִ��� Ȯ���ϴ� �Լ�
	bool ToPoint(Point& p)
	{
		if (m_Min.x <= p.x && m_Max.x >= p.x &&
			m_Min.y <= p.y && m_Max.y >= p.y)
		{
			return true; //���� �簢�� �ȿ� �ֽ�
		}
		return false;
	}

	Rect()
		:m_bEnable(true){}
	Rect(float fx, float fy, float fw, float fh)
	{
		m_bEnable = true;
		Set(fx, fy, fw, fh);
	}
};