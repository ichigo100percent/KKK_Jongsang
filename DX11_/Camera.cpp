#include "Camera.h"

bool Camera::Create(Vec3 _pos, Vec2 _size)
{
	m_vCameraPos = _pos;
	m_dwWindowWidth = _size.x;
	m_dwWindowHeight = _size.y;

	return true;
}

bool Camera::init()
{
	return true;
}

bool Camera::Frame()
{
	float fHalfWidth = m_dwWindowWidth / 2.0f;
	float fHalfHeight = m_dwWindowHeight / 2.0f;

	if (m_vCameraPos.x < -(g_fMapHalfSizeX)+fHalfWidth)
	{
		m_vCameraPos.x = -(g_fMapHalfSizeX)+fHalfWidth;
	}
	if (m_vCameraPos.y < -(g_fMapHalfSizeY)+fHalfHeight)
	{
		m_vCameraPos.y = -(g_fMapHalfSizeY)+fHalfHeight;
	}
	if (m_vCameraPos.x > (g_fMapHalfSizeX) -fHalfWidth)
	{
		m_vCameraPos.x = (g_fMapHalfSizeX)-fHalfWidth;
	}
	if (m_vCameraPos.y > (g_fMapHalfSizeY)-fHalfHeight)
	{
		m_vCameraPos.y = (g_fMapHalfSizeY)-fHalfHeight;
	}

	m_matView._41 = -m_vCameraPos.x;
	m_matView._42 = -m_vCameraPos.y;
	m_matView._43 = -m_vCameraPos.z;
	m_matOrthoProjection._11 = 2.0f / ((float)m_dwWindowWidth);
	m_matOrthoProjection._22 = 2.0f / ((float)m_dwWindowHeight);
	// ������ǥ ����(-10 ~ +10)  camera (0,0)
	// -10 ~ +10 camera (-5,0)�� ������ �ȴ�.
	// �� ��ǥ -> -5 ~ 15
	// ������ǥ -> 9 ~ 10 ~ 11
	// ������ǥ -> -1 ~ 0 ~ +1

	return true;
}

bool Camera::Render()
{
	return true;
}

bool Camera::Release()
{
	return true;
}

