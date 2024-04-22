#include "JSMath.h"

namespace J::math
{
	Vector2 Vector2::One = Vector2(1.0f, 1.0f);
	Vector2 Vector2::Zero = Vector2(0.0f, 0.0f);
	Vector2 Vector2::Right = Vector2(1.0f, 0.0f);
	Vector2 Vector2::Left = Vector2(-1.0f, 0.0f);
	Vector2 Vector2::Up = Vector2(0.0f, -1.0f);
	Vector2 Vector2::Down = Vector2(0.0f, 1.0f);


	JRect::JRect()
		: m_bEnable(true)
	{
	}

	JRect::JRect(float _x, float _y, float _w, float _h)
	{
		m_bEnable = true;
		Set(_x, _y, _w, _h);
	}

	void JRect::Set(Vector2 _p)
	{
		v = { _p.x , _p.y };
		s = { m_Width, m_Height };
		Set(m_Width, m_Height);
	}

	void JRect::Set(float _w, float _h)
	{
		m_Width = _w;
		m_Height = _h;
		m_Half = { m_Width / 2.0f, m_Height / 2.0f };
		m_Point[0] = { v.x , v.y };
		m_Point[1] = { v.x + m_Width , v.y };
		m_Point[2] = { v.x + m_Width, v.y + m_Height };
		m_Point[3] = { v.x, v.y + m_Height };
		m_Center = (m_Point[0] + m_Point[2]) / 2.0f;
		m_Min = m_Point[0];
		m_Max = m_Point[2];
	}

	void JRect::Set(Vector2 _p, float _w, float _h)
	{
		v = _p;
		s = { _w, _h };
		Set(_w, _h);
	}

	void JRect::Set(float _x, float _y, float _w, float _h)
	{
		v = { _x, _y };
		s = { _w, _h };
		Set(_w, _h);
	}

	bool JRect::Intersect(JRect& _result, JRect& _r1, JRect& _r2)
	{
		return false;
	}

	bool JRect::ToRect(JRect& _rt)
	{
		JRect sum = (*this) + _rt;
		float x = m_Width + _rt.m_Width;
		float y = m_Height + _rt.m_Height;

		if (sum.m_Width <= x)
		{
			if (sum.m_Height <= y)
			{
				return true;
			}
		}
		return false;
	}

	bool JRect::ToPoint(Vector2& _p)
	{
		if (m_Min.x <= _p.x && m_Max.y >= _p.x &&
			m_Min.y <= _p.y && m_Max.y >= _p.y)
		{
			return true;
		}
		return false;
	}

	JRect JRect::operator+(JRect& _rt)
	{
		JRect rt;
		float MinX = min(v.x, _rt.v.x);
		float MinY = min(v.y, _rt.v.y);
		float MaxX = max(m_Point[2].x, _rt.m_Point[2].x);
		float MaxY = max(m_Point[2].y, _rt.m_Point[2].y);
		Vector2 pos = { MinX, MinY };
		rt.Set(pos, MaxX - MinX, MaxY - MinY);
		return rt;
	}

	JRect JRect::operator-(JRect& _rt)
	{
		JRect rt;
		rt.m_bEnable = false;

		if (ToRect(_rt))
		{
			float x = (m_Min.x > _rt.m_Min.x) ? m_Min.x : _rt.m_Min.x;
			float y = (m_Min.y > _rt.m_Min.y) ? m_Min.y : _rt.m_Min.y;
			float top = (m_Max.x < _rt.m_Max.x) ? m_Max.x : _rt.m_Max.x;
			float bottom = (m_Max.y < _rt.m_Max.y) ? m_Max.y : _rt.m_Max.y;
			rt.Set(x, y, top - x, bottom - y);
			rt.m_bEnable = true;
		}
		return rt;
	}

	JRect JRect::operator-(Vector2& _p)
	{
		return JRect();
	}

	JRect JRect::operator*(float _value)
	{
		return JRect();
	}

	JRect JRect::operator/(float _value)
	{
		return JRect();
	}

}