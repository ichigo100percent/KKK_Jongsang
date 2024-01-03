#pragma once
#include "DXObject.h"


class GameObject : public Object
{
public:
	bool m_isDead = false;

public:
	Vec3			m_Postion;
	Vec3			m_Scale;
	Vec3			m_Rotation;
	Matrix			m_World;
	Matrix			m_View;
	Matrix			m_Projection;
	RECT			m_Rect;

public:
	virtual void SetRect(Vec2& _c, float _w, float _h);
	virtual void SetPos(Vec3 _p);
	virtual void SetScale(Vec3 _s);
	virtual void SetMatrix(Matrix* matWorld, Matrix* matView, Matrix* matProj);

public:
	virtual bool  Create(wstring _texName, wstring _shaderNmae);
	virtual void  Move(float _fSecond) {};
	virtual bool  Init();
	virtual bool  Frame();
	virtual bool  Render();
	virtual bool  Release();

public:
	GameObject();
	virtual ~GameObject() {}
};

