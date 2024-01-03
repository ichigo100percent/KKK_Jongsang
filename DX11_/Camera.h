#pragma once
#include "Std.h"

class Camera
{
public:
	Matrix		m_matView;
	Matrix		m_matOrthoProjection;
	Vec3		m_vCameraPos;
	DWORD		m_dwWindowWidth;
	DWORD		m_dwWindowHeight;

public:
	bool init();
	bool Frame();
	bool Render();
	bool Release();

public:
	bool Create(Vec3 _pos, Vec2 _size);
};

