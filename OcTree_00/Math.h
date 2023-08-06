#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <math.h>

#define T_PI (3.141592f)
#define T_EPSILON ( 0.0001f)
#define RadianToDegree(radian) ( radian *( 180.0f / T_PI))
#define DegreeToRadian(degree) ( degree *( T_PI / 180.0f))
#define randstep(fmin, fmax) ((float)fmin+((float)fmax-(float)fmin)* rand() / RAND_MAX)

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
    float   operator | (Vector3 const& v);
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


