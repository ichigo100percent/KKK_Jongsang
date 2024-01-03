#pragma once
#include "Std.h"

namespace J
{
    class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();

	public:
		virtual bool Init();
		virtual bool Frame();
		virtual bool Render(HWND _hwnd);
		virtual bool Release();

	public:
		void SetPosition(float _x, float _y)
		{
			m_fX = _x;
			m_fY = _y;
		}

		float GetX() const { return m_fX; }
		float GetY() const { return m_fY; }

	private:
		float m_fX;
		float m_fY;
	};
}

