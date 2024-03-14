#pragma once
#include "Collider.h"

namespace J
{
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		~CircleCollider2D();

		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);

	private:
		float m_Radius;
	};
}
