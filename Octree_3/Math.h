#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <math.h>

#define PI (3.141592f)
#define EPSILON (0.0001f)
#define RadianToDegree(radian) ( radian *( 180.0f / PI))
#define DegreeToRadian(degree) ( degree *(PI / 180.0f))
#define randstep(fmin, fmax) ((float)fmin+((float)fmax-(float)fmin)*rand() / RAND_MAX)

struct Float2
{
	union 
	{
		struct
		{
			float x;
			float y;
		};
		float v[2];
	};
};

struct Float3
{
	union 
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		float v[3];
	};
};

struct Float4
{
	union 
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		float v[4];
	};
};

struct Float4x4
{
	union 
	{
		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4];
	};
};

class Vector2 : public Float2
{
public:
	bool operator == (Vector2& p);
	bool operator != (Vector2& p);
	Vector2 operator + (Vector2& p);
	Vector2 operator - (Vector2& p);
	Vector2 operator * (float fValue);
	Vector2 operator / (float fValue);
	Vector2& operator /= (float fValue);
	
public:
	float Length();
	static float Length(Vector2& p);
	
public:
	Vector2();
	Vector2(float fx, float fy);
};

class Vector3 : public Float3
{
public:
	float operator | (Vector3 const& v);
	Vector3 operator ^ (Vector3 const& v);
	bool operator == (Vector3& p);
	bool operator != (Vector3& p);
	Vector3 operator + (Vector3& p);
	Vector3 operator - (Vector3& p);
	Vector3 operator * (float fValue);
	Vector3 operator / (float fValue);
	Vector3& operator /= (float fValue);
	float Angle(Vector3& v);

public:
	float Length();
	void Normalize();
	Vector3 NormalVector();

public:
	static float GetDistance(Vector3& p);

public:
	Vector3();
	Vector3(float fx, float fy, float fz);
};

class Vector4 :public Float4
{
public:
	Vector4()
	{
		x = y = z = w = 0.0f;
	}
	Vector4(float fx, float fy, float fz, float fw)
	{
		x = fx;
		y = fy;
		z = fz;
		w = fw;
	}
};

//★
//직선과 한점의 거리
class Ray
{
public:
	//직선과 시작점을 나타내는 벡터
	Vector3 vPosition;
	//직선과 방향을 나타내는 벡터
	Vector3 vDirection;

	//한 점과 직선 사이의 거리를 계산하는 함수
	float GetDistance(Vector3& p0)
	{
		//직선 위의 한 점과 주어진 점 p 사이의 벡터를 구함
		Vector3 v = p0 - vPosition;

		//직선 방향 벡터와 v벡터의 내적을 구함
		//내적은 두 벡터의 유사도를 나타내며, 크기가 작을수록 두 벡터가 직교에 가깝고,
		//크기가 클수록 두 벡터가 평행에 가깝다.
		//k는 주어진 점 p가 직선 위의 어떤 위치에 있는지 나타내는 비례 상수
		float k = ((v | vDirection) / (vDirection | vDirection));

		//직선 위의 한 점을 구하기 위해 직선 방향 벡터에 k를 곱함
		Vector3 p = vDirection * k;

		//한 점과 직선 사이의 거리 벡터 w를 구함
		Vector3 w = v - p;

		//w 벡터의 길이를 계산하여 한 점과 직선 사이의 거리를 구함
		return w.Length();
	}
	Ray() {};
	Ray(Vector3 p, Vector3 d)
	{
		vPosition = p;
		vDirection = d;
	}
};

//평면과 한점의 거리
class Plane
{
public:
	//평면 위의 한 점을 나타내는 벡터 Pos
	Vector3 vPos;
	//평면의 법선 벡터를 나타내는 벡터 Nor;
	Vector3 vNor;
	float a, b, c, d;

	float GetDistance(Vector3& v)
	{
		return a * v.x + b * v.y + c * v.z + d;
	}

	Plane() {};

	//시작점과 법선 벡터를 지정하는 생성자
	Plane(Vector3 vP, Vector3 vD)
	{
		//법선 벡터를 정규화하여 Nor에 저장
		vNor = vD.NormalVector();
		//평면 위의 한 점을 Pos에 저장
		vPos = vP;
		a = vNor.x;
		b = vNor.y;
		c = vNor.z;
		d = -(vNor | vPos);
	}

	//세 점으로 평면을 정의하는 생성자
	//주의: 세 점은 시계 방향으로 구성되어 있어야함
	//p0, p1, p2의 순서가 시계방향으로 구성되어야 올바른 평면이 정의됨
	Plane(Vector3 p0, Vector3 p1, Vector3 p2)
	{
		vPos = p0;
		Vector3 e1 = p1 - p0;
		Vector3 e2 = p2 - p0;
		vNor = (e1 ^ e2).NormalVector();
		a = vNor.x;
		b = vNor.y;
		c = vNor.z;
		d = -(vNor | vPos);
	}
};

class Matrix :public Float4x4
{
public:
	Matrix()
	{
		//생성자 호출 시 단위 행렬로 초기화
		identity();
	}

	//단위 행렬로 초기화하는 메소드
	void identity()
	{
		_11 = _12 = _13 = _14 = 0.0f;
		_21 = _22 = _23 = _24 = 0.0f;
		_31 = _32 = _33 = _34 = 0.0f;
		_41 = _42 = _43 = _44 = 0.0f;
		_11 = _22 = _33 = _44 = 1.0f;
	}

	Matrix operator * (Matrix const& matrix)
	{
		Matrix ret;
		for (int iColumn = 0; iColumn < 4; iColumn++)
		{
			for (int iRow = 0; iRow < 4; iRow++)
			{
				ret.m[iRow][iColumn] =
					m[iRow][0] * matrix.m[0][iColumn] +
					m[iRow][1] * matrix.m[1][iColumn] +
					m[iRow][2] * matrix.m[2][iColumn] +
					m[iRow][3] * matrix.m[3][iColumn];
			}
		}
		return ret;
	}
	
	Vector3 operator * (Vector3 const& v)
	{
		Vector4 ret;
		ret.w = 1.0f;
		ret.x = v.x * _11 + v.y * _21 + v.z * _31 + 1.0f * _41;
		ret.y = v.x * _12 + v.y * _22 + v.z * _32 + 1.0f * _42;
		ret.z = v.x * _13 + v.y * _23 + v.z * _33 + 1.0f * _43;
		ret.w = v.x * _14 + v.y * _24 + v.z * _34 + 1.0f * _44;
		
		return Vector3(ret.x, ret.y, ret.z);
	}

	float operator () (int iRow, int iCol) const
	{
		return m[iRow][iCol];
	}

	float& operator () (int iRow, int iCol)
	{
		return m[iRow][iCol];
	}

	void Translation(const Vector3& v)
	{
		_41 = v.x;
		_42 = v.y;
		_43 = v.z;
	}

	void Translation(float x, float y, float z)
	{
		_41 = x;
		_42 = y;
		_43 = z;
	}

	void Sclae(const Vector3& v)
	{
		_11 = v.x;
		_22 = v.y;
		_33 = v.z;
	}

	void Sclae(float x, float y, float z)
	{
		_11 = x;
		_22 = y;
		_33 = z;
	}

	void XRotate(float fRadian)
	{
		float fCos = cos(fRadian);
		float fSin = sin(fRadian);
		_22 = fCos;		_23 = fSin;
		_32 = -fSin;	_33 = fCos;
	}

	void YRotate(float fRadian)
	{
		float fCos = cos(fRadian);
		float fSin = sin(fRadian);
		_11 = fCos;		_13 = -fSin;
		_31 = -fSin;	_33 = fCos;
	}

	void ZRotate(float fRadian)
	{
		float fCos = cos(fRadian);
		float fSin = sin(fRadian);
		_11 = fCos;		_12 = fSin;
		_21 = -fSin;	_22 = fCos;
	}
};

class Math
{

};