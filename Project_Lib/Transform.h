#pragma once
#include "Entity.h"
#include "Component.h"

namespace J
{
	using namespace math;

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


		//void SetPos(float _x, float _y)
		//{
		//	m_fX = _x;
		//	m_fY = _y;
		//}

		//float GetX() const { return m_fX; }
		//float GetY() const { return m_fY; }

		void SetPos(Vector2 _pos)
		{
			m_Position.x = _pos.x;
			m_Position.y = _pos.y;
		}

		Vector2 GetPos() { return m_Position; }

	private:
		Vector2		m_Position;
	};
}
