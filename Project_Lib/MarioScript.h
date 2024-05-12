#pragma once
#include "Script.h"

namespace J
{
	class MarioScript : public Script
	{
	public:
		MarioScript();
		~MarioScript();

		enum class eMarioType
		{
			Normal,
			Mushroom,
			Flower,
			Star,
		};

		enum class eMarioState
		{
			Idle,
			Move,
			Jump,
			Climbing,
			Sliding,
			Die,
		};

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		bool GetisDie() { return m_isDie; }
		bool GetisJump() { return m_isJumping; }
		void SetDie(bool _die) { m_isDie = _die; }
		void SetJump(bool _jump) { m_isJumping = _jump; }
		void Setinit();

	private:
		void idle();
		void move();
		void jump();
		void die();
		void attack();

	private:
		eMarioType	m_eType;
		eMarioState m_eState;
		bool		m_isJumping;
		bool		m_isDie;
		float		m_Time;
	};
}
