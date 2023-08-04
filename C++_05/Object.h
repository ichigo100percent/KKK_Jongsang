#pragma once
#include "Collision.h"

class Object
{
public:
	std::wstring m_csName;
	Point m_Position;
	Rect m_rt;
	virtual void	SetRect(Point& c, float w, float h);
	virtual void	Move(float fSecond) {};
	virtual void	SetTarget(Point& t) {};
};

class StaticObject :public Object
{
public:
	void			Move(float fSecond) {};
};

class DynamicObject :public Object
{
public:
	float m_fSpeed = 100.0f;
	Point m_Direction;
	Point m_Target;

public:
	void			SetTarget(Point& t);
	void			Move(float fSecond);

public:
	DynamicObject();
};