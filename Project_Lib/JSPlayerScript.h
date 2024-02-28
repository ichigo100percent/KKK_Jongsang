#pragma once
#include "Script.h"

namespace J
{
	class JSPlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Jump,
			Hit,
		};

		JSPlayerScript();
		~JSPlayerScript();

		bool Init() override;
		bool Update() override;
		bool LateUpdate() override;
		bool Render(HDC _hdc) override;

	private:
		void idle();
		void move();
		void jump();
		void hit();

	private:
		eState m_State;
		class Animator* m_Animator;
	};
}
