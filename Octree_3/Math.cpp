#include "Math.h"

bool Vector2::operator == (Vector2& p)
{
	if (fabs(x - p.x) > EPSILON)
	{
		if (fabs(y - p.y) > EPSILON)
		{
			return true;
		}
	}
	return false;
}

bool Vector2::operator != (Vector2& p)
{
	return !(*this == p);
}

Vector2 Vector2::operator+ (Vector2& p)
{
	return Vector2(x + p.x, y + p.y);
}

Vector2 Vector2::operator- (Vector2& p)
{
	return Vector2(x - p.x, y - p.y);
}

Vector2 Vector2::operator * (float fValue)
{
	return Vector2(x * fValue, y * fValue);
}

Vector2 Vector2:: operator / (float fValue)
{
	return Vector2(x / fValue, y / fValue);
}

Vector2& Vector2:: operator /= (float fValue)
{
	x = x / fValue;
	y = y / fValue;
	return *this;
}

float Vector2::Length()
{
	float fDistance = sqrt(x * x + y * y);
	return fDistance;
}

static float Length(Vector2& p)
{
	float fDistance = sqrt(p.x * p.x + p.y + p.y);
}

Vector2::Vector2(){}
Vector2::Vector2(float fx, float fy)
{
	x = fx;
	y = fy;
}

//�� ������ ������ ����ϴ� �Լ�
float Vector3::operator | (Vector3 const& v)
{
	return x * v.x + y * v.y + z * v.z;
}

//�� ������ ������ ����ϴ� �Լ�
Vector3 Vector3::operator ^ (Vector3 const& v)
{
	return Vector3(y * v.z - z * v.y,
				   z * v.x - x * v.z,
				   x * v.y - y * v.x);
}

bool Vector3::operator == (Vector3& p)
{
	if (fabs(x - p.x) > EPSILON)
	{
		if (fabs(y - p.y) > EPSILON)
		{
			if (fabs(z - p.z) > EPSILON)
			{
				return true;
			}
		}
	}
	return false;
}

bool Vector3::operator != (Vector3& p)
{
	return !(*this == p);
}

Vector3 Vector3::operator + (Vector3& p)
{
	return Vector3(x + p.x, y + p.y, z + p.z);
}

Vector3 Vector3::operator - (Vector3& p)
{
	return Vector3(x - p.x, y - p.y, z - p.z);
}

Vector3 Vector3::operator * (float fValue)
{
	return Vector3(x * fValue, y * fValue, z * fValue);
}

Vector3 Vector3::operator / (float fValue)
{
	return Vector3(x / fValue, y / fValue, z / fValue);
}

Vector3& Vector3::operator /= (float fValue)
{
	x = x / fValue;
	y = y / fValue;
	z = z / fValue;
	return *this;
}

float Vector3::Length()
{
	float fDistance = sqrt(x * x + y * y + z * z);
	return fDistance;
}

static float GetDistance(Vector3& p)
{
	float fDistance = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	return fDistance;
}

//������ ����ȭ�ϴ� �Լ�
void Vector3::Normalize()
{
	float fInvertLength = 1.0f / Length();
	x = x * fInvertLength;
	y = y * fInvertLength;
	z = z * fInvertLength;
}

//������ ���� ����(����ȭ�� ����)�� ��ȯ�ϴ� �Լ�
Vector3 Vector3::NormalVector()
{
	float fInvertLength = 1.0f / Length();
	return (*this) * fInvertLength;
}

//��
//�� ���� ������ ������ ����ϴ� �Լ�
float Vector3::Angle(Vector3& v)
{
	Vector3 a = NormalVector();
	Vector3 b = v.NormalVector();
	float fCosAngle = a | b;
	//���� ���� ���ﰢ�Լ��� acos�� �̿��� �������� ��ȯ�Ѵ�.
	float fRadian = acos(fCosAngle);
	//���� ���� ������ ��ȯ�Ͽ� ��ȯ�Ѵ�.
	float fDegree = RadianToDegree(fRadian);
	return fDegree;
}

Vector3::Vector3(){}
Vector3::Vector3(float fx, float fy, float fz)
{
	x = fx;
	y = fy;
	z = fz;
}

