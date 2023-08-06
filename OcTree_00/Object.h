#pragma once
#include "Collision.h"

class Object2D
{
public:
	std::wstring    m_csName;
	Vector2			m_Position;
	Rect			m_tRT;
	virtual void    SetRect(Vector2& c, float w, float h);
	virtual void	Move(float fSecond) {};
	virtual void	SetTarget(Vector2& t) {};
};
class TStaticObject2D : public Object2D
{
public:
	void			Move(float fSecond) {};
};
class TDynamicObject2D : public Object2D
{
public:
	float			m_fSpeed = 100.0f;
	Vector2			m_Direction;
	Vector2			m_Target;
public:
	void			SetTarget(Vector2& t);
	void			Move(float fSecond);
public:
	TDynamicObject2D();
};

class Object3D
{
public:
	int				m_iNodeIndex = -1;
	std::wstring    m_csName;
	Vector3			m_Position;
	Box			m_tBox;
	virtual void    SetBox(Vector3& c, float w, float h, float z);
	virtual void	Move(float fSecond) {};
	virtual void	SetTarget(Vector3& t) {};
};
class StaticObject3D : public Object3D
{
public:
	void			Move(float fSecond) {};
};
class DynamicObject3D : public Object3D
{
public:
	float			m_fSpeed = 100.0f; 
	Vector3			m_Direction;
	Vector3			m_Target;
public:
	void			SetTarget(Vector3& t);
	void			Move(float fSecond);
public:
	DynamicObject3D();
};


