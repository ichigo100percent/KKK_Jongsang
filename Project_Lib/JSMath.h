#pragma once
//#include <cmath>


namespace J::math
{
	struct Vector2
	{
		static Vector2 One;
		static Vector2 Zero;

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

		Vector2 operator+ (Vector2 _other)
		{
			return Vector2(x + _other.x, y + _other.y);
		}

		Vector2 operator- (Vector2 _other)
		{
			return Vector2(x - _other.x, y - _other.y);
		}

		Vector2 operator* (float _value)
		{
			return Vector2(x * _value, y * _value);
		}

		Vector2 operator/ (float _value)
		{
			return Vector2(x / _value, y / _value);
		}
	};
}
