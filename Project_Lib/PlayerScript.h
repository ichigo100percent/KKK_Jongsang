#pragma once
#include "Script.h"

namespace J
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			Attack,
			GiveWater,

		};

		PlayerScript();
		~PlayerScript();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;
		bool Release() override;

		void AttackEffect();

	private:
		void idle();
		void move();
		void giveWater();

	private:
		eState m_State;
		class Animator* m_Animator;
	};
}
