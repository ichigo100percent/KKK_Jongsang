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
		void SetGround(bool _ground) { m_bGround = _ground; }
		bool GetGround() { return m_bGround; }
		void SetVelocity(Vector2 _velocity) { m_Velocity = _velocity; }
		Vector2 GetVelocity() { return m_Velocity; }

		
	private:
		bool  m_bGround;
		float m_Mass;
		float m_Friction;

		Vector2 m_Force;
		Vector2 m_Accelation;
		Vector2 m_Velocity;
		Vector2 m_LimitedVelocity;
		Vector2 m_Gravity;
	};
}
