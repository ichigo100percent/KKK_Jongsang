#pragma once
#include "Collider.h"

namespace J
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		~BoxCollider2D();

		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);

	private:

	};
}
