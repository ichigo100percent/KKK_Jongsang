#pragma once
#include "Component.h"

namespace J
{
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		virtual bool Init();
		virtual bool Update();
		virtual bool LateUpdate();
		virtual bool Render(HDC _hdc);

		void SetMass(float _mass) { m_Mass = _mass; }
		void AddForce(Vector2 _force) { m_Force = _force; }
		
	private:
		float m_Mass;
		float m_Friction;

		Vector2 m_Force;
		Vector2 m_Accelation;
		Vector2 m_Velocity;
		Vector2 m_Gravity;
	};
}
