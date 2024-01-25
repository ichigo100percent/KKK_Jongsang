#pragma once
//#include "Entity.h"
#include "Component.h"

namespace J
{
	struct Pos
	{
		float m_fX;
		float m_fY;
	};

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;
		bool Release() override;


		void SetPos(float _x, float _y)
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
