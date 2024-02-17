#pragma once
#include "Script.h"

namespace J
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			Attack,
		};

		PlayerScript();
		~PlayerScript();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;
		bool Release() override;

	private:
		void sitDown();
		void move();
	

	private:
		eState m_State;
		class Animator* m_Animator;
	};
}
