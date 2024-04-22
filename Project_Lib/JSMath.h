#pragma once
#include <cmath>


namespace J::math
{

#define PI 3.141592f
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))


	static float ConvertDegree(float radian) { return (radian * (180 / PI)); }

	struct Vector2
	{
		static Vector2 Rotate(Vector2 _vector, float _degree)
		{
			float radian = (_degree / 180.f) * PI;
			_vector.normalize();
			float x = cosf(radian) * _vector.x - sinf(radian) * _vector.y;
			float y = sinf(radian) * _vector.x + cosf(radian) * _vector.y;

			return Vector2(x, y);
		}

		static float Dot(Vector2& v1, Vector2& v2)
		{
			return v1.x * v2.x + v1.y * v2.y;
		}

		static float Cross(Vector2& v1, Vector2& v2)
		{
			return v1.x * v2.y - v1.y * v2.x;
		}

		static Vector2 One;
		static Vector2 Zero;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;

		float x;
		float y;

		Vector2()
			: x(0.0f)
			, y(0.0f)
		{

		}

		Vector2(float _x, float _y)
			: x(_x)
			, y(_y)
		{

		}

		Vector2 operator-()
		{
			return Vector2(-x, -y);
		}

		Vector2 operator+(Vector2 other)
		{
			return Vector2(x + other.x, y + other.y);
		}

		void operator+=(Vector2 other)
		{
			x += other.x;
			y += other.y;
		}

		void operator-=(Vector2 other)
		{
			x -= other.x;
			y -= other.y;
		}

		void operator*=(Vector2 other)
		{
			x *= other.x;
			y *= other.y;
		}

		void operator*=(float value)
		{
			x *= value;
			y *= value;
		}

		Vector2 operator-(Vector2 other)
		{
			return Vector2(x - other.x, y - other.y);
		}
		Vector2 operator/(float value)
		{
			return Vector2(x / value, y / value);
		}

		Vector2 operator*(float value)
		{
			return Vector2(x * value, y * value);
		}

		Vector2 operator*(Vector2 v)
		{
			return Vector2(x * v.x, y * v.y);
		}

		bool operator==(Vector2 v)
		{
			return (x == v.x) && (y == v.y);
		}

		void clear()
		{
			x = 0.0f;
			y = 0.0f;
		}

		float length()
		{
			return sqrtf(x * x + y * y);
		}

		//float magnitude(Vector2 vec)
		//{
		//	return sqrt(vec.x * vec.x + vec.y * vec.y);
		//}

		Vector2 normalize()
		{
			float len = length();
			x /= len;
			y /= len;

			return *this;
		}
	};

	struct JRect
	{
		JRect();
		JRect(float _x, float _y, float _w, float _h);

		void	Set(Vector2 _p);
		void	Set(float _w, float _h);
		void	Set(Vector2 _p, float _w, float _h);
		void	Set(float _x, float _y, float _w, float _h);
		bool	Intersect(JRect& _result, JRect& _r1, JRect& _r2);

		bool	ToRect(JRect& _rt);
		bool	ToPoint(Vector2& _p);

		JRect	operator+(JRect& _rt);
		JRect	operator-(JRect& _rt);
		JRect	operator-(Vector2& _p);
		JRect	operator*(float _value);
		JRect	operator/(float _value);

		bool	m_bEnable = true;
		float	m_Width = 0.0f;
		float	m_Height = 0.0f;
		Vector2 m_Point[4];
		Vector2	m_Center;
		Vector2 m_Half;
		Vector2	m_Min;
		Vector2 m_Max;
		Vector2	v;
		Vector2	s;
	};
}
