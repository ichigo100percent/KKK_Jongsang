#pragma once
#include "Collision.h"
const float g_fMapSize = 1000.0f;

class Object2D
{
public:
	std::wstring m_csName;
	Vector2		 m_Position;
	Rect		 m_tRT;

	virtual void SetRect(Vector2& c, float w, float h);
	virtual void Move(float fSecond) {};
	virtual void SetTarget(Vector2& t) {};
};

class StaticObject2D : public Object2D
{

};

class DynamicObject2D : public Object2D
{

};

class Object3D
{
public:
	int				m_iNodeIndex = -1;
	std::wstring    m_csName;
	Vector3			m_Position;
	Box				m_Box;
	virtual void SetBox(Vector3& c, float w, float h, float z);
	virtual void Move(float fSecond) {};
	virtual void SetTarget(Vector3& t) {};
};

class StaticObject3D : public Object3D
{
public:
	void Move(float fSecond) {};
};


class DynamicObject3D : public Object3D
{
public:
	float  m_fSpeed = 100.0f;
	Vector3 m_Direction;
	Vector3 m_Target;

public:
	void SetTarget(Vector3& t);
	void Move(float fSecond);

public:
	DynamicObject3D();
};